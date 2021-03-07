/***************************************************************************//**
  @file     +lectura.c+
  @brief    +El usuario ingresa un dato y se transforma a int que el main analiza+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "lectura.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define OFFSET 48

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static int endp (void); //Clásico mensaje que "Do you want to quit? Y/N"

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
int lectura() {
	char c;
	int cont;
	int out=0;
	int error;
	do{
		error=NO_ERROR;
		cont=0;
		while(error!=ERROR && (c=getchar()) != '\n') 
		{
			cont++;
			if(cont>1) 
			{
				printf("Solo se puede ingresar UN caracter!\n");
				error=ERROR;
				CLEAN_BUFFER();
			}
			else if(c=='s'|| c=='S') //Si es s prender todos los led
			{	
				out=S;
			}
			else if(c=='t'|| c=='T') //Si es t invertir el estado de todos los leds
			{
				out=T;
			}
			else if(c=='c'|| c=='C') //Si es c apagar todos los led
			{	
				out=C;
			}
			else if(c=='q'||c=='Q') //Si es q salir del programa
			{	
				if (endp()==TRUE)
				{
					return out=Q;
				}
				else 
				{
					printf("\nBuena eleccion...\nIngrese un nuevo comando:");
					error=ERROR;		//Vuelve a pedir al usuario que ingrese datos
				}
			}	
			else if (c>='0' && c<='7')	//Si es un numero devolver ese número 
			{
				out=c-OFFSET;
			}
			else
			{
				printf("Valor ingresado INVALIDO\n");
				error=ERROR;
				CLEAN_BUFFER();
			}
		}
	} while (error==ERROR);		// Repito hasta que se ingrese correctamente
	return out;	 //Devuelvo el valor el formato int que interpretará el main
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
static int endp () //Pregunta al usuario si realmente quiere salir y le da la opcion
{	 
	char q;		//de continuar o salir definitivamente
	int out2=0;
	int error2;
	CLEAN_BUFFER();
	printf("Quiere salir del programa? Y/N: ");
	do
	{
		error2=NO_ERROR;
		while(error2!=ERROR && (q=getchar()) != '\n') 
		{
			if(q=='y' || q == 'Y') //Realmente quiere salir
			{	 
				out2 = TRUE;
			}
			else if(q=='n' || q=='N') //No quiere salir del programa 
			{
				out2 = FALSE;
			}
			else
			{
				printf("Y/N: ");
				error2=ERROR;
				CLEAN_BUFFER();
			}
		}
	} while (error2==ERROR);		// Repito hasta que se ingrese correctamente
	return out2;
}