/***************************************************************************/ /**
  @file     +Constantes.h+
  @brief    +Header que contiene las constantes globales para todos los archivos+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef CONST_H
#define CONST_H

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define CLEAN_BUFFER()  while (getchar() != '\n') continue  // Macro para limpiar buffer.
#define PRINT_ERROR(error) printf("ERROR: %s \n", error) // Macro que imprime el error pedido.
#define ARRSIZE(arr) (sizeof(arr) / sizeof(*(arr)))      // Macro para obtener cantidad de elementos de un arreglo

// Generales
#define OK 0
#define FALSE 0
#define TRUE 1
#define OPMAX 5            //Cantidad de operadores admitidos.
#define RANGE 100000       //Constante que aparece en el menu de oprando máximo
#define RANGE2 10000000000 //Constante para la multiplicación
/*****************************************************************************/
#endif // CONST_H