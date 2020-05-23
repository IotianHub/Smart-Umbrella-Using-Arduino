#include <LiquidCrystal.h>

#include <SimpleDHT.h>

//Declaring digital pin no 9 as the dht11 data pin

int pinDHT11 = 9;

SimpleDHT11 dht11;

//Declaring the lcd pins

const int a1 = 12, a2 = 11, a3 = 5, a4 = 4, a5 = 3, a6 = 2;

LiquidCrystal lcd(a1,a2,a3,a4,a5,a6);

void setup() {

//  serial monitor at 9600 

Serial.begin(9600);

//lcd to start

lcd.begin(16, 2);

}

void loop() {

//These serial codes are for getting readings on the serialmonitor as well as the LCD display, since they'll offer us a more detailed interface

Serial.println("=================================");

Serial.println("DHT11 readings...");

byte temperature = 0;

byte humidity = 0;

int err = SimpleDHTErrSuccess;

//This bit will tell our Arduino what to do if there is some sort of an error at getting readings from our sensor

if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {

Serial.print("No reading , err="); Serial.println(err);delay(1000);

return;

}

Serial.print("Readings: ");

Serial.print((int)temperature); Serial.print(" Celcius, ");

Serial.print((int)humidity); Serial.println(" humidity%");

//Telling our lcd to refresh itself every 0.75 seconds

lcd.clear();

//Choosing the first line and row

lcd.setCursor(0,0);

//Typing Temp: to the first line starting from the first row

lcd.print("Temp: ");

//Typing the temperature readings after "Temp: "

lcd.print((int)temperature);

//Choosing the second line and first row

lcd.setCursor(0,1);

//Typing Humidity(%): to the second line starting from the first row

lcd.print("Humidity(%): ");

//Typing the humidity readings after "Humidity(%): "

lcd.print((int)humidity);

delay(1000);

}
