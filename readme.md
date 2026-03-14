# Simple HTML web interface for ESP32

A simple web interface to download PDF files stored on an ESP32.

This project only works on your local network.

**Dependencies**

- ESP32 Arduino core
- ESP32FS (Tools)

**Usage**

1. Open `card.ino` and set `ssid` and `password` to your Wi-Fi credentials so the ESP32 can connect to your LAN.
2. Add or edit PDF files inside the `data/PDF` folder. If you rename files, update the references in `data/index.html`.
3. Upload the sketch to your ESP32 from the Arduino IDE.
4. Upload the `data` folder to the ESP32 filesystem using "Tools > ESP32 Sketch Data Upload".
