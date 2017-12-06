//lcd display 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
 
//initialize dht sensor
#define DHTTYPE DHT11
#define DHTPIN D0
DHT dht(DHTPIN, DHTTYPE);
//intialize light
#define lightpin D3

//declare variables
float hum;
float temp;
float light;

//set lcd address
LiquidCrystal_I2C lcd(0x3F,16,2);


void setup()
{
  //begin serial
  Serial.begin(115200);
  delay(10);

  //initialize
  lcd.init();                      
  lcd.backlight();
  
  //print
  lcd.setCursor(4,0);
  lcd.print("HW: A8");
  delay(500);
}


void loop()
{
  //read & store data
  light = analogRead(lightpin);
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  float temp = dht.readTemperature(true);

  //print to serial
  Serial.println("humidity: ");
  Serial.println(hum);
  Serial.println(" %, temp: ");
  Serial.println(temp);
  Serial.println(" %, light: ");
  Serial.println(light);
  delay(1000);
  
  //print to LCD
  lcd.setCursor(4,0);
  lcd.print("light:");
  lcd.print(light);
  lcd.setCursor(0,1);
  lcd.print("hum:");
  lcd.print(hum);
  lcd.setCursor(8,1);
  lcd.print("tmp:");
  lcd.print(temp);
}
