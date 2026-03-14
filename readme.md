# Simple web for ESP32 in html

A simple web interface to download PDF files stored in a ESP32 controller

this proyect just works on your local network

_Dependencies_

<code> ESP32 library for arduino </code>

<code> tool -> ESP32FS</code>

_Usage_

Edit card.ino and change ssid AND password to your SSID and password to enable the ESP32 to connect to your LAN

Edit the files inside the PDF folder (and the references in index.html if change the names of the pdf files)

Upload the root (data) to the ESP32 storage -> <code>Tools > ESP32 Sketch to data upload</code>

Upload the code to your ESP32 using arduino
