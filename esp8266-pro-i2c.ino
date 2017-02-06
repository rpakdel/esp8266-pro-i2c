#include <ESP8266WiFi.h>
#include <SSD1306AsciiWire.h>

// to program:
// 10Kohm between EN and 5V
// 10Kohm between IO15 and gnd
// ground IO0 and reset
// http://stackoverflow.com/q/41819985/7482007

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
