/***************************************************************************//**
  @file     +Constantes.h+
  @brief    +Header que contiene las constantes globales para todos los archivos+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef CONST_H
#define CONST_H

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define CLEAN_BUFFER()  while(getchar()!='\n') continue  // Macro para limpiar buffer.
#define PRINT_ERROR(error)  printf("ERROR: %s \n", error)

// Generales
#define OK  0
#define FALSE 0
#define TRUE  1
#define OPMAX 10
enum OPERADORES{OP_SUMA='+', OP_RESTA='-', OP_MULTI='*', OP_DIV='/', OP_EXP='^'};

//ERRORES DE CALCULO
#define ERR_0DIV  "No se puede dividir por cero"

//ERRORES DE CARGA
#define CARACTINV "El número ingresado contiene caracteres inválidos. Vuelva a ingresar el numero:"
#define COMAREPETIDA "No puede ingresar una coma dos veces. Vuelva a ingresar el numero:"

//ERRORES DENTROS DE LAS OPERACIONES

#define DIV_0X0 -1
#define OUT_OF_SCALE -2
#define DECIMAL_EXP -3

/*
#define POSI_OUT_OF_RANGE 
#define NEG_OUT_OF_RANGE*/
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/


/*******************************************************************************
 ******************************************************************************/

#endif // CONST_H