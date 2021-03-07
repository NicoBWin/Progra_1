/***************************************************************************//**
  @file     Lectura.h
  @brief    Archivo header del modulo Lectura
  @author   Grupo 3
 ******************************************************************************/

#ifndef LECT_H
#define LECT_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "Constantes.h"
//////////////////////////////////////////////////////////////////////#include ACA TENGO QUE INCLUIR EL QUE TIENE LA FUNCION loadingInstructor();  


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/



/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Carga los numeros de fila y columna de la matriz 
 * @return Cantidad de filas/columnas ingresadas por el usuario
*/
unsigned int lectNum(void);

/**
 * @brief Carga los valores en la matriz.
 * @param mat Matriz del juego de la vida
 * @param row Cantidad de filas de la matriz
 * @param col Cantidad de columnas de la matriz
 * @return void
*/
void lectMat (int mat [][MAT_SIZE], int row, int col);



/*******************************************************************************
 ******************************************************************************/

#endif // LECT_H