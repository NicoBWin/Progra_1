#include <stdio.h>
#include <stdint.h>
#include "../EJ4/PORTS.h"

#define PORT_D_BITS_AMOUNT 16
#define PORT_A_BITS_AMOUNT 8
#define PORT_B_BITS_AMOUNT 8

#define MASK_8 0xF0         // Mascaras aleatorias. 
#define MASK_16 0xFADE  

/**
 * @brief Pasa el contenido del puerto a decimal, sirve para 8 bits y 16 bits. 
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D').
 * @param portBits La cantidad de bits de puerto.
 * @return Devuelve un entero de 16 bits.
*/
uint16_t bin2dec(char port, uint8_t portBits);


int main(void)
{
    //Variables para el conteo de pruebas
    int totalTests = 0;
    int passTests = 0;
    int failTests = 0;

/*#############################################################################
#####################    Prueba de bitSet en A y B    #########################
#############################################################################*/

    for(int i = 0; i < PORT_A_BITS_AMOUNT; i++ )  // Ya el puerto viene todo en 0. Pues es estatica y global.
    {
        totalTests++;
        bitSet('A',i);                             
        if(bitGet('A',i))
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitSet fallada\n");
        }
    }

    for(int i = 0; i < PORT_B_BITS_AMOUNT; i++ )
    {
        totalTests++;
        bitSet('B',i);
        if(bitGet('B',i))
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitSet fallada\n");
        }
    }

/*#############################################################################
###################    Prueba de bitClr EN A y B    #########################
#############################################################################*/

    for(int i = 0; i < PORT_A_BITS_AMOUNT; i++ )  
    {
        totalTests++;
        bitClr('A',i);
        if( !(bitGet('A',i)) )
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitClr fallada\n");
        }
    }

    for(int i = 0; i < PORT_B_BITS_AMOUNT; i++ )
    {
        totalTests++;
        bitClr('B',i);
        if( !(bitGet('B',i)) )
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitClr fallada\n");
        }
    }

/*#############################################################################
####################    Prueba de bitSet en D     #############################
#############################################################################*/


    for(int i = 0; i < PORT_D_BITS_AMOUNT; i++ )
    {
        totalTests++;
        bitSet('D',i);
        if(bitGet('D',i))
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitSet en D fallada\n");
        }
    }

/*#############################################################################
####################    Prueba de bitClr en D     ###########################
#############################################################################*/


    for(int i = 0; i < PORT_D_BITS_AMOUNT; i++ )
    {
        totalTests++;
        bitClr('D',i);
        if( !(bitGet('D',i)))
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitClr en D fallada\n");
        }
    }


/*#############################################################################
####################    Prueba de bitToggle en D     ##########################
#############################################################################*/


    for(int i = 0; i < PORT_D_BITS_AMOUNT; i++ )
    {
        totalTests++;
        bitToggle('D',i);
        if( bitGet('D',i) )
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitToggle en D fallada\n");
        }
    }

/*#############################################################################
####################    Prueba de bitToggle en A y B     ######################
#############################################################################*/

    for(int i = 0; i < PORT_A_BITS_AMOUNT; i++ )
    {
        totalTests++;
        bitToggle('A',i);
        if( !(bitGet('A',i)) )
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitToggle fallada\n");
        }
    }

    for(int i = 0; i < PORT_B_BITS_AMOUNT; i++ )
    {
        totalTests++;
        bitToggle('B',i);
        if( !(bitGet('B',i)) )
        {
            passTests++;
        }
        else
        {
            failTests++;
            printf("Prueba bitToggle fallada\n");
        }
    }

/*#############################################################################
####################    Prueba de maskOn en A y B     #########################
#############################################################################*/


    totalTests++;

    bitSet('A', 0);                                                     //Seteo aleatorio de bits
    bitSet('A', 1);                                                     //No importa con que valores venia el puerto
    bitSet('A', 2);
    bitSet('A', 3);

    uint8_t capaAnterior = bin2dec( 'A', PORT_A_BITS_AMOUNT);      //Consigo el valor decimal del puerto

    uint8_t comparacion = capaAnterior | MASK_8;                            //Calculo el resultado que deberia dar la funcion pero a mano
                                                                            //para despues comparar
    maskOn('A', MASK_8);

    uint8_t resultado = bin2dec( 'A', PORT_A_BITS_AMOUNT);

    if(comparacion == resultado)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskOn en A y B fallada\n");
    }

//OTRO TEST

    totalTests++;

    bitSet('A', 7);
    bitSet('A', 5);
    bitSet('A', 3);
    bitSet('A', 0);

    capaAnterior = bin2dec( 'A', PORT_A_BITS_AMOUNT);

    comparacion = capaAnterior | MASK_8;

    maskOn('A', MASK_8);

    resultado = bin2dec( 'A', PORT_A_BITS_AMOUNT);

    if(comparacion == resultado)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskOn en A y B fallada\n");
    }

//Puerto B

    totalTests++;

    bitSet('B', 7);
    bitSet('B', 5);
    bitSet('B', 3);
    bitSet('B', 0);

    capaAnterior = bin2dec( 'B', PORT_B_BITS_AMOUNT);

    comparacion = capaAnterior | MASK_8;

    maskOn('B', MASK_8);

    resultado = bin2dec( 'B', PORT_B_BITS_AMOUNT);

    if(comparacion == resultado)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskOn en B fallada\n");
    }


/*#############################################################################
####################    Prueba de maskOn en D     #############################
#############################################################################*/

    totalTests++;

    bitSet('D', 7);
    bitSet('D', 5);
    bitSet('D', 3);
    bitSet('D', 0);

    uint16_t capaAnterior16 = bin2dec( 'D', PORT_D_BITS_AMOUNT);      //Idem pero para el puerto de 16bits

    uint16_t comparacion16 = capaAnterior16 | MASK_16;

    maskOn('D', MASK_16);

    uint16_t resultado16 = bin2dec( 'D', PORT_D_BITS_AMOUNT);

    if(comparacion16 == resultado16)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskOn en D fallada\n");
    }

/*#############################################################################
####################    Prueba de maskOFF en D     #############################
#############################################################################*/

    totalTests++;

    bitSet('D', 7);
    bitSet('D', 5);
    bitSet('D', 3);
    bitSet('D', 0);

    capaAnterior16 = bin2dec( 'D', PORT_D_BITS_AMOUNT);

    comparacion16 = capaAnterior16 &  ~MASK_16;                                 //Aca cambia la mascara de comparacion pues se debe resetear los bits no setear

    maskOff('D', MASK_16);

    resultado16 = bin2dec( 'D', PORT_D_BITS_AMOUNT);

    if(comparacion16 == resultado16)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskOn en D fallada\n");
    }

/*#############################################################################
####################    Prueba de maskOFF en A     ############################
#############################################################################*/

    totalTests++;

    bitSet('A', 7);
    bitSet('A', 5);
    bitSet('A', 3);
    bitSet('A', 0);

    capaAnterior = bin2dec( 'A', PORT_A_BITS_AMOUNT);

    comparacion = capaAnterior &  ~MASK_8;

    maskOff('A', MASK_8);

    resultado = bin2dec( 'A', PORT_A_BITS_AMOUNT);

    if(comparacion == resultado)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskOff en A y B fallada\n");
    }


/*#############################################################################
####################    Prueba de maskToggle en A     #########################
#############################################################################*/


    totalTests++;

    bitSet('A', 7);                                             //Seteo aleatorio de bits
    bitSet('A', 5);
    bitSet('A', 3);
    bitSet('A', 0);

    capaAnterior = bin2dec( 'A', PORT_A_BITS_AMOUNT);

    comparacion =  capaAnterior ^ MASK_8;                           //Cambia la mascara de comparacion nuevamente, pues se tiene que tugliar ahora

    maskToggle('A', MASK_8);

    resultado = bin2dec( 'A', PORT_A_BITS_AMOUNT);

    if(comparacion == resultado)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskToggle en A fallada\n");
    }

/*#############################################################################
####################    Prueba de maskToggle en D   ###########################
#############################################################################*/

    totalTests++;

    bitSet('D', 7);
    bitSet('D', 5);
    bitSet('D', 3);
    bitSet('D', 0);                     //Aleatorio
    bitSet('D', 4);
    bitSet('D', 1);
    bitClr('D',12);
    bitClr('D',11);
    bitClr('D',10);

    capaAnterior16 = bin2dec( 'D', PORT_D_BITS_AMOUNT);

    comparacion16 = capaAnterior16 ^ MASK_16;                       //Ahora para 16bits

    maskToggle('D', MASK_16);

    resultado16 = bin2dec( 'D', PORT_D_BITS_AMOUNT);

    if(comparacion16 == resultado16)
    {
        passTests++;
    }
    else
    {
        failTests++;
        printf("Prueba maskOn en D fallada\n");
    }
    printf("Total tests: %d\n", totalTests);
    printf("Passed tests: %d\n", passTests); 
    printf("Failed tests: %d\n", failTests); 

}

uint16_t bin2dec(char port, uint8_t portBits) // Devuelve un entero de 16 para no tener que escribir de 2 funciones para 8 y 16 bits. 
{                                             //Esta funcion se hace ya que solo se puede acceder de a bits con bitGet.
    uint16_t  a=0;                             
    if(portBits == PORT_A_BITS_AMOUNT)
    {
        for (int i = 0; i < portBits; i++)  // Primero se van levantando los bits menos significativos, estos son colocados en el bit mas significativos del Bytes
        {                                   // Cuando entran los bits mas significativos estos hacen que los que estaban en el bytes se vayan shifteando a la derecha                               
            a = ( bitGet(port, i) <<  (portBits -1) ) | ( a >> 1  );  //una vez que termino el loop, quedo bien ordenado el byte.
        }                                           
    }
    else if(portBits == PORT_D_BITS_AMOUNT)
    {   
        for (int i = 0; i < portBits; i++)                                 //Lo mismo pero para 16 bits
        {
            a = ( bitGet(port, i) <<  (portBits -1)  ) |  a >> 1; 
        }   
    }
    return a;
}
