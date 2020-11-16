//
// Hi-Tech Lite include file for DB038 board with 16F887:
// using an (external) RFM70 transciever
//
// Loosely based on the example application provided by HopeRF
//
//
// $Id: rfm73-config.h,v 1.1 2013/06/12 06:45:52 Staples Exp $
//
// (c) Wouter van Ooijen - wouter@voti.nl
//
// Copying and distribution of this file, with or without modification,
// are permitted in any medium without royalty provided the copyright
// notice and this notice are preserved.  This file is offered as-is,
// without any warranty.
//

#ifndef _DB038_RFM73_H_
#define _DB038_RFM73_H_

#include "stm32f1xx_hal.h"

//***************************************************************************//
//---------------------     defines for RFM73 START     ---------------------//
//***************************************************************************//
#define PIN_NSS                 GPIO_PIN_7      // from RFM73 side - connected to CSN
#define PORT_NSS                GPIOB           // NSS port
#define PIN_CE                  GPIO_PIN_8
#define PIN_IRQ                 GPIO_PIN_3
#define PIN_SCK                 GPIO_PIN_6
#define PIN_MOSI                GPIO_PIN_5
#define PIN_MISO                GPIO_PIN_4
#define PORT_SPI_IRQ_CE         GPIOB           // TODO: rename "PORT_SPI_IRQ_CE"; SPI port

//***************************************************************************//
//----------------------     defines for RFM73 END     ----------------------//
//***************************************************************************//

#define RFM73_SCK( x )   if(x) { \
                           HAL_GPIO_WritePin(PORT_SPI_IRQ_CE, PIN_SCK, GPIO_PIN_SET); \
                         } else { \
                           HAL_GPIO_WritePin(PORT_SPI_IRQ_CE, PIN_SCK, GPIO_PIN_RESET); \
                         }

#define RFM73_MOSI( x )  if(x) { \
                           HAL_GPIO_WritePin(PORT_SPI_IRQ_CE, PIN_MOSI, GPIO_PIN_SET); \
                         } else { \
                           HAL_GPIO_WritePin(PORT_SPI_IRQ_CE, PIN_MOSI, GPIO_PIN_RESET); \
                         }

#define RFM73_MISO       HAL_GPIO_ReadPin(PORT_SPI_IRQ_CE, PIN_MISO) == GPIO_PIN_RESET ? 0 : 1

#define RFM73_CSN( x )   if(x) { \
                           HAL_GPIO_WritePin(PORT_NSS, PIN_NSS, GPIO_PIN_SET); \
                         } else { \
                           HAL_GPIO_WritePin(PORT_NSS, PIN_NSS, GPIO_PIN_RESET); \
                         }

#define RFM73_CE( x )    if(x) { \
                           HAL_GPIO_WritePin(PORT_SPI_IRQ_CE, PIN_CE, GPIO_PIN_SET); \
                         } else { \
                           HAL_GPIO_WritePin(PORT_SPI_IRQ_CE, PIN_CE, GPIO_PIN_RESET); \
                         }

#define RFM73_WAIT_US( x ) Delay_us( x )
#define RFM73_WAIT_MS( x ) HAL_Delay( x )

#include "rfm73.h"

#endif
