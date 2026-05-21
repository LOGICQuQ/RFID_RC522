#include "mbed.h"
#include "MFRC522.h"

using namespace std::chrono_literals;

// Update these pins for your target board.
#define RFID_MOSI D11
#define RFID_MISO D12
#define RFID_SCK  D13
#define RFID_CS   D10
#define RFID_RST  D9

MFRC522 rfid(RFID_MOSI, RFID_MISO, RFID_SCK, RFID_CS, RFID_RST);

int main()
{
  printf("MFRC522 Mbed OS 6 example\r\n");
  rfid.PCD_Init();

  while (true)
  {
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    {
      ThisThread::sleep_for(200ms);
      continue;
    }

    printf("UID:");
    for (uint8_t i = 0; i < rfid.uid.size; i++)
    {
      printf(" %02X", rfid.uid.uidByte[i]);
    }
    printf("\r\n");

    uint8_t piccType = rfid.PICC_GetType(rfid.uid.sak);
    printf("Type: %s\r\n", rfid.PICC_GetTypeName(piccType));

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    ThisThread::sleep_for(500ms);
  }
}
