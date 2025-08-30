#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "*******";      // Đặt tên WiFi
const char* password = "*******";  // Mật khẩu WiFi

WebServer server(80);  // Dùng HTTP port 80
const int LED_PIN = 2; // LED_BUILTIN (GPIO2)

void handleRoot() {
  server.send(200, "text/plain", "ESP32 WebServer is running!");
}

void handleLedOn() {
  digitalWrite(LED_PIN, HIGH);
  
  server.send(200, "text/plain", "LED ON");
}

void handleLedOff() {
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/plain", "LED OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  // Kết nối WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Cấu hình các URL điều khiển
  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);

  // Khởi động server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
