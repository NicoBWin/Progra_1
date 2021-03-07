/***************************************************************************//**
  @file     +main.c+
  @brief    +archivo principal del programa+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include "PORTS.h"
#include "const.h"
#include "lectura.h"
#include "gui.h"

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/
bool ledState[CANT_LEDS];

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
/**
 * @brief Imprime el estado de todos los bits del puerto dado
 * @param port El nombre del puerto a mostrar ('A', 'B' o 'D').
 * @param port El nombre del puerto a mostrar ('A', 'B' o 'D').
*/
static void estado_bits(char port, bool* ledState);  
/**
 * @brief Imprime el estado de todos los bits del puerto dado
 * @param port El nombre del puerto a mostrar ('A', 'B' o 'D').
*/
void gen_bool(char port, bool *pointer, int bits);



int main () {
	
	if (init_all()) {
		return -1;
	}

	int	corriendo=TRUE;			// Declaro "corriendo" como la variable que indica cuando salgo del programa 
	int led=0;					// Cuando leo un número, guardo cual es el led a prender. 
	int estado=LECTURE;			// Inicio la máquina de estados en el estado lectura.
	int blinking=0;

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
			destroy_all();
			corriendo=FALSE;		// Salgo  del while que ejecuta la máquina de estados.
			break;

		case LECTURE:					//En el caso de que tenga que leer:
			estado_bits('A', ledState);		// Primero imprimo el estado del puerto A.
			printf ("Ingrese un nuevo comando:");	// Pido un nuevo comando.
			estado = lectura();						// Hago la lectura de la consola.
			if(estado>=0 && estado<=CANT_LEDS)		// Si se ingresó un número:
			{
				led = estado;						// El número ingresado lo guardo como el led a prender.
				estado = NUMERO;					// Dirijo la máquina a estado Numero.
			}
			break;

		case BLINK:
			blinking= ~blinking;
			estado = LECTURE;
			break;
			

		default:						// Ante cualquier error:
			estado = LECTURE;			//entro en estado de lectura.
			break;
		}
	}
	return 0;
}


void printPort(char port, int bits)
{    
    printf("Port %c: ", port);
    for (int i = bits-1; i >= 0; i--)           // Por cada bit del puerto imprimo el estado del mismo. 
    {
        (bitGet(port, i)==1)? printf("%c ", 254): printf("_ ");
    }
    printf("\n");
}

void gen_bool(char port, bool *pointer, int bits)
{
    for (int i=0; i<bits; i++)
    {
       pointer[i]=bitGet(port, i);   
    }
}

static void estado_bits(char port, bool* ledState)       
{
    int bits = 0;
	gen_bool(port, ledState, CANT_LEDS);
    switch (port) {
        case 'A':
            bits = 8;
            printPort(port, bits); 
            drawLEDS(ledState, bits);
            break;
        
        case 'B':
            bits = 8;
            printPort(port, bits);
            drawLEDS(ledState, bits);
            break;
        
        case 'D':
            bits = 16;
            printPort(port, bits);
            drawLEDS(ledState, bits);
            break;
        
        default:
            printf("Error, puerto inválido");
            break;
    }
}
