/***************************************************************************//**
  @file     +hardware.h+
  @brief    +Header del módulo hardware, para controlar GPIO de la Raspi+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef _RASPI_H_
#define _RASPI_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "const.h"
#include "PORTS.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief init_raspi: Hace export de todos los puertos que usamos
 * @return Devuelve si hay un error o no
*/
int init_raspi();

/**
 * @brief act_leds: Enciende o apaga los leds de la raspi
 * @param port El puerto donde se encuentran los LED's
 * @return Devuelve si hay un error o no
*/
int act_leds(char port);


/**
 * @brief fin_raspi: Hace unexport de todos los puertos
*/
void fin_raspi();

/*******************************************************************************
 ******************************************************************************/

#endif // _RASPI_H_
