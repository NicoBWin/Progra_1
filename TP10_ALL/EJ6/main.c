/***************************************************************************//**
  @file     +main.c+
  @brief    +archivo principal del programa+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../EJ4/PORTS.h"
#include "../EJ4/const.h"
#include "lectura.h"

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
int main () {
	
	int	corriendo=TRUE;			// Declaro "corriendo" como la variable que indica cuando salgo del programa 
	int led=0;					// Cuando leo un número, guardo cual es el led a prender. 
	int estado=LECTURE;			// Inicio la máquina de estados en el estado lectura.

	while (corriendo==TRUE)		// Mientras no salga del programa, ejecuto la máquina.
	{
		switch (estado)			
		{
		case NUMERO:			// Si se aprieta un número:
			bitSet('A', led);	// Enciendo el led en cuestión
			estado=LECTURE;		// y vuelvo al estado de lectura.
			break;
				
		case TOGGLE:			// Si se aprieta 'T':

			for (int i=0; i<CANT_LEDS; i++)
			{
				bitToggle('A', i); 	// Invierto todos los leds
			}
			estado=LECTURE;			// y vuelvo al estado de lectura.
			break;

		case CLEAR:					// Si se aprieta 'C':

			for (int i=0; i<CANT_LEDS; i++)
			{
				bitClr('A', i);		// Limpio todos los leds
			}
			estado=LECTURE;			// y vuelvo al estado de lectura.
			break;
		
		case SET:					// Si se aprieta 'S':

			for (int i=0; i<CANT_LEDS; i++)
			{
				bitSet('A', i);		// Enciendo todos los leds
			}
			estado=LECTURE;			// y vuelvo al estado de lectura.
			break;

		case QUIT:					// Si se aprieta 'Q':
			corriendo=FALSE;		// Salgo  del while que ejecuta la máquina de estados.
			break;

		case LECTURE:					//En el caso de que tenga que leer:

			estado_bits('A');						// Primero imprimo el estado del puerto A.
			printf ("Ingrese un nuevo comando:");	// Pido un nuevo comando.
			estado = lectura();						// Hago la lectura de la consola.
			if(estado>=0 && estado<=CANT_LEDS)		// Si se ingresó un número:
			{
				led = estado;						// El número ingresado lo guardo como el led a prender.
				estado = NUMERO;					// Dirijo la máquina a estado Numero.
			}
			break;

		default:						// Ante cualquier error:
			estado = LECTURE;			//entro en estado de lectura.
			break;
		}
	}
	return 0;
}