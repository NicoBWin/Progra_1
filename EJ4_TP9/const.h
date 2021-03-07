/***************************************************************************//**
  @file     +const.h+
  @brief    +Archivo con constantes y macros necesarias para todo el programa+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef CONST_H
#define CONST_H

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define MAY_TO_MIN(c)   (((c)<='Z' && (c)>='A')? ((c)+'a'-'A'):(c)) 
// Si tengo un caracter en mayúscula lo paso a minúscula.

#define MIN_TO_MAY(c)   (((c)<='z' && (c)>='a')? (c)+'A'-'a':(c)) 
// Si tengo un caracter en minúscula lo paso a mayúscula.

#define MAX_LENG 100       //Cantidad máxima de caracteres a ingresar

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum boolean {NO_OK,OK};

/*******************************************************************************
 ******************************************************************************/

#endif // CONST_H