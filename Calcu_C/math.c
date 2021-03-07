/*******************************************************************************
  @file     +math.c+
  @brief    +Archivo con las funciones matemáticas+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>

#include "math.h"

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
double suma(double num1, double num2, int *p) //Realiza
{
	double result;
	*p = N_ERR;
	result = num1 + num2;
	if (num1 > 0 && num2 > 0 && result < 0) //Busca si hay error de overflow
	{
		*p = E_OVF;
	}
	if (num1 < 0 && num2 < 0 && result > 0) //Busca si hay error de overflow
	{
		*p = E_OVF;
	}
	return result;
}

double resta(double num1, double num2, int *p)
{
	*p = N_ERR;
	double result;
	result = num1 - num2;
	if (num1 > 0 && num2 < 0 && result < 0) //Busca si hay error de overflow
	{
		*p = E_OVF;
	}
	if (num1 < 0 && num2 > 0 && result > 0) //Busca si hay error de overflow
	{
		*p = E_OVF;
	}
	return result;
}

double multi(double num1, double num2, int *p)
{
	*p = N_ERR;
	double result;
	result = num1 * num2;
	if (result > RANGE2) //Si supero el rango máximo de multiplicación
	{					 //tiro error.
		*p = E_OVF;
	}
	return result;
}

double div(double num1, double num2, int *p)
{
	*p = N_ERR;
	double result = 0;
	if (num2 == 0) // No puedo dividir por 0.
	{
		*p = E_DIV;
	}
	else
	{
		result = num1 / num2;
	}
	return result;
}

double pot(double num1, double num2, int *p)
{
	*p = N_ERR;
	double result = 1; //Inicializo para poder realizar la operación
	if ((num2 - (int)num2 <= -0.01) || (num2 - (int)num2 >= 0.01))
	{
		*p = E_POT;
		return result;
	}
	else if (num2 < 0)
	{
		for (int i = 0; i > num2; i--) //Calculo para exponente negativo
		{

			result = result * num1;
		}
		result = 1 / result;
	}
	else
	{
		for (int i = 0; i < num2; i++) //Calculo para exponente positivo
		{
			result = multi(result, num1, p);
			if (*p == E_OVF)
			{
				return result;
			}
		}
	}
	return result;
}