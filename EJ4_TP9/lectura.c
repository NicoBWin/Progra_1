/***************************************************************************//**
  @file     +lectura.c+
  @brief    +Guarda los caracteres ingresados en un string y entrega el largo+
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
#define ERROR   1
#define NO_ERROR 0 
#define CLEAN_BUFFER()  while (getchar() != '\n') continue  // Macro para limpiar buffer.

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
int lect (char *point, int leng)
{
	char *p=point;
	int error=NO_ERROR;
	int cont=0;
	int c;
	do
    {	
		error=NO_ERROR;
		while ((c=getchar()) != '\n' && error!=ERROR && cont<leng)
        {
				*p++=c;
				cont++;
		}
		if (cont>=leng)
        {            //Si se excedió de la cantidad de caracteres maximos
			printf ("Se excedio de la cantidad de caracteres maximo.\nPor favor vuelva a ingresarla:\n");
			error=ERROR;                //Hay error
			CLEAN_BUFFER();
			cont=0;                     //Vuelve a comenzar a leer
			p=point;
		}
	} while (error==ERROR);		// Repito hasta que se ingrese correctamente
	return cont;
}