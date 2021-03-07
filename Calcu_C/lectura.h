/***************************************************************************/ /**
  @file     +lectura.h+
  @brief    +Contiene las funciones necesarias para realizar la lectura de las 
            operaciones ingresadas por el usuario.+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef LECTURA_H
#define LECTURA_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "const.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
// Constantes de errores
#define CARACTINV "El número ingresado contiene carecteres inválidos. Vuelva a ingresar toda la operación:"
#define COMAREPETIDA "No puede ingresar una coma dos veces. Vuelva a ingresar toda la operación:"
#define MALOPERADOR "El operador ingresado, no es valido. Por favor vuelva a ingresar toda la operación:"
#define OUTOFRANGE "El numero ingresado excede la cant de caracteres maxima."

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief lectura de cuenta
 * @param *str Puntero a donde se encuentran los operadores
 * @param *pn1 Puntero a donde se debe colocar el primer numero
 * @param *pn2 Puntero a donde se debe colocar el segundo numero
 * @param *pop Puntero a donde se debe colocar el operador
 * @return void
*/
void lect(char *str, double *pn1, double *pn2, char *pop);

/*******************************************************************************
 ******************************************************************************/

#endif // LECTURA_H