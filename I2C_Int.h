/*
 * I2C_Int.h
 *
 *  Created on: Dec 11, 2020
 *      Author: Mohamed
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_
#include"STD_type.h"
#define TWBR *((volatile u8*) 0x20)
#define TWSR *((volatile u8*) 0x21)
#define TWAR *((volatile u8*) 0x22)
#define TWDR *((volatile u8*) 0x23)
#define TWCR *((volatile u8*) 0x56)
#define EEAR *((volatile u16*) 0x3E)
#define EEDR *((volatile u8*) 0x3D)
/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

//Status Codes
#define START_SENT_OK  	     0x08
#define REP_START_SENT_OK    0x10
#define SLAVE_ADD_AND_WR_ACK 0x18
#define SLAVE_ADD_AND_RD_ACK 0x40
#define WR_BYTE_ACK			 0x28
#define RD_BYTE_WITH_NACK    0x58

void I2c_Init_Master(void);
void I2c_Init_Slave(void);
void I2c_Start(void);
void I2c_Repeated_start(void);
void I2c_Send_slave_address_with_write_req(u8 slave_address);
void I2c_Send_slave_address_with_read_req(u8 slave_address);
void I2c_Write_byte(u8 byte);
u8   I2c_Read_byte(void);
void I2c_Stop(void);

/*
void I2c_Slave_check_slave_address_received_with_write_req(void);
void I2c_Slave_check_slave_address_received_with_read_req(void);
u8   I2c_Slave_read_byte(void);
void I2c_Slave_write_byte(u8 byte);
*/

#endif /* I2C_INT_H_ */
