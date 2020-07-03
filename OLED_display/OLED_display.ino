/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>



#define DHTTYPE    DHT11 
#define DHTPIN 13  
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  
  dht.begin();

   float t = dht.readTemperature();
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  
}

void loop() {
  
  oledDisplay(temperature(),123.4);
  delay(2000);
  display.clearDisplay();
}

void oledDisplay(float temperature,float ph){
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.print("Temp:");
  display.println(temperature);
  display.display(); 
}

float temperature(){
   float t = dht.readTemperature();
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
   return t;
}
