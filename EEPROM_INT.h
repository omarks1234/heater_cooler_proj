/*
 * EEPROM_INT.h
 *
 *  Created on: Oct 29, 2021
 *      Author: lenovo
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_
void EEPROM_INIT (void);
void EEPROM_Write_data(u8 address , u8 data);
u8 EEPROM_readData (u8 address);
void EEPROM_Write_data_all(u8 address , u8 data);
u8 EEPROM_readData_all (u8 address);
#endif /* EEPROM_INT_H_ */
