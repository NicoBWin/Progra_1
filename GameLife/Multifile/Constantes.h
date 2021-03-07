/***************************************************************************//**
  @file     +Logica.h+
  @brief    +Descripcion del archivo+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef CONSTS_H
#define CONSTS_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define MAT_SIZE	100
#define ALIVE     1   	// Constantes para los estados de las células
#define DEAD		  0  
#define CHAROFFSET  '0'

#define CLEAN_BUFFER()     while (getchar() != '\n')    //Macro para limpiar el buffer de getchar()


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
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+


/*******************************************************************************
 ******************************************************************************/

#endif // CONSTS_H