/***************************************************************************//**
  @file     +lectura.h+
  @brief    +Modulo que contiene funciones para manejar enrtadas del usuario.+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef LECTURA_H
#define LECTURA_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "const.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief lect: Guarda los caracteres ingresados en un string
 * @param *point Puntero al string donde guarda los caracteres ingresados
 * @param leng    Tamaño maximo permitido en el string
 * @return Cantidad de caracteres ingresados
*/
int lect (char *point, int leng);

/*******************************************************************************
 ******************************************************************************/

#endif // LECTURA_H