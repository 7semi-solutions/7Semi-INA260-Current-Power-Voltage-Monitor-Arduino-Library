# 7Semi-INA260-Current-Power-Voltage-Monitor-Arduino-Library

This Arduino library provides support for the **7Semi INA260 Module**, a high-precision digital sensor for current, voltage, and power monitoring via I2C. It enables easy access to real-time power metrics, useful in energy monitoring, battery profiling, and embedded power control systems.

![Arduino](https://img.shields.io/badge/platform-arduino-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg)

---

## Hardware Required

- 7Semi INA260 Sensor Module  
- Arduino-compatible board  
- I2C connection (SDA, SCL)  

---

## Getting Started
 
  ### 1. Library Installation
 
      - Download or clone the repository.

      - Copy the files `7semi_INA260.cpp` and `7semi_INA260.h` into a folder named `7semi_INA260` under your Arduino `libraries/` directory.

      - Restart the Arduino IDE.

---

### 2. Wiring

| INA260 Pin | Arduino Pin |
|------------|-------------|
| SDA        | A4 (Uno)    |
| SCL        | A5 (Uno)    |
| VCC        | 3.3V or 5V  |
| GND        | GND         |

---

## Example Output

INA260 Initialized
Bus Voltage: 4.98 V
Current: 125.37 mA
Power: 0.62 W

Bus Voltage: 4.97 V
Current: 132.18 mA
Power: 0.66 W


---

## Applications

- Battery-powered device monitoring  
- Solar power systems  
- Motor driver feedback  
- IoT current logging  
- Overcurrent protection systems  

---

## License

This library is released under the MIT License.
