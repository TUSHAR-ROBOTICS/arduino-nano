#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);

  if (!ina219.begin()) {
    Serial.println("INA219 not found!");
    while (1);
  }

  Serial.println("INA219 Ready");
}

void loop() {
  float shuntVoltage = ina219.getShuntVoltage_mV();
  float busVoltage   = ina219.getBusVoltage_V();
  float current_mA   = ina219.getCurrent_mA();
  float power_mW     = ina219.getPower_mW();

  Serial.print("Bus Voltage: ");
  Serial.print(busVoltage);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current_mA);
  Serial.println(" mA");

  Serial.print("Power: ");
  Serial.print(power_mW);
  Serial.println(" mW");

  Serial.print("Shunt Voltage: ");
  Serial.print(shuntVoltage);
  Serial.println(" mV");

  Serial.println("----------------------");

  delay(1000);
}