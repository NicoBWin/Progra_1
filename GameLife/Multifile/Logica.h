/***************************************************************************//**
  @file     +Logica.h+
  @brief    +Descripcion del archivo+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef LOGIC_H
#define LOGIC_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "Constantes.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Genera la n-esima generación de la matriz originalMat. 
 * @param originalMat Matriz del juego de la vida
 * @param filas Cantidad de filas de la matriz
 * @param columnas Cantidad de columnas de la matriz
 * @param generaciones Cantidad de generaciones a avanzar
 * @return void
*/
void newGeneration(int originalMat[][MAT_SIZE], int filas, int columnas, double generaciones);


/**
 * @brief Muestra esteticamente por consola mat[][]. 
 * @param mat Matriz del juego de la vida
 * @param filas Cantidad de filas de la matriz
 * @param columnas Cantidad de columnas de la matriz
 * @return void
*/
void showResult(int mat[][MAT_SIZE],int filas, int columnas);

/*******************************************************************************
 ******************************************************************************/

#endif // LOGIC_H
