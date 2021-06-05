/*
 * eeprom.c
 *
 * Created: 3/20/2021 10:59:48 AM
 *  Author: Andrew
 */


#include "STD.h"
#include "eeprom.h"
#include "I2c.h"


void EEpromInit(void)
{
	i2c_init_master();
}



void EEpromWriteByte(unsigned short address, unsigned char data)
{
	i2c_start();
	i2c_send_slave_address_with_write_req( 0b01010000 /*| ((address & 0x0700)>>8) */);
	i2c_write_byte((unsigned char)address);
	i2c_write_byte(data);
	i2c_stop();
	return;
}

void E2PROM_WriteMultyByteOn(uint8 address, uint8 *data)
{
	uint8 i=0 ;
	i2c_start();
	i2c_send_slave_address_with_write_req( 0b01010000 /*| ((address & 0x0700)>>8)*/ );
	i2c_write_byte((unsigned char)address);
	while(data[i] != '\0')
	{
		i2c_write_byte(data[i]);
		i++;
	}
	i2c_write_byte('#');
	i2c_stop();
}


unsigned char EEpromReadByte(unsigned short address)
{
	unsigned char data;
	i2c_start();
	i2c_send_slave_address_with_write_req( 0b01010000 /*| ((address & 0x07)>>8) */);
	i2c_write_byte((unsigned char)address);
	i2c_repeated_start();
	i2c_send_slave_address_with_read_req( 0b01010000 /*| ((address & 0x07)>>8)*/ );
	data = i2c_read_byte();
	i2c_stop();
	return data;
}

uint8* E2PROM_ReadMultyByteFrom(uint8 address)
{
	uint8* data;
	uint8 i =0;
	i2c_start();
	i2c_send_slave_address_with_write_req( 0b01010000 /*| ((address & 0x07)>>8) */);
	i2c_write_byte((unsigned char)address);

	i2c_repeated_start();
	i2c_send_slave_address_with_read_req( 0b01010000 /*| ((address & 0x07)>>8)*/ );


	data[i] = i2c_read_byte();


	i2c_stop();
	return data;
}


