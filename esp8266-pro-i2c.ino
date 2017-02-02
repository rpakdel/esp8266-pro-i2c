#include <ESP8266WiFi.h>
#include <SSD1306AsciiWire.h>

#include "myssid.h"
#include "esp8266-pro-pins.h"

SSD1306AsciiWire oled;
WiFiServer server(80);

void initDisplay()
{
    
    Serial.println(F("Init OLED"));
    Wire.begin(GPIO4, GPIO5);
    oled.begin(&Adafruit128x64, 0x3C);
    oled.setFont(Adafruit5x7);
    oled.clear();
    oled.setCursor(0, 0);
}

void initWiFi()
{
    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(MYSSID);

    WiFi.begin(MYSSID, MYPASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    // Start the server
    server.begin();
    Serial.println("Server started");

    // Print the IP address
    Serial.println(WiFi.localIP());
    oled.println(WiFi.localIP());
}

void setup()
{
    Serial.begin(9600);
    initDisplay();
    initWiFi();
}

void loop()
{
}
