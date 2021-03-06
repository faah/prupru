/*
 * I2C_HAL.h
 *
 *  Created on: 10/9/2015
 *      Author: Diego
 */

#ifndef I2C_HAL_H_
#define I2C_HAL_H_

//==============================================================================
//    S E N S I R I O N   AG,  Laubisruetistr. 50, CH-8712 Staefa, Switzerland
//==============================================================================
// Project   :  SHT2x Sample Code (V1.2)
// File      :  I2C_HAL.h
// Author    :  MST
// Controller:  NEC V850/SG3 (uPD70F3740)
// Compiler  :  IAR compiler for V850 (3.50A)
// Brief     :  I2C Hardware abstraction layer
//==============================================================================

//---------- Includes ----------------------------------------------------------
#include "System.h"
#include "typedefs.h"
#include <msp430.h>
#include <driverlib/MSP430FR57xx/driverlib.h>
#include <driverlib/MSP430FR57xx/inc/hw_memmap.h>

//---------- Defines -----------------------------------------------------------
//I2C ports
//The communication on SDA and SCL is done by switching pad direction
//For a low level on SCL or SDA, direction is set to output. For a high level on
//SCL or SDA, direction is set to input. (pull up resistor active)
/*#define SDA      PM3H_bit.no0 //SDA on I/O P38 defines direction (input=1/output=0)
#define SDA_CONF P3H_bit.no0  //SDA level on output direction
#define SCL      PM3H_bit.no1 //SCL on I/O P39 defines direction (input=1/output=0)
#define SCL_CONF P3H_bit.no1  //SCL level on output direction*/
#define SDA		GPIO_PIN4
#define SCL		GPIO_PIN5

// OUTPUT = LOW LEVEL
// INPUT = HIGH LEVEL
/*
 * Funciones por las que sustituir por las funciones SDA/SCL
 */
	/*
	GPIO_setAsOutputPin(GPIO_PORT_P1,SDA);// SDA as output
	GPIO_setAsInputPin(GPIO_PORT_P1,SDA);//SDA as input

	GPIO_setAsOutputPin(GPIO_PORT_P1,SCL);//SCL as output
	GPIO_setAsInputPin(GPIO_PORT_P1,SCL);//SCL as input

	GPIO_setOutputHighOnPin(GPIO_PORT_P1,SDA);//set SDA  HIGH
	GPIO_setOutputLowOnPin(GPIO_PORT_P1,SDA);//set SDA	LOW


	GPIO_setOutputHighOnPin(GPIO_PORT_P1,SCL);//set SCL HIGH
	GPIO_setOutputLowOnPin(GPIO_PORT_P1,SCL);//set SCL	LOW

 	 GPIO_getInputPinValue(GPIO_PORT_P1,SDA); //get SDA
 	 GPIO_getInputPinValue(GPIO_PORT_P1,SCL);	//get SCL
 */

//---------- Enumerations ------------------------------------------------------
//  I2C level
typedef enum{
  LOW                      = 0,
  HIGH                     = 1,
}etI2cLevel;

// I2C acknowledge
typedef enum{
  ACK                      = 0,
  NO_ACK                   = 1,
}etI2cAck;

//==============================================================================
void I2c_Init ();
//==============================================================================
//Initializes the ports for I2C interface

//==============================================================================
void I2c_StartCondition ();
//==============================================================================
// writes a start condition on I2C-bus
// input : -
// output: -
// return: -
// note  : timing (delay) may have to be changed for different microcontroller
//       _____
// SDA:       |_____
//       _______
// SCL :        |___

//==============================================================================
void I2c_StopCondition ();
//==============================================================================
// writes a stop condition on I2C-bus
// input : -
// output: -
// return: -
// note  : timing (delay) may have to be changed for different microcontroller
//              _____
// SDA:   _____|
//            _______
// SCL :  ___|

//===========================================================================
uint8_t I2c_WriteByte (uint8_t txByte);
//===========================================================================
// writes a byte to I2C-bus and checks acknowledge
// input:  txByte  transmit byte
// output: -
// return: error
// note: timing (delay) may have to be changed for different microcontroller

//===========================================================================
uint8_t I2c_ReadByte (etI2cAck ack);
//===========================================================================
// reads a byte on I2C-bus
// input:  rxByte  receive byte
// output: rxByte
// note: timing (delay) may have to be changed for different microcontroller

#endif /* I2C_HAL_H_ */
