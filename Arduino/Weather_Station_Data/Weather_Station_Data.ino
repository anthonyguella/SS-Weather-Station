#include <MAX17043.h>

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 6
#define BME_MISO 5
#define BME_MOSI 4
#define BME_CS 3

Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);
MAX17043 lipo;

float Temperature;
float Humidity;
float Pressure;
float Voltage;
float SoC;


void setup() {
  Serial.begin(9600);
  bme.begin();
  lipo.reset();
  lipo.quickStart();

  
}

void loop() {
    Temperature = ((bme.readTemperature() * 9 / 5) + 32);
    Serial.print("Temperature = "); 
    Serial.print(Temperature);
    Serial.print(" *F" );
    Serial.println();

    Pressure = (bme.readPressure() / 100.0F);
    Serial.print("Pressure = ");
    Serial.print(Pressure); 
    Serial.print(" hPa");
    Serial.println();

    Humidity = bme.readHumidity();
    Serial.print("Humidity = ");
    Serial.print(Humidity);
    Serial.print(" %");
    Serial.println();

    Voltage = lipo.getVCell();
    Serial.print("Voltage = ");
    Serial.print(Voltage);
    Serial.print(" V");
    Serial.println();

    SoC = lipo.getSoC();
    Serial.print("SoC = ");
    Serial.print(SoC);
    Serial.print(" %");
    Serial.println();
    
    delay(2000);
}
