#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D3
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
WiFiClient client;
LiquidCrystal_I2C lcd(0x27, 20, 4);

String apiKey = "LD02BM9BGC3ZRQKC";
const char* ssid = "TeoAndroid";
const char* password = "HMHDemo1";
const char* server = "api.thingspeak.com";
void setup()
{

  Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Connecting with ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  DS18B20.begin();

  
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  
  while (WiFi.status() != WL_CONNECTED) {
  lcd.clear();
  lcd.print("WiFi disconnected!");
  delay(500);
  Serial.print(".");
 }
 
 Serial.println("");
 Serial.println("WiFi Connected");
 
 lcd.clear();
 lcd.setCursor(0, 0);      
 lcd.print(" WiFi connected!");
}

void loop()
{
   
   float temp;
   DS18B20.requestTemperatures();
   temp = DS18B20.getTempCByIndex(0);
   
   lcd.setCursor(0, 1);
   lcd.print(String("Temp: ") + temp + String(" C"));
   lcd.setCursor(0, 0);      
   lcd.print(" WiFi connected!");
   
   if (client.connect(server, 80)) {
      Serial.println("connected");
      lcd.setCursor(0, 0);      
      lcd.print("*");
      String postStr = apiKey;
      postStr +="&field1=";
      postStr += String(temp);
      postStr += "\r\n\r\n";
      Serial.println(postStr);
      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

    }
    client.stop();
    
    delay(16000);
}
