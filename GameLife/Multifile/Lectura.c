/***************************************************************************//**
  @file     Lectura.c
  @brief    Archivo fuente del modulo Lectura
  @author   Grupo3
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "Lectura.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define ERROR       1       // Constantes que representan diferentes errores al 
#define ERROR_MAT   -1      //cargar la matriz.

#define RESETMAT    1       // Constantes que representan si es o no necesario
#define NORESETMAT  0       //resetear la matriz.

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/



/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/**
 * @brief Analiza los caracteres ingresados a la hora de cargar la matriz
 * @param col Cantidad de columnas de la matriz
 * @param reset Determina si se resetea o no el contador
 * @return void
*/
int lectChar (int col, int reset);




/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/




/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/




/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

unsigned int lectNum(void)
{
	int c=0;								 			// Caracter ingresado.	
	unsigned int num=0;                         		// Cuenta parcial del numero ingresado.
	int error=0;
	do
    {
		error = 0;
		while ( error!= ERROR && (c=getchar()) != '\n')           // Mientras que no apriete enter ni se encuentre error
        {	
			if (c>='0' && c<='9')
            {					
			    num=num*10+ c - CHAROFFSET;				// Si el numero es entero, lo multiplico por	
				    									//10 y le sumo el siguiente (para conformar
			}		    								//el numero)
			else 
            {
				error=ERROR;							// Si no, es un caracter erroneo y pido que vuelva a ingresar el numero.
				printf ("Cantidad erronea, por favor vuelva a ingresarla:\n");	
                CLEAN_BUFFER();		
			}
		}
		if (num==0 && error!=ERROR)
        {
			error=ERROR;								                        // Si primero ingresaste un enter o solo ingresaste un 0
			printf ("Cantidad erronea, por favor vuelva a ingresalarla:\n");    //pido que vuelva a ingresar el numero.
            
            if(c!='\n')
            {
                CLEAN_BUFFER();
            }
        }
	}
	while (error==ERROR);       					// Repetir todo el bucle hasta que se haya ingresado un valor válido.
	return num;
}

void lectMat (int mat [][MAT_SIZE], int row, int col)
{
	loadingInstructor();           					// Indico las instrucciones de carga de matriz.
    int reset=RESETMAT;                         
	for (int i=0; i<row; i++)
    {
		for (int j=0; j<col; j++)
        {				
			mat [i][j]= lectChar (col, reset);		// Cargo los valores ij de la matriz.
			reset=NORESETMAT;
			if (i==row-1 && j==col-1){        		// Si la matriz no termina con un ENTER.
				if (getchar()!='\n')          		//Reinicio la carga de la matriz.
                {					
					i=0;
					j=-1;
					CLEAN_BUFFER();
					printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
					reset=RESETMAT;
				}
			}
			if (mat [i][j]==ERROR_MAT){				// Si es un caracter no deseado
				i=0;                           		//reinicio la escrtiura de matriz
				j=-1;                          		//termino de leer la "basura" restante hasta completar la fila.		
			}
			
		}
	}
}

int lectChar (int col, int reset)
{
	int c;											// Caracter leído.	
	int a=0;                                        // Estado de la celula.
	static int cont=-1;                             // Contador de celulas cargadas por fila.
	
    if (reset==RESETMAT)
    {
		cont=-1;                                    // Si necesito empezar de cero reinicio el contador
	}
	
    cont++;                                         // Por cada caracter leído, incremento el contador de celulas cargadas por fila. 
    do
    {
		c=getchar();
		
        if (c== '*' || c== 'A' || c== '1')
        {                                       	//Si la celula esta viva
			a=ALIVE;								//coloco un 1.
		}
		
        else if  (c== ' ' || c== 'D' || c== '0')
        {                                          	// Si la celula esta muerta
			a=DEAD;									//coloco un 0.
		}
		
        else if (c=='\n')
        {
			if (cont<col)                           // Si se cargaron menos celulas de las que deberían
            {                                       //aviso por consola y reseteo la carga de matriz.
				c= ERROR_MAT;
				a= ERROR_MAT;
				printf ("Faltan valores para completar la fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}
			else if (cont>col)                       // Si se cargaron más celulas de las que deberían
            {                                        //aviso por consola y reseteo la carga de matriz.
				c=ERROR_MAT;
				a=ERROR_MAT;
				printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}	
			else
            {
				cont=0; 
			}
		}
		else
        {
			printf ("El caracter ingresado fue erróneo. Por favor vuelva a ingresar el tablero.\n");
			a=ERROR_MAT;							// Si se ingreso un caracter no deseado,
			cont=-1;                                //que vuelva a ingresar la matriz e 
            CLEAN_BUFFER();                         //ignoro todos los datos siguientes.
		}		
	}
	while (c == '\n');                              // Repito el bucle hasta que encuentre el caracter terminador "\n"
	
	return a;
}	


 