/***************************************************************************//**
  @file     +main.c+
  @brief    +archivo principal del programa+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "PORTS.h"
#include "const.h"
#include "lectura.h"
#include "hardware.h"
#include "nonblock.h"
#include <unistd.h> // usleep
#include <stdio.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum BLINK_STATE { NO_BLINK, BLINK_OFF, BLINK_ON };     // Estado del blink


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
int main () {
	
	if(init_raspi()==ERROR)
	{
		return 1;
	}

	char c;
	int quit = 0;
	int	corriendo=TRUE;			// Declaro "corriendo" como la variable que indica cuando salgo del programa 
	int led=0;					// Cuando leo un número, guardo cual es el led a prender. 
	int estado=LECTURE;			// Inicio la máquina de estados en el estado lectura.
	uint8_t blink = BLINK_OFF;
	uint8_t blinkMask = 0x00;

	while (corriendo==TRUE)		// Mientras no salga del programa, ejecuto la máquina.
	{
		switch (estado)			
		{
		case NUMERO:			// Si se aprieta un número:
			bitSet(PORT, led);	// Enciendo el led en cuestión
			estado=LECTURE;		// y vuelvo al estado de lectura.
			break;
				
		case TOGGLE:			// Si se aprieta 'T':

			for (int i=0; i<CANT_LEDS; i++)
			{
				bitToggle(PORT, i); 	// Invierto todos los leds
			}
			estado=LECTURE;			// y vuelvo al estado de lectura.
			break;

		case CLEAR:					// Si se aprieta 'C':

			for (int i=0; i<CANT_LEDS; i++)
			{
				bitClr(PORT, i);		// Limpio todos los leds
			}
			estado=LECTURE;			// y vuelvo al estado de lectura.
			break;
		
		case SET:					// Si se aprieta 'S':

			for (int i=0; i<CANT_LEDS; i++)
			{
				bitSet(PORT, i);		// Enciendo todos los leds
			}
			estado=LECTURE;			// y vuelvo al estado de lectura.
			break;

		case BLINK:
			printf("Blink mode ON: MIRAR LED!\nPara salir presione b\n");
			blinkMask = portGet(PORT, CANT_LEDS); // Guardo estado actual como máscara
            maskOff(PORT, blinkMask);
			nonblock(NB_ENABLE);
    		while(!quit)
    		{
      			if (!kbhit())
				{
					usleep(500000);		// Un pequeño delay
					
					if (blink==BLINK_ON)
					{
						maskOn(PORT, blinkMask); 
						blink = BLINK_OFF;
					}
					else if (blink==BLINK_OFF) 
					{
						maskOff(PORT, blinkMask); 
						blink = BLINK_ON;
					}
					// estado_bits(PORT); // Lo comente para que cuando apretemos b no quede todo rancio
					act_leds(PORT);
				}
				else
				{
					c = getchar();
					quit = (c == BLINK);
				}
    		}
			quit=0;
			maskOn(PORT, blinkMask);    // Enciendo los que estaban blinkeando
    		nonblock(NB_DISABLE);
			estado=LECTURE;			// y vuelvo al estado de lectura.
			break;

		case QUIT:					// Si se aprieta 'Q':
			corriendo=FALSE;		// Salgo  del while que ejecuta la máquina de estados.
			break;

		case LECTURE:					//En el caso de que tenga que leer:

			estado_bits(PORT);						// Primero imprimo el estado del puerto A.
			act_leds(PORT);
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

	fin_raspi();	// Unexport de todos los pines utilizados

	return 0;
}
