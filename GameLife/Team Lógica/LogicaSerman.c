#include <stdio.h>

#define MAT_SIZE    20   //Tamaño máximo de la matriz (ancho = alto)

#define ALIVE   1   // Constantes para los estados de las células
#define DEAD    0

int aliveNeighbors (int M[][MAT_SIZE], int x, int y, int fils, int cols);

int main(void){
// Programa ejemplo para probar la funcion
    int mat[3][20] = {   {1, 1, 1},
                        {1, 1, 0},
                        {1 ,1, 0} };
    int x = 2, y = 1;
    printf("Vecinos de %d, %d: %d\n", x,y,aliveNeighbors(mat, x, y, 3, 3));
    return 0;
}

int aliveNeighbors (int M[][MAT_SIZE], int x, int y, int fils, int cols)  {

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