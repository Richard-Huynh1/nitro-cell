#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

const char* ssid = "Nitro Cell";
const char* password = "12345678";

AsyncWebServer server(80);

const int ledPin = 2;

void setup() {

  Serial.begin(115200);
  delay(2000);

  pinMode(ledPin, OUTPUT);

  Serial.println("Mounting LittleFS...");

  // format if filesystem not present
  if (!LittleFS.begin(true, "/littlefs", 10, "littlefs")) {
    Serial.println("LittleFS Mount Failed");
    return;
  }

  Serial.println("LittleFS Mounted!");

  // Start AP
  WiFi.softAP(ssid, password);

  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // LED endpoints
  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, HIGH);
    request->send(200, "text/plain", "LED ON");
  });

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, LOW);
    request->send(200, "text/plain", "LED OFF");
  });

  // serve files from filesystem
  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

  server.begin();

  Serial.println("Server started");
}

void loop() {}