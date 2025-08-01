/*!
 * @file 7semi_INA260.h
 * @brief INA260 precision current, voltage, and power monitor library
 * @author 7semi
 * @license MIT
 */

#ifndef _7SEMI_INA260_H_
#define _7SEMI_INA260_H_

#include <Arduino.h>
#include <Wire.h>

// Default I2C address
#define I2C_ADD             0x40

#define MFG_ID_REG          0xFE
#define DIE_ID_REG          0xFF
#define MFG_ID              0x5449  // Texas Instruments
#define DIE_ID              0x2270  // INA260 Die ID
// Register addresses
#define CONFG_REG           0x00
#define CURRENT_REG         0x01
#define BUS_VOLTAGE_REG     0x02
#define POWER_REG           0x03
#define ENABLE_REG          0x06
#define ALERT_LIMIT_REG     0x07


class INA260_7semi {
public:
  // Initialize sensor with I2C instance and address
  bool begin(uint8_t address = 0x40);

  // Read current (1.25 mA/bit)
  int16_t readCurrent();

  // Read bus voltage (1.25 mV/bit)
  int16_t readBusVoltage();

  // Read power (10 mW/bit)
  int16_t readPower();

  // Read 8-bit register
  uint8_t readReg(uint8_t reg);

  // Read 16-bit register
  uint16_t read2Reg(uint8_t reg);

  // Write 8-bit register
  void writeReg(uint8_t reg, uint8_t value);

private:
  TwoWire* _wire;
  uint8_t _address;
};

#endif
