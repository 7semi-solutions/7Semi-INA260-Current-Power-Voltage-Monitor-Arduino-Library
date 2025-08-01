/*!
 * @file 7semi_INA260.cpp
 * @brief INA260 precision current, voltage, and power monitor library
 * @author 7semi
 * @license MIT
 * 
 * Based on the official Texas Instruments INA260 datasheet.
 */

#include "7semi_INA260.h"

// Initialize I2C and verify manufacturer/die ID
bool INA260_7semi::begin(uint8_t address) {
  _wire = &Wire;
  _wire->begin();
  _address = address;

  uint16_t mfg_id = read2Reg(MFG_ID_REG);  // Expected: 0x5449
  uint16_t die_id = read2Reg(DIE_ID_REG);  // Expected: 0x2270

  return (mfg_id == MFG_ID && die_id == DIE_ID);
}

// Read signed current (1.25 mA/bit)
int16_t INA260_7semi::readCurrent() {
  return (int16_t)read2Reg(CURRENT_REG);
}

// Read signed bus voltage (1.25 mV/bit)
int16_t INA260_7semi::readBusVoltage() {
  return (int16_t)read2Reg(BUS_VOLTAGE_REG);
}

// Read signed power (10 mW/bit)
int16_t INA260_7semi::readPower() {
  return (int16_t)read2Reg(POWER_REG);
}

// Read one byte from register
uint8_t INA260_7semi::readReg(uint8_t reg) {
  _wire->beginTransmission(_address);
  _wire->write(reg);
  _wire->endTransmission();

  _wire->requestFrom(_address, (uint8_t)1);
  return _wire->available() ? _wire->read() : 0;
}

// Read two bytes from register (MSB first)
uint16_t INA260_7semi::read2Reg(uint8_t reg) {
  _wire->beginTransmission(_address);
  _wire->write(reg);
  _wire->endTransmission(false);  // Restart for read

  _wire->requestFrom(_address, (uint8_t)2);
  uint16_t value = ((uint16_t)_wire->read() << 8) | _wire->read();
  return value;
}

// Write one byte to register
void INA260_7semi::writeReg(uint8_t reg, uint8_t value) {
  _wire->beginTransmission(_address);
  _wire->write(reg);
  _wire->write(value);
  _wire->endTransmission();
}
