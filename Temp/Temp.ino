// By Druhi Chakraborty, cleaned and corrected

#include <DHT.h>                  // Include the DHT library
#include <LiquidCrystal_I2C.h>     // Include the LCD library

#define DHTPIN 4                  // DHT sensor connected to digital pin 4
#define DHTTYPE DHT11              // Define sensor type (DHT11, DHT22, or DHT21)

// Create DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

// Create LCD object (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();      // Initialize the DHT sensor
  lcd.init();       // Initialize the LCD
  lcd.backlight();  // Turn on the LCD backlight
}

void loop() {
  lcd.clear();
  
  lcd.setCursor(0, 0);  // Set cursor to first row, first column
  lcd.print("Humidity=");
  lcd.print(dht.readHumidity()); // Print humidity
  lcd.print("%");
  
  lcd.setCursor(0, 1);  // Set cursor to second row, first column
  lcd.print("Temp=");
  lcd.print(dht.readTemperature()); // Print temperature
  lcd.print((char)223); // Print degree symbol
  lcd.print("C");

  delay(2000); // Wait 2 seconds before updating again
}
