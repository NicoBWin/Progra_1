#include <stdio.h>

#define MAT_SIZE	11
#define FILS		11	// Constantes para los estados de las células
#define COLS		11
#define ALIVE   	1   	// Constantes para los estados de las células
#define DEAD		0
#define CHAROFF     '0'
#define CORRIENDO   1
#define APAGADO     0
#define EQUAL       1
#define NOTEQUAL    0

//enum STATES {NUMERO, ENTER='\n', FIN='f', TERMINAL='i', CARGA='l'}

void welcome (void);
// printf's de la introducción inicial.

void menu(int mat[][MAT_SIZE], int filas, int columnas);
// Gestor que maneja todo el tema de ejecutar las funciones necesarias según lo que indiquen por consola.

void newGeneration(int originalMat[][MAT_SIZE], int filas, int columnas, double generaciones);
// Genera la n-esima generación de la matriz originalMat. 

void copyMat(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int filas, int columnas);
// Copia en una nueva copiedMat Mcopy cada elemento de originalMat.

void cellNewState(int originalMat[][MAT_SIZE], int copiedMat[][MAT_SIZE], int x, int y, int filas, int columnas);
// Guarda en originalMat[x][y] el nuevo estado de la celula de posición (x,y).

int aliveNeighbors (int M[][MAT_SIZE], int x, int y, int fils, int cols);  
// Calcula la cant de vecinos vivos de la celula de M[x][y].

void showresult(int mat[][MAT_SIZE],int filas, int columnas);
// Muestra esteticamente por consola mat[][].

void cleanBuffer();
// Limpia todo el contenido del buffer.

void teclasAPulsar();
// printf's de los comandos a utilizar.

int comparison(int mat[][MAT_SIZE],int mat2[][MAT_SIZE], int filas, int columnas);
// Determina cuando todos los elementos de mat son iguales a los de mat2.



int main ()
{
	welcome();

    int mat[FILS][COLS]={
                         {0,0,0,0,0,0,0,0,1,0,0},
                         {0,0,0,0,0,0,0,0,1,0,0},
                         {0,0,0,0,0,0,0,0,0,1,0},
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

	showresult(mat, filas, col);	//Matriz inicial
    
    teclasAPulsar();
    menu(mat, filas, col);
    return 0;
}

void welcome ()
{
	printf("***************************************************************************\n");
    printf("*\t\t  Hola, bienvenido al juego de la vida!\t\t\t  *\n");
	printf("*      En el tablero se vera una simulacion predeterminada de celulas\t  *\n");
	printf("*\t  El |*| representa la vida y el | | representa la muerte\t  *\n");
	printf("*Las condiciones de vida son las siguientes:\t\t\t\t  *\n");
	printf("*a) Una célula viva con menos de dos vecinos muere\t\t\t  *\n");
	printf("*b) Una célula con mas de tres vecinos también muere\t\t\t  *\n");
	printf("*c) Una célula con exactamente dos o tres vecinos sobrevivo\t\t  *\n");
	printf("*d) Una célula muerta con exactamente tres vecinos obtiene vida nuevamente*\n");
	printf("***************************************************************************\n\n");
}

void menu(int mat[][MAT_SIZE], int filas, int columnas)
{
    int juego = CORRIENDO;
    int generaciones=0;

    while (juego == CORRIENDO)          // Mientras que no aprete 'F', me quedo en el bucle esperando que me indiquen las generaciones.
    {
        int comando=getchar();
        int num=comando-CHAROFF;

        /* if(num>=0 && num<=9)
            {
                comando=NUMERO;
            }
        
            switch (comando)
            {
                case NUMERO:
                break;

                case ENTER:
                break;

                case FIN:
                break;

                case TERMINAL:
                break;

                case CARGA:
                break;

                case DEFAULT:
                printf("Ingrese un comando válido");
                break;
            }
        */

        if(num>=0 && num<=9)    //Si el caracter leido es un numero, actualizo el valor parcial del numero.
        {
            generaciones = generaciones*10+num;    
        }
        else if (comando=='\n')       // Si el caracter leido es '\n', entonces:
        {
            if (generaciones!=0)        //  a) Si ingrese ningún número 'n', salto 'n' generaciones.  
            {
                newGeneration(mat, filas, columnas, generaciones);
                generaciones=0;
                printf("Matriz resultante:\n");
                showresult(mat, filas, columnas);
                teclasAPulsar();
            }
            else            //  b) Si no ingrese ningún número, salto una sola generación.
            {
                newGeneration(mat, filas, columnas, 1);    
                printf("Matriz resultante:\n");
                showresult(mat, filas, columnas);
                teclasAPulsar();
            }

        }
        else if (comando=='f')
        {
			juego = APAGADO;
            printf("\n\n\n\n\nHa salido del juego, esperamos que se haya divertido.\n");
		}
        else if (comando=='i')
        {
            int mat2[MAT_SIZE][MAT_SIZE];
            int equals;
            unsigned long long int cont_generaciones = 0;

            do
            {
                cont_generaciones++;
                copyMat(mat, mat2, filas, columnas);
                newGeneration(mat, filas, columnas, 1);
                equals = comparison(mat ,mat2, filas, columnas);
            } while (equals==NOTEQUAL);

            printf("Matriz resultante:\n");
            showresult(mat, filas, columnas);
            printf("Se llega a la matriz terminal en %llu generaciones, o sea,\n", cont_generaciones-1);
            printf("nada se modifica despues de la generación %llu \n", cont_generaciones);
            cleanBuffer();
            teclasAPulsar();
            
        }
        else if (comando=='l')
        {
            cleanBuffer();
            // FUNCION DE KEVIN.
            teclasAPulsar(); 
        }
        else if (((comando=='.' || comando==',') && generaciones !=0) || comando=='-') 
        {
			
            printf("La cantidad de generaciones a correr debe ser un número natural.\n");
			generaciones=0;
            cleanBuffer();
            teclasAPulsar();
		}
        else 
        {
			printf("Por favor ingrese comandos admisibles.\n");
			generaciones=0;
            cleanBuffer();
            teclasAPulsar();
		}
    }
}

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

void cleanBuffer()
{   
    int c=0;
    do
    {
        c=getchar();
    } while (c != '\n');
}

void teclasAPulsar()
{
    printf("Presione 'l' para cargar una nueva matriz.\n");
    printf("Presione 'i' para saltar hasta la generación terminal.\n");
    printf("Presione ENTER por saltar una generación.\n");
    printf("Presione la cantidad de generaciones que quiera saltar (max. 65535) y luego ENTER para saltar dicha cantidad de generaciones.\n");
    printf("Presione 'f' para finalizar el juego.\n");
}

int comparison (int mat[][MAT_SIZE],int mat2[][MAT_SIZE], int filas, int columnas)
{
    int equal=EQUAL;

    for (int i=0; i< filas; i++)                // Recorro filas.
    {
        for (int j = 0; j < columnas; j++)      // Recorro columnas.
        {
            if(mat[i][j]!=mat2[i][j])
            {
                equal=NOTEQUAL;
            }
        }
        
        if (equal==NOTEQUAL)
        {
            break;
        }
    }
    return  equal;
}

