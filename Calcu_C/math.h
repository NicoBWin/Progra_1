/***************************************************************************/ /**
  @file     +math.h+
  @brief  +En este archivo se encuentran las operaciones 
				   matemáticas para la calculadora.+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef MATH_H 
#define MATH_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "const.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
//Tipos de errores//
#define N_ERR 0  //No hay error
#define E_OVF -1 //Error de overflow
#define E_DIV -2 //Error de dividir por cero
#define E_POT -3 //Error potencias no enteras.

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum OPERADORES
{
  OP_SUMA = '+',    // operador reconocido como suma. 
  OP_RESTA = '-',   // operador reconocido como resta.
  OP_MULTI = '*',   // operador reconocido como multiplicación.
  OP_DIV = '/',     // operador reconocido como división.
  OP_EXP = '^'      // operador reconocido como exponente.
};

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*
 * @brief suma: Suma los dos operandos que recibe 
 * @param num1 Es el primer numero que se ingreso
 * @param num2 Es el segundo numero que se ingreso
 * @param *p Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo double para mayor precision 
*/
double suma(double num1, double num2, int *p);

/*
 * @brief resta: Resta los dos operandos que recibe
 * @param num1 Es el primer numero que se ingreso
 * @param num2 Es el segundo numero que se ingreso
 * @param *p Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo double para mayor precision 
*/
double resta(double num1, double num2, int *p);

/*
 * @brief multi: Multiplica los dos operandos que recibe
 * @param num1 Es el primer numero que se ingreso
 * @param num2 Es el segundo numero que se ingreso
 * @param *p Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo double para mayor precision 
*/
double multi(double num1, double num2, int *p);

/*
 * @brief div: Divide los dos operandos que recibe 
 * @param num1 Es el primer numero que se ingreso
 * @param num2 Es el segundo numero que se ingreso
 * @param *p Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultao tipo double para mayor precision 
*/
double div(double num1, double num2, int *p);

/*
 * @brief pot: Raliza la operacon de exponente (num1^num2) 
 * @param num1 Es el primer numero que se ingreso
 * @param num2 Es el segundo numero que se ingreso
 * @param *p Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultao tipo double para mayor precision 
*/
double pot(double num1, double num2, int *p);

/*******************************************************************************
 ******************************************************************************/

#endif //  MATH_H