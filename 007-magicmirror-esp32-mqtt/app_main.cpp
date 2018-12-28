#include <WiFi.h>
#include <PubSubClient.h>
#include "SSD1306.h"
#include "DHT.h"

#define PORT_LED 16

const char* SSID = "****";
const char* PASS = "****";
const char* SERVER = "***.***.***.***";
const int PORT = 1883;

SSD1306 display(0x3c, 5, 4);

DHT dht(22, DHT11);

WiFiClient espClient;
PubSubClient client(espClient);

void initializeLCD() {
    display.init();
    display.setFont(ArialMT_Plain_24);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
}

void updateLCD(String str) {
    display.clear();
    display.drawString(0, 0, str);
    display.display();
}

void callback(char* topic, byte* payload, unsigned int length) {
    char str[32];

    memset(str, 0x00, sizeof(str));

    Serial.println(sizeof(str));
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");

    for (int i=0;i<length;i++) {
        Serial.print((char)payload[i]);
        str[i] = (char)payload[i];
    }
    Serial.println();

    updateLCD(String(str));
}

void setup()
{
    pinMode(PORT_LED, OUTPUT);
    Serial.begin(115200);

    initializeLCD();

    WiFi.begin(SSID, PASS);
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to AP...");
    }

    Serial.println("Connected to AP!!");

    client.setServer(SERVER, PORT);
    client.setCallback(callback);

    while (!client.connected()) {
        Serial.println("Connecting to MQTT...");

        if (client.connect("ESP32Client")) {
            Serial.println("Connected!!");
        } else {
            Serial.print("Failure on connect (");
            Serial.print(client.state());
            Serial.println(")");
            delay(2000);
        }
    }
 }

void loop() {
    char buffer[16];
    float humid = dht.readHumidity();
    float tempC = dht.readTemperature(); // Celsius
  
    // check fail
    if (isnan(humid) || isnan(tempC))
    {
        Serial.println("fail to read DHT.");
        updateLCD("Fail to read!");
        delay(1000);
        return;
    }
    
    memset(buffer, 0x00, sizeof(buffer));
    sprintf(buffer, "H:%2.1f T:%2.1f", humid, tempC);

    client.publish("ttgo/dht", buffer);

    updateLCD(buffer);

    //blink
    digitalWrite(PORT_LED, LOW);
    delay(1000);
    digitalWrite(PORT_LED, HIGH);
    delay(1000);

    client.loop();
}
