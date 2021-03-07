/***************************************************************************/ /**
  @file     +lectura.c+
  @brief    +lectura de la calculadora+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "lectura.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define OFFSET 48
#define DECIMAL 1
#define ENTERO 0
#define ERROR 0
#define NO_ERROR 1
#define NO_ERROR_OP 2
#define FIRST 0
#define NO_FIRST 1
#define NEG 1
#define POS 0

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

enum ingreso
{
	NUM1,
	OPER,
	NUM2,
	FIN
};

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/**
 * @brief lectura numero
 * @param *str Puntero a donde se encuentran los operadores
 * @param *pn Puntero donde se debe colocar el numero
 * @param *pop Puntero donde se debe colocar el operador
 * @param n Indica si es el primer o el segundo numero
 * @return si hubo o no error
*/
static int lect_num(double *pn, char *str, char *pop, int n);

/**
 * @brief lectura de operando
 * @param *str Puntero a donde se encuentran los operadores
 * @param *pop Puntero donde se debe colocar el operador
 * @return si hubo o no error
*/
static int lect_op(char *str, char *pop);

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void lect(char *str, double *pn1, double *pn2, char *pop)
{
	int ingreso = NUM1;
	int error = NO_ERROR;
	while (ingreso != (FIN))
	{
		switch (ingreso)
		{
		case NUM1:
			do
			{
				error = lect_num(pn1, str, pop, NUM1);
			} while (error == ERROR); //Mientras que haya un error que pida volver a ingresar el numero1
			if (error == NO_ERROR)
			{
				ingreso = OPER;
			}
			else
			{
				ingreso = NUM2;
			}
			break;

		case OPER:
			error = lect_op(str, pop);
			if (error == ERROR) //Mientras que haya un error que pida volver a ingresar el numero2
			{
				ingreso = NUM1;
			}
			else
			{
				ingreso = NUM2;
			}
			break;

		case NUM2:
			error = lect_num(pn2, str, pop, NUM2);
			if (error == ERROR) //Mientras que haya un error que pida volver a ingresar el numero3
			{
				ingreso = NUM1;
			}
			else
			{
				ingreso = FIN;
			}
			break;
		}
	}
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
static int lect_num(double *pn, char *str, char *pop, int n)
{
	int c;					  //character
	double num = 0, temp = 0; //número
	int num_type = ENTERO;
	double cant_dec = 10; //cantidad de numeros despues de la coma
	int sign = POS;
	int error = NO_ERROR;
	int first_c = FIRST;
	while (error == NO_ERROR && (c = getchar()) != '\n') //Mientras que no apriete enter
	{
		if (c == '-' && sign == POS && first_c == FIRST) //si era positivo y aprieto -, lo vuelvo negativo
		{
			sign = NEG;
		}
		for (int i = 0; i < OPMAX; i++)
		{
			if (str[i] == c && first_c == NO_FIRST && n == NUM1)
			{ //si es un operador y no es el primer caracter, que no sea un error
				*pop = c;
				error = NO_ERROR_OP; //no hay error y lei operador
			}
		}
		if (c >= '0' && c <= '9')
		{
			if (num_type == ENTERO)
			{
				temp = num * 10 + c - OFFSET; //Si el numero es entero, lo multiplico por
			}								  // 10 y le sumo el siguiente (para conformar el numero)
			else
			{
				temp = num + (c - OFFSET) / cant_dec; //si el numero es decimal, agrego el numero
				cant_dec *= 10;						  //despues de la coma
			}
		}
		else if (c == '.' || c == ',')
		{
			if (num_type == ENTERO) // paso de modo decimal a entero
			{
				num_type = DECIMAL;
			}
			else
			{
				error = ERROR; // si no, es un caracter erroneo
				PRINT_ERROR(COMAREPETIDA);
				CLEAN_BUFFER();
			}
		}
		else if (error == NO_ERROR && ((sign == NEG && first_c == NO_FIRST) || sign == POS))
		{
			error = ERROR; // si no, es un caracter erroneo
			PRINT_ERROR(CARACTINV);
			CLEAN_BUFFER();
		}
		first_c = NO_FIRST;
		if (temp <= RANGE) // Sume y quedo mayor, no hay Overflow
		{
			num = temp;
		}
		else // Hay overflow
		{
			error = ERROR;
			PRINT_ERROR(OUTOFRANGE);
			CLEAN_BUFFER();
		}
	}
	if (first_c == FIRST)
	{ // No se ingreso nada
		error = ERROR;
		PRINT_ERROR(CARACTINV);
	}
	else if (n == NUM1 && error == NO_ERROR) // Falta operador
	{
		error = ERROR;
		PRINT_ERROR(MALOPERADOR);
	}

	if (error != ERROR) // Si el número ingresado era negativo,
	{					//niego su módulo para obtenerlo.
		if (sign == NEG)
		{
			num = -num;
		}
		*pn = num;
	}
	return error;
}

static int lect_op(char *str, char *pop)
{
	char c;
	c = getchar();
	int error = ERROR;
	for (int i = 0; i < OPMAX; i++) // Comparo con los operadores que consideramos válidos.
	{
		if (str[i] == c) // Si el operador es reconocido, lo guardo en memoria.
		{
			*pop = c;
			error = NO_ERROR;
		}
	}
	if (error == ERROR) // Si el operador no es válido, aviso que hubo un error.
	{
		PRINT_ERROR(MALOPERADOR);
		CLEAN_BUFFER();
	}
	return error;
}