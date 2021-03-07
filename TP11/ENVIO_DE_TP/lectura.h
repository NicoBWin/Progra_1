/***************************************************************************//**
  @file     +lectura.h+
  @brief    +header de lectura.c donde se encuentra constantes importantes+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef LECTURA_H_
#define LECTURA_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdlib.h>
#include "const.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define CLEAN_BUFFER()  while (getchar() != '\n') continue  // Macro para limpiar buffer.
#define S	's'	//Definiciones arbitrarias de constantes para la salida
#define C	'c'	//de la funcion
#define Q	'q'
#define T	't'
#define B 'b'

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief lectura: El usuario ingresa un dato y se transforma a int 
 * @return Devuelve un int dependiendo de lo que se ingreso para ser
			analizado luego en el main
*/
int lectura(void);

/*******************************************************************************
 ******************************************************************************/

#endif // LECTURA_H_
