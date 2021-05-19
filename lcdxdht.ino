#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <dht.h>

#define dataPin 2

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

dht DHT;

void setup()
{

  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display

}

void loop() {
  lcd.clear();
  int readData = DHT.read11(dataPin);
  float t = DHT.temperature;
  float h = DHT.humidity;
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Temp.: "); // Prints string "Temp." on the LCD
  lcd.print(t); // Prints the temperature value from the sensor
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi.: ");
  lcd.print(h); // Prints the humidity value from the sensor
  lcd.print(" %");
  delay(2000);
}
