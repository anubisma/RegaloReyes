#include <WiFi.h>
#include <SPIFFS.h>
#include <WebServer.h>

// --- CONFIGURACIÓN WIFI ---
const char* ssid = "MI_SSID";
const char* password = "contraseña";

// --- SERVIDOR WEB ---
WebServer server(80);

// --- FUNCIONES PARA SERVIR ARCHIVOS ---
void handleRoot() {
  File file = SPIFFS.open("/index.html", "r");
  if (!file) {
    server.send(404, "text/plain", "Archivo index.html no encontrado");
    return;
  }
  server.streamFile(file, "text/html");
  file.close();
}

void handlePDF() {
  String path = server.uri(); // ejemplo: /PDF/Melchor.pdf
  File file = SPIFFS.open(path, "r");
  if (!file) {
    server.send(404, "text/plain", "Archivo PDF no encontrado");
    return;
  }
  server.streamFile(file, "application/pdf");
  file.close();
}

// --- SETUP ---
void setup() {
  Serial.begin(115200);
  delay(1000);

  // --- CONEXIÓN WIFI ---
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado: " + WiFi.localIP().toString());

  // --- INICIALIZAR SPIFFS (formatea si está corrupto) ---
  if (!SPIFFS.begin(true)) { // true = formatea automáticamente
    Serial.println("Error montando SPIFFS");
    return;
  }
  Serial.println("SPIFFS montado correctamente");

  // --- RUTAS DEL SERVIDOR ---
  server.on("/", handleRoot);

  // Manejo de PDFs automáticamente
  server.onNotFound([]() {
    String path = server.uri();
    if (path.startsWith("/PDF/")) handlePDF();
    else server.send(404, "text/plain", "Ruta no encontrada");
  });

  // --- INICIAR SERVIDOR ---
  server.begin();
  Serial.println("Servidor iniciado");
}

// --- LOOP PRINCIPAL ---
void loop() {
  server.handleClient();
}
