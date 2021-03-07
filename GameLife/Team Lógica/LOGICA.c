#include <stdio.h>

#define MAT_SIZE 11
#define FILS    11
#define COLS    11

#define ALIVE   1   // Constantes para los estados de las células
#define DEAD    0

void newGeneration(int originalMat[][MAT_SIZE], int filas, int columnas, int generaciones);
//Genera la n-esima generación de la matriz originalMat. 

void copyMat(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int filas, int columnas);
//Copia en una nueva copiedMat Mcopy cada elemento de originalMat.

void cellNewState(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int x, int y, int filas, int columnas);
//Guarda en originalMat[x][y] el nuevo estado de la celula de posición (x,y).

int aliveNeighbors (int M[][MAT_SIZE], int x, int y, int fils, int cols);  
//Calcula la cant de vecinos vivos de la celula de M[x][y].

void showresult(int mat[][MAT_SIZE],int filas, int columnas);
//Muestra esteticamente por consola mat[][].


int main() 
{
    int mat[FILS][COLS]={
                         {0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,1,0,0,0,0,0,0},
                         {0,0,0,0,0,1,1,0,0,0,0},
                         {0,0,0,0,1,0,1,1,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,1,1,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0,0}};
    int filas = FILS;
    int col= COLS;
    int generaciones=1;

    newGeneration(mat, filas, col, generaciones);
    showresult(mat, filas, col);
    return 0;

}

void newGeneration(int originalMat[][MAT_SIZE], int filas, int columnas, int generaciones) 
{
    int matOldGen[filas][columnas];                         //  Matriz de backup para determinar el estado de las nuevas celulas.

    for (int t=0; t<generaciones ; t++)                     //Para cada una de las generaciones:
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

void copyMat(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int filas, int columnas)
{
    for (int i=0; i< filas; i++)                // Recorro filas.
    {
        for (int j = 0; j < columnas; j++)      // Recorro columnas.
        {
            copiedMat[i][j]=originalMat[i][j];  // Copio elemento elemento (i,j) la matriz original en una matriz copia.
        }
        
    }
}

void cellNewState(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int x, int y, int filas, int columnas)
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

int aliveNeighbors (int M[][MAT_SIZE], int x, int y, int fils, int cols)  
{
    int cont = 0;   // Contador de vecinos

    for (int i = x-1; i <= x+1; i++) {          // Recorro filas
        for (int j = y-1; j <= y+1; j++) {       // Recorro columnas
            if(!(i==x && j==y)) {                      // Si no es la propia celda
                if (i>=0 && i<fils && j>=0 && j<cols) { // Si esta entre los límites
                    if (M[i][j] == ALIVE) {                 // y solo si esta viva 
                        cont++;                                 // Incremento contador
                    }
                }
            }
        }
    }

    return cont;
}

void showresult(int mat[][MAT_SIZE],int filas, int columnas)
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
