#define OFFSET 48
#include <stdio.h>
#define N 20
#define ERR_MAT -1
#define ERR	1
#define ALIVE 1
#define DEAD 0
void lect_mat (int mat [][N], int, int);
int lect_char (int, int);
unsigned int lect (void);
void lect_basura (void);

int main(void){
	int row;
	int col;
	printf ("Ingrese la cantidad de filas:\n");
	row= lect();

	do{
		printf ("Ingrese la cantidad de columnas menor a %d:\n", N);
		col= lect();
	}
	while (col>N);
	int mat [row][N];
	lect_mat (mat, row, col);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			printf ("%d", mat [i][j]);
		}
		printf ("\n");
	}
}	

int lect_char (int col, int reset){
	int c;											//character	
	int a=0; 
	static int cont=-1;
	if (reset==1){
		cont=-1;
	}
	cont++;
	do{
		c=getchar();
		if (c== '*' || c== 'A' || c== '1'){ //Si la celula esta viva
			a=ALIVE;							//coloco un 1
		}
		else if  (c== ' ' || c== 'D' || c== '0'){	//si la celula esta muertaa
			a=DEAD;									//coloco un 0
		}
		else if (c=='\n'){
			if (cont<col){
				c= ERR_MAT;
				a= ERR_MAT;
				printf ("Faltan valores para completar la fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}
			else if (cont>col){
				c=ERR_MAT;
				a=ERR_MAT;
				printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}	
			else{
				cont=0;
			}
		}
		else {
			printf ("El caracter ingresado fue erroneo. Por favor vuelva a ingresar el tablero.\n");
			a=ERR_MAT;									//si es un caracter no deseado, que vuelva a ingresar la matriz
			cont=-1;
			lect_basura ();
		}		
	}
	while (c == '\n');
	
	return a;
}	

void lect_mat (int mat [][N], int row, int col){			//carga los valores en la matriz
	printf ("Ingrese el tablero.\nLas  celulas vivas se pueden ingresar como '1', '*' o 'A' (Alive).\nLas  celulas muertas se pueden ingresar como '0', ' ' (espacio) o 'D' (Dead).\n");
	int reset=0;
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){				
			mat [i][j]= lect_char (col, reset);
			reset=0;
			if (i==row-1 && j==col-1){
				if (getchar()!='\n'){					
					i=0;
					j=-1;
					lect_basura();
					printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
					reset=1;
					
				}
			}
			//printf ("[%d][%d]=%d\n", i, j, mat[i][j]);
			if (mat [i][j]==ERR_MAT){			//si es un caracter no deseado
				i=0;
				j=-1;
										//reinicio la escrtiura de matriz
										//termino de leer la "basura" restante hasta completar la fila
				
			}
			
		}
	}
}

unsigned int lect (void){
	int c=0;										//character	
	unsigned int a=0; 
	int error=0;
	do{
		error = 0;
		while ((c=getchar()) != '\n'){	//mientras que no apriete enter
			if (c>='0' && c<='9'){					
				a=a*10+c-OFFSET;					//si el numero es entero, lo multiplico por	
													//10 y le sumo el siguiente (para conformar
			}										//el numero)
			else {
				error=ERR;							// si no, es un caracter erroneo
				printf ("Cantidad erronea, por favor vuelva a ingresala:\n");			
			}
		}
		if (a==0 && error!=ERR){
				error=ERR;								// si primeroingresaste un enter o solo ingresaste un 0
				printf ("Cantidad erronea, por favor vuelva a ingresala:\n");
		}
	}
	while (error==ERR);
	return a;
}

void lect_basura (void){
	int c=0;										//character	 
	while ((c=getchar()) != '\n'){	//mientras que no apriete enter
		//
	}
	
	
}

/*
void lect_mat (double mat [][], int row, int col){			//carga los valores en la matriz
	for (int i=0; i<row; i++){
		for (int j=0; int c=getchar(); c!='\n'; j++){				
			mat [i][j]= c;
			
		}
	}
}
*/

