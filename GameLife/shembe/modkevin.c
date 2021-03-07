#include <stdio.h>
#define J_SIZE 20
#define ERR_world -1
#define ERR	1
#define ALIVE 1
#define DEAD 0
void lect_world (int world [][J_SIZE], int, int);
int lect_char (int, int);
unsigned int lect (void);
void lect_basura (void);

int main(void){
	int i_RealSize;
	int j_realSize;
	printf ("Ingrese la cantidad de filas:\n");
	i_RealSize = lect();

	do{
		printf ("Ingrese la cantidad de columnas menor a %d:\n", J_SIZE);
		j_realSize= lect();
	}
	while (j_realSize>J_SIZE);
	int world[i_RealSize][J_SIZE];
	lect_world (world, i_RealSize, j_realSize);
	for (int i=0; i<i_RealSize; i++){
		for (int j=0; j<j_realSize; j++){
			printf ("%d", world [i][j]);
		}
		printf ("\n");
	}
}	

int lect_char (int j_realSize, int reset){
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
			a=ALIVE;							//j_realSizeoco un 1
		}
		else if  (c== ' ' || c== 'D' || c== '0'){	//si la celula esta muertaa
			a=DEAD;									//j_realSizeoco un 0
		}
		else if (c=='\n'){
			if (cont<j_realSize){
				c= ERR_world;
				a= ERR_world;
				printf ("Faltan valores para completar la fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}
			else if (cont>j_realSize){
				c=ERR_world;
				a=ERR_world;
				printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}	
			else{
				cont=0;
			}
		}
		else {
			printf ("El caracter ingresado fue erroneo. Por favor vuelva a ingresar el tablero.\n");
			a=ERR_world;									//si es un caracter no deseado, que vuelva a ingresar la worldriz
			cont=-1;
			lect_basura ();
		}		
	}
	while (c == '\n');
	
	return a;
}	

void lect_world (int world [][J_SIZE], int i_RealSize, int j_realSize){			//carga los valores en la worldriz
	printf ("Ingrese el tablero.\nLas  celulas vivas se pueden ingresar como '1', '*' o 'A' (Alive).\nLas  celulas muertas se pueden ingresar como '0', ' ' (espacio) o 'D' (Dead).\n");
	int reset=0;
	for (int i=0; i<i_RealSize; i++){
		for (int j=0; j<j_realSize; j++){				
			world [i][j]= lect_char (j_realSize, reset);
			reset=0;
			if (i==i_RealSize-1 && j==j_realSize-1){
				if (getchar()!='\n'){					
					i=0;
					j=-1;
					lect_basura();
					printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
					reset=1;
					
				}
			}
			//printf ("[%d][%d]=%d\n", i, j, world[i][j]);
			if (world [i][j]==ERR_world){			//si es un caracter no deseado
				i=0;
				j=-1;
										//reinicio la escrtiura de worldriz
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
				a=a*10+c-'0';					//si el numero es entero, lo multiplico por	
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