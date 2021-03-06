/***************************************************************************//**
  @file     +PORTS.c+
  @brief    +Archivo source del modulo PORTS para manejar puertos virtuales+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "PORTS.h"
#include <stdio.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef struct {
    uint8_t low;
    uint8_t high;   
} byte16_t;

typedef union {     // Acceso por
    byte16_t bytes;  //  - bytes
    uint16_t word;   //  - word
} port16_t;

typedef struct {        // Estructura de A+B
    uint8_t portB;
    uint8_t portA;
} portsAB_t;

typedef union {
    portsAB_t port8;
    port16_t portD;
} port_t;


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static int gen_mascara(int bit);

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
static port_t puertos; 

enum ERRORES		// Distintos tipos de errores
{
	NO_ERROR = -2,
	ERROR = -1
};

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

uint8_t bitSet (char port, uint8_t bit){
    int msk = gen_mascara(bit);     // Genero la m??scara acorde al bit deseado.
    return maskOn (port, msk);      // Enciendo el bit indicado y retorno si hay o no error.
}

uint8_t bitClr (char port, uint8_t bit)
{
    int msk = gen_mascara(bit);     // Genero la m??scara acorde al bit deseado.
    return maskOff (port, msk);     // Apago el bit indicado y retorno si hay o no error.
}

uint8_t bitGet(char port, uint8_t bit)
{
    int msk = gen_mascara(bit); 
    switch (port)
    {
    case 'A':
        msk = ((puertos.port8.portA & msk)>0)? 1:0;     //Trabajando con mascaras corroboro si un bit esta encendido
        break;

    case 'B':
        msk = ((puertos.port8.portB & msk)>0)? 1:0;    //Trabajando con mascaras corroboro si un bit esta encendido
        break;

    case 'D':
        msk = ((puertos.portD.word & msk)>0)? 1:0;          //Trabajando con mascaras corroboro si un bit esta encendido
        break;
    
    default:
        printf("Puerto no encontrado.");
        return ERROR;
        break;
    }
    return msk;
}

uint8_t bitToggle(char port, uint8_t bit)
{
    int msk = gen_mascara(bit);     // Genero la m??scara acorde al bit indicado.
    return maskToggle (port, msk);  // Invierto el bit indicado y retorno si hay o no error.
}

uint8_t maskOn (char port, uint16_t mask)
{
    uint8_t error = NO_ERROR;
    switch (port)
    {
        case 'A':
            puertos.port8.portA |= mask;       // Trabajando con m??scaras enciendo los bits deseados.
            break;
            
        case 'B':
            puertos.port8.portB |= mask;       // Trabajando con m??scaras enciendo los bits deseados.
            break;

        case 'D':
            puertos.portD.word |= mask;             // Trabajando con m??scaras enciendo los bits deseados.
            break;

        default:
            printf("Puerto no encontrado. \n");     // De no encontrarse el puerto, devuelvo error.
            error =  ERROR;
            break;
    }
    return error;                                   // Retorno si la operaci??n fue exitosa.
}

uint8_t maskOff (char port, uint16_t mask)
{
    uint8_t error= NO_ERROR;
    switch (port)
    {
        case 'A':
            puertos.port8.portA &= (~(uint8_t)mask);   // Trabajando con mascaras apago los bits indicados
            break; 
        case 'B':
            puertos.port8.portB &= (~(uint8_t)mask);   // Trabajando con mascaras apago los bits indicados
            break;
        case 'D':
            puertos.portD.word &= (~ mask);         // Trabajando con mascaras apago los bits indicados
            break;
        default:
            printf("Puerto no encontrado.\n");      // De no encontrarse el puerto, devuelvo error.
            error=  ERROR;
            break;
    }
    return error;                                   // Retorno si la operaci??n fue exitosa.
}

uint8_t maskToggle (char port, uint16_t mask)
{
    uint8_t error= NO_ERROR;
    uint8_t temporalA = puertos.port8.portA & (~mask);     // Guardo en temporal todos los bits del puerto que no esten en la mascara.
    uint8_t temporalB = puertos.port8.portB & (~mask);     // Guardo en temporal todos los bits del puerto que no esten en la mascara.
    uint16_t temporalD = puertos.portD.word & (~mask);          // Guardo en temporal todos los bits del puerto que no esten en la mascara.

    switch (port)
    {
    case 'A':   
        
        puertos.port8.portA =~ puertos.port8.portA;   // Trabajando con m??scaras invierto los bits deseados.
        puertos.port8.portA &= mask;
        puertos.port8.portA |= temporalA;
        break;
        
    case 'B':
        
        puertos.port8.portB = ~ puertos.port8.portB;  // Trabajando con m??scaras invierto los bits deseados
        puertos.port8.portB &=  mask;
        puertos.port8.portB |= temporalB;
        break;

    case 'D':
        
        puertos.portD.word =~ puertos.portD.word;   // Trabajando con m??scaras invierto los bits deseados
        puertos.portD.word &= mask;
        puertos.portD.word |= temporalD;
        break;
    default:
        printf("Puerto no encontrado.\n");          // De no encontrarse el puerto, devuelvo error.
        error=  ERROR;
        break;
    }
return error;                                       // Retorno si la operaci??n fue exitosa.
}

int portGet(const char port, const int bits)
{
    int state = 0;
    switch (port)
    {
        case 'A':
            state = puertos.port8.portA;
            break;
            
        case 'B':
            state = puertos.port8.portB;
            break;

        case 'D':
            state = puertos.portD.word;
            break;

        default:
            printf("Puerto no encontrado.\n");     // De no encontrarse el puerto, devuelvo error.
            state = -1;
            break;
    }
    return state;
}

// int portGet(char port, int bits)
// {    
//     static int temporal=0;   // WHY STATIC???
//     for (int i = bits-1; i >= 0; i--)           // Por cada bit del puerto guardo el estado del mismo. 
//     {
//         if(bitGet(port, i)==1) 
//         {
//             temporal+=1;
//         }

//         if(i>0)
//         {
//             temporal = temporal<<1;
//         }
//     }
//     return temporal;
// }

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
    
static int gen_mascara(int bit)        // Genera la mascara necesaria para operar de forma mascarizada
{                               //basandose en el bit que se desea modificar.
    if (bit >= 0) {
        return (1<<bit);
    }
    else
    {
        return 0;
    }
}