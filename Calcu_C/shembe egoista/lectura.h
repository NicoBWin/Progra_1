/***************************************************************************//**
  @file     +lectura.h+
  @brief    +lectura de la calculadora+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_ 

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "const.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief lectura de cuenta
 * @param *str Puntero a donde se encuentran los operadores
 * @param *pn1 Puntero donde se debe colocar el primer numero
 * @param *pn2 Puntero donde se debe colocar el segundo numero
 * @param *pop Puntero donde se debe colocar el operador
 * @return void
*/
void lect(char*str, float*pn1, float*pn2, char*pop);


/*******************************************************************************
 ******************************************************************************/

#endif 
