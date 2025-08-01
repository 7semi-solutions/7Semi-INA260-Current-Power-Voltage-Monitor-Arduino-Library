#include <7semi_INA260.h>

// Create INA260 object
INA260_7semi ina260;

void setup() {
  Serial.begin(9600);
  // Initialize INA260 with default I2C address 0x40
  if (ina260.begin()) {
    Serial.println("INA260 Power Monitor Initialized");
  } else {
    Serial.println("INA260 Not Detected");
    while (1);  // Halt if sensor not found
  }
}

void loop() {
  // Read raw values
  int16_t current_raw = ina260.readCurrent();
  int16_t voltage_raw = ina260.readBusVoltage();
  int16_t power_raw   = ina260.readPower();

  // Convert based on INA260 datasheet resolution
  float current_mA = current_raw * 1.25;     // Current in mA
  float voltage_mV = voltage_raw * 1.25;     // Voltage in mV
  float power_mW   = power_raw * 10.0;       // Power in mW

  // Print converted values
  Serial.print("Voltage: ");
  Serial.print(voltage_mV / 1000.0);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current_mA / 1000.0);
  Serial.println(" A");

  Serial.print("Power: ");
  Serial.print(power_mW / 1000.0);
  Serial.println(" W");

  Serial.println("-------------------------");
  delay(1000);
}
