/*

* EEPROM_INIT.C
 *
 *  Created on: Oct 29, 2021
 *      Author: lenovo
 */

#include"I2C_Int.h"
#include"STD_type.h"
#include"EEPROM_INT.h"
// WRITE IN EXTERNAL EEPROM
void EEPROM_INIT (void)
{
	 I2c_Init_Master();

}
void EEPROM_Write_data(u8 address , u8 data)
{
	 I2c_Start();
	  I2c_Send_slave_address_with_write_req(0b10100000);
	  I2c_Write_byte(address);
	  I2c_Write_byte(data);
	  I2c_Stop();
}
u8 EEPROM_readData (u8 address)
{
	 I2c_Start();
	 I2c_Send_slave_address_with_write_req(0b10100000);
	  I2c_Write_byte(address); // slave knows first byte sent for address inside block

	  // instead of repeated start
	   I2c_Stop();
	   I2c_Start();
	    I2c_Send_slave_address_with_read_req(0b10100000);
	      u8 z =I2c_Read_byte();
	      I2c_Stop();
	      return z ;
}
// Write in interNal EEPROM
void EEPROM_Write_data_all(u8 address , u8 data)
{
	 I2c_Start();
	  I2c_Send_slave_address_with_write_req(0b10100000);
	  EEAR = 0 ; // cause first address isn t defined
	  EEAR = address;
	  I2c_Write_byte(EEAR);
	  I2c_Write_byte(data);
	  I2c_Stop();
}
u8 EEPROM_readData_all (u8 address)
{
    // write first cause save last address wanted to read from
    // for data more than one byte
	 I2c_Start();
	 I2c_Send_slave_address_with_write_req(0b10100000);
	 EEAR = 0 ;
	 EEAR = address;
	  I2c_Write_byte(EEAR); // slave knows first byte sent for address inside block

	  // instead of repeated start
	   I2c_Stop();
	   I2c_Start();
	    I2c_Send_slave_address_with_read_req(0b10100000);
	      u8 z =I2c_Read_byte();
	      I2c_Stop();
	      return z ;
}




