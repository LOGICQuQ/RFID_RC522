# RFID RC522 (Mbed OS 6)

This library provides an MFRC522 RFID driver for Mbed OS targets using SPI.

## Mbed OS 6 compatibility

- Uses `#include "mbed.h"` APIs.
- Uses `ThisThread::sleep_for(...)` with chrono durations.
- Keeps SPI configured with `format(8, 0)` and `frequency(8000000)`.
- Uses `DigitalOut` chip-select and reset pins.
- Adds SPI `lock()/unlock()` around register transactions for thread-safe bus access.

No driver API changes were required for Mbed OS 6.

## Wiring (RC522 -> Mbed target)

- `SDA/SS` -> SPI chip-select pin used in `MFRC522` constructor (`cs`)
- `SCK` -> SPI SCLK (`sclk`)
- `MOSI` -> SPI MOSI (`mosi`)
- `MISO` -> SPI MISO (`miso`)
- `RST` -> Reset pin used in `MFRC522` constructor (`reset`)
- `3.3V` -> `3V3`
- `GND` -> `GND`

> RC522 is a 3.3V device. Do not power it from 5V on typical Mbed boards.

## Mbed CLI 2 / mbed-tools build steps

Example below creates a simple app that uses this driver:

```bash
python -m venv .venv
source .venv/bin/activate
pip install mbed-tools

mbed-tools new .
mbed-tools deploy

# Copy MFRC522.h, MFRC522.cpp and examples/mbed-os6/main.cpp into your app
# then build (replace target/toolchain as needed):
mbed-tools compile -m NUCLEO_F401RE -t GCC_ARM
```

See `examples/mbed-os6/main.cpp` for a minimal UID-read loop.
