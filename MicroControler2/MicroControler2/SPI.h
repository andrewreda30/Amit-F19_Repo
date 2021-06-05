/*
 * SPI.h
 *
 * Created: 4/24/2021 11:51:38 AM
 *  Author: Andrew
 */ 


#ifndef SPI_H_
#define SPI_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);

void SPI_Master_InitTrans(void);
void SPI_Master_TermTrans(void);

uint8 SPI_TranSiver(uint8 data);




#endif /* SPI_H_ */