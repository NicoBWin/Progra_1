/***************************************************************************//**
  @file     Logica.c
  @brief    Archivo fuente del módulo Lógica
  @author   Grupo 3
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "Logica.h"
// +Incluir el header propio (ej: #include "template.h")+


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/**
 * @brief Copia en una nueva copiedMat cada elemento de originalMat.
 * @param originalMat La matriz a ser copiada 
 * @param copiedMat La matriz donde se realizara la copia
 * @param filas Cantidad de filas de las matrices
 * @param columnas Cantidad de columnas de las matrices
 * @return void
*/
static void copyMat(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int filas, int columnas);


/**
 * @brief Guarda en originalMat[x][y] el nuevo estado de la celula de posición (x,y).
 * @param originalMat Matriz del juego de la vida
 * @param copiedMat Matriz de la generacion anterior
 * @param x Posición x de la célula
 * @param y Posición y de la célula
 * @param filas Cantidad de filas de la matriz
 * @param columnas Cantidad de columnas de la matriz
 * @return void
*/
static void cellNewState(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int x, int y, int filas, int columnas);

/**
 * @brief Calcula la cant de vecinos vivos de la célula de M[x][y].
 * @param M Matriz del juego de la vida
 * @param x Posición x de la célula
 * @param y Posición y de la célula
 * @param fils Cantidad de filas de la matriz
 * @param cols Cantidad de columnas de la matriz
 * @return Cantidad de vecinos vivos de la célula
*/
static int aliveNeighbors (int M[][MAT_SIZE], int x, int y, int fils, int cols);  


/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static int temperaturas_actuales[4];+


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



 
void newGeneration(int originalMat[][MAT_SIZE], int filas, int columnas, double generaciones) 
{
    int matOldGen[MAT_SIZE][MAT_SIZE];                         //  Matriz de backup para determinar el estado de las nuevas celulas.

    for (double t=0; t<generaciones ; t++)                     //Para cada una de las generaciones:
    {
        copyMat(originalMat, matOldGen, filas, columnas);   //  Hago una copia de la generación anterior

        for (int i=0; i< filas; i++)                        //  Recorro filas de la matriz.
        {
            for (int j = 0; j < columnas; j++)              //  Recorro columnas de la matriz.
            {
                cellNewState(originalMat, matOldGen, i, j, filas, columnas);    // Y cargo en la matriz original el nuevo valor de cada celula .
            }  
        }
    }
}

static void copyMat(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int filas, int columnas)
{
    for (int i=0; i< filas; i++)                // Recorro filas.
    {
        for (int j = 0; j < columnas; j++)      // Recorro columnas.
        {
            copiedMat[i][j]=originalMat[i][j];  // Copio elemento elemento (i,j) la matriz original en una matriz copia.
        }
        
    }
}

static void cellNewState(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int x, int y, int filas, int columnas)
{
    int neighbors = aliveNeighbors(copiedMat, x, y, filas, columnas);   // Determino cuantos vecinos vivos tiene la celula.
    
    if (copiedMat[x][y]==ALIVE && (neighbors<2 || neighbors>3) )    // Si la celula esta viva y tiene más de 3 o menos de 2 vecinos, la mato.
    {
        originalMat[x][y]=DEAD;
    }

    else if (copiedMat[x][y]==DEAD && neighbors==3)                 // Si la celula esta muerta y tiene exactamente 3 vecinos, le doy vida nuevamente.
    {
        originalMat[x][y]=ALIVE;                                    
    }   
}

static int aliveNeighbors (int M[][MAT_SIZE], int x, int y, int fils, int cols)  
{
    int cont = 0;   // Contador de vecinos

    for (int i = x-1; i <= x+1; i++) {         		 // Recorro filas
        for (int j = y-1; j <= y+1; j++) {       	// Recorro columnas
            if(!(i==x && j==y)) {                     		 // Si no es la propia celda
                if (i>=0 && i<fils && j>=0 && j<cols) { // Si esta entre los límites
                    if (M[i][j] == ALIVE) {                	 // y solo si esta viva 
                        cont++;                                			 // Incremento contador
                    }
                }
            }
        }
    }
    return cont;
}

void showResult(int mat[][MAT_SIZE],int filas, int columnas)
{
    for (int i=0; i<filas; i++)             //  Recorro filas de la matriz
    {
        for (int j = 0; j < columnas; j++)  //  Recorro columnas de la matriz.
        {
            if (mat[i][j]==ALIVE)           //  Si la celula esta viva, lo imprimo.
            {
                printf(" | *");
            }
            else if (mat[i][j]==DEAD)       //  Si la celula esta muerta, lo imprimo.
            {
                printf(" |  ");
            }

            if (j==columnas-1)              //  Si estoy en la última celula de la fila, cierro la tabla.
            {
                printf(" |");
            }

        }
        printf("\n");                       //  Cuando termine de imprimir una fila, empiezo un nuevo renglón.
    }
}