/*
 * I2C_Prog.c
 *
 *  Created on: Dec 11, 2020
 *      Author: Mohamed
 */
#include "STD_type.h"
#include "Utilites.h"
#include "I2C_Int.h"

void I2c_Init_Master(void)
{
	TWBR=0x03;        //SCL_frequency = 400000 HZ, F_CPU = 16M   SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
	//CLR_BIT(TWSR, 0); //setting prescaller to 1
	//CLR_BIT(TWSR, 1); //setting prescaller to 1
	SET_BIT(TWCR, TWEN); //Enable I2C
}
void I2c_Init_Slave(void)
{
	TWAR=0x06;            //provide slave address, my address will be 0x06
	SET_BIT(TWCR, TWEN);  //Enable I2C
}
void I2c_Start(void)
{
	TWCR = (1<< TWINT) | (1<< TWSTA) | (1<< TWEN);//Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	while(GET_BIT(TWCR, TWINT)==0);	// Wait till start condition is transmitted
	while ((TWSR & 0xF8)!=START_SENT_OK);//Check value of TWI Status Register equal to start
}
void I2c_Repeated_start(void)
{
	TWCR = (1<< TWINT) | (1<< TWSTA) | (1<< TWEN);//Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	while(GET_BIT(TWCR, TWINT)==0);	// Wait till start condition is transmitted
	while ((TWSR & 0xF8)!=REP_START_SENT_OK);//Check value of TWI Status Register equal to start
}
void I2c_Send_slave_address_with_write_req(u8 slave_address)
{
	TWDR = slave_address;                    //Address and write instruction
	TWCR = (1<<TWINT) | (1<<TWEN);//Clear TWI interrupt flag, Enable TWI
	while(GET_BIT(TWCR, TWINT)==0);	//Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK);  // Check for the acknowledgment
}
void I2c_Send_slave_address_with_read_req(u8 slave_address)
{
	TWDR = slave_address;       // Address
	SET_BIT(TWDR, 0);				// read instruction
	TWCR = (1<<TWINT) | (1<<TWEN);//Clear TWI interrupt flag, Enable TWI
	while(GET_BIT(TWCR, TWINT)==0);	//Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK);   // Check for the acknowledgment
}
void I2c_Write_byte(u8 byte)
{
	TWDR = byte;                            // put data in TWDR
	TWCR = (1<<TWINT) | (1<<TWEN);//Clear TWI interrupt flag, Enable TWI
	while(GET_BIT(TWCR, TWINT)==0);	//Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != WR_BYTE_ACK);    // Check for the acknowledgment
}
u8 I2c_Read_byte(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);//Clear TWI interrupt flag, Enable TWI
	while(GET_BIT(TWCR, TWINT)==0);	//Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != RD_BYTE_WITH_NACK);   // Check for the acknowledgment
	return TWDR;
}
void I2c_Stop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);//Clear TWI interrupt flag,Put stop condition, Enable TWI
}
