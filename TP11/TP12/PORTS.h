/***************************************************************************//**
  @file     +PORTS.h+
  @brief    +Archivo header del modulo PORTS para manejar puertos virtuales+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef _PORTS_H_
#define _PORTS_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include <stdint.h>   
#include "const.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Dado un puerto y un número de bit, cambia su estado a 1
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D')
 * @param bit El numero de bit a cambiar (0-7 para A y B, 0-16 para D)
 * @return NO_ERROR=-2 si se completo de manera exitosa, caso contrario ERROR=-1
*/
uint8_t bitSet(char port, uint8_t bit);

/**
 * @brief Dado un puerto y un número de bit, cambia su estado a 0
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D')
 * @param bit El numero de bit a cambiar (0-7 para A y B, 0-16 para D)
 * @return NO_ERROR=-2 si se completo de manera exitosa, caso contrario ERROR=-1
*/
uint8_t bitClr(char port, uint8_t bit);

/**
 * @brief Dado un puerto y un número de bit, devuelve su valor
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D')
 * @param bit El numero de bit a leer (0-7 para A y B, 0-16 para D)
 * @return El valor del bit solicitado (0-1) o ERROR=-1 si hay error en la entrada
*/
uint8_t bitGet(char port, uint8_t bit);

/**
 * @brief Dado un puerto y un número de bit, lo cambia al estado opueto 0/1 1/0
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D')
 * @param bit El numero de bit a cambiar (0-7 para A y B, 0-16 para D)
 * @return NO_ERROR=-2 si se completo de manera exitosa, caso contrario ERROR=-1
*/
uint8_t bitToggle(char port, uint8_t bit);

/**
 * @brief Dado un puerto y una máscara, prende todos los bits que son 1 en la máscara 
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D')
 * @param bit La máscara (MAX 8 bits para A y B, 16 bits para D)
 * @return NO_ERROR=-2 si se completo de manera exitosa, caso contrario ERROR=-1
*/
uint8_t maskOn(char port, uint16_t mask);

/**
 * @brief Dado un puerto y una máscara, apaga todos los bits que son 1 en la máscara 
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D')
 * @param bit La máscara (MAX 8 bits para A y B, 16 bits para D)
 * @return NO_ERROR=-2 si se completo de manera exitosa, caso contrario ERROR=-1
*/
uint8_t maskOff(char port, uint16_t mask);

/**
 * @brief Dado un puerto y una máscara, cambia el estado de todos los bits que son 1 en la máscara 
 * @param port El nombre del puerto a cambiar ('A', 'B' o 'D')
 * @param bit La máscara (MAX 8 bits para A y B, 16 bits para D)
 * @return NO_ERROR=-2 si se completo de manera exitosa, caso contrario ERROR=-1
*/
uint8_t maskToggle(char port, uint16_t mask);

/**
 * @brief Lee el estado de cada bit del puerto y lo convierte a  
 * @param port: El nombre del puerto a cambiar ('A', 'B' o 'D').
 * @param bit: cantidad de bits del puerto a leer. 
 * @return varible tipo int que represetnta el estado de cada bit.
 * */
int portGet(const char port, const int bits);

/**
 * @brief Imprime el estado de todos los bits del puerto dado
 * @param port El nombre del puerto a mostrar ('A', 'B' o 'D').
*/
void estado_bits(char port);
// Esta funcion es para ser utilizada en el ejercicio 6


/*******************************************************************************
 ******************************************************************************/

#endif // _PORTS_H_
