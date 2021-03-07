#include <stdio.h>
#define J_SIZE 40
#define QPRESS -2
#define ENTERPRESS -1
#define ERROR -3

//#################################################### KEVIN DECLARACIONES ALGUNAS CAMBIADAS 
#define ERR_world -1
#define ERR	1
#define ALIVE 1
#define DEAD 0
void lect_world (int world [][J_SIZE], int, int);
int lect_char (int, int);
unsigned int lect (void);
void lect_basura (void);
//####################################################para todo epsilon > 0


void outputWorld(int world[][J_SIZE], int i_RealSize, int j_RealSize);
void finalizeEvolution(int world[][J_SIZE], int nextWorld[][J_SIZE],  int i_RealSize, int j_RealSize);
int getCellState(int world[][J_SIZE], int i, int j);
void setCellState(int nextWorld[][J_SIZE], int i, int j, int state);
int checkRange(int, int, int i_RealSize, int j_RealSize);
int aroundCell(int world[][J_SIZE], int i, int j, int i_RealSize, int j_RealSize);
void calculateNext(int world[][J_SIZE], int nextWorld[][J_SIZE], int i_RealSize, int j_RealSize);
void initialitazion(int world[][J_SIZE], int i_RealSize, int j_RealSize);
int getNumber(void);
void cleanWorld(int world[][J_SIZE], int i_RealSize, int j_RealSize);

                                        
int main(void)
{
    int i_RealSize;
    int j_RealSize;

    int ingresado;

    do
    {
        printf("Bienvenido!!!!!!!\n");

//################################################### KEVIN PART

        printf ("Ingrese la cantidad de filas:\n");
        i_RealSize = lect();

        do{
            printf ("Ingrese la cantidad de columnas menor a %d:\n", J_SIZE);
            j_RealSize= lect();
        }
        while (j_RealSize>J_SIZE);
        int world[i_RealSize][J_SIZE];
        int nextWorld[i_RealSize][J_SIZE];
        lect_world (world, i_RealSize, j_RealSize);
        printf("\n");
        for (int i=0; i<i_RealSize; i++){
            for (int j=0; j<j_RealSize; j++){
                printf ("%d", world[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");
        outputWorld(world,  i_RealSize, j_RealSize);
             
//######################################################
        do
        {
            do
            {
                printf("\nIngrese lo que quiere hacer\n");
                ingresado = getNumber();
            }while(ingresado == ERROR);


            if(ingresado!=QPRESS  && ingresado!=ENTERPRESS)
            {
                int counter = 0;
                while(counter < ingresado)
                {
                    calculateNext(world, nextWorld, i_RealSize, j_RealSize);
                    finalizeEvolution(world, nextWorld, i_RealSize, j_RealSize);
                    counter++;
                }

                outputWorld(world,  i_RealSize, j_RealSize);  

            }
            else if(ingresado==ENTERPRESS && ingresado!=QPRESS )
            {
                calculateNext(world, nextWorld, i_RealSize, j_RealSize);
                finalizeEvolution(world, nextWorld, i_RealSize, j_RealSize);
                outputWorld(world, i_RealSize, j_RealSize);
                
            }

        }
        while(ingresado != QPRESS);

    } 
    while(ingresado == QPRESS);

}
void initialitazion(int world[][J_SIZE], int i_RealSize, int j_RealSize)
{
    cleanWorld(world, i_RealSize, j_RealSize);
    printf("ASI ESTA EL MUNDO ACUTALMENTE\n");
    world[2][1] = 1;      //TESTEO
    world[1][3] = 1;
    world[3][3] = 1;
    world[2][3] = 1;
    world[3][2] = 1;
    outputWorld(world, i_RealSize, j_RealSize);
}

void calculateNext(int world[][J_SIZE], int nextWorld[][J_SIZE], int i_RealSize, int j_RealSize)
{
    int adjacent;
    int cellState;
    for(int i=0; i < i_RealSize; i++)
    {
        for(int j = 0; j < j_RealSize; j++)
        {
            cellState = getCellState(world, i, j);
            adjacent = aroundCell(world, i, j, i_RealSize, j_RealSize);

            if(cellState && adjacent < 2 )      //A_ Una celula viva con menos de dos vecinos muere
            {
                setCellState(nextWorld, i, j, 0);
            }
            else if(cellState && adjacent > 3)  //  b) una célula con más de tres vecinos también muere;
            {
                setCellState(nextWorld, i, j, 0);
            }
            else if(cellState && ( adjacent == 2 || adjacent == 3 ) )   // c) una célula viva con exactamente dos o tres vecinos sobrevive;
            {
                setCellState(nextWorld, i, j, 1);
            }
            else if(!cellState && adjacent == 3)   //d) una célula muerta con exactamente tres vecinos obtiene vida nuevamente.
            {
                setCellState(nextWorld, i, j, 1);
            }
            else if(!(!cellState && adjacent == 3))
            {
                setCellState(nextWorld, i, j, 0);   //sigue muerta    
            }
        }
    }
}

int checkRange(int i, int j, int i_RealSize, int j_RealSize) //ANIDADA SOLO EN AROUNDCELL()
{
    int ok = 1;
    if( !((i >= 0 && i < i_RealSize) && (j >= 0 && j < j_RealSize)) )
    {
        ok = 0;        
    }
    return ok;  
}

int aroundCell(int world[][J_SIZE], int i, int j, int i_RealSize, int j_RealSize)
{
    int adjacent = 0;
    int ok;

    for(int varI = i - 1; varI < i + 2; varI++)
    {
        for(int varJ = j - 1; varJ < j + 2; varJ++)
        {
            if(!(varI == i && varJ == j))
            {
                ok = checkRange(varI,varJ, i_RealSize, j_RealSize);
                if(ok)                      //SI no esta OK no suma nada por que las celulas de afuer estan muertas
                {
                    adjacent += world[varI][varJ];
                }
            }
        }
    }
    return adjacent;
}

void setCellState(int nextWorld[][J_SIZE], int i, int j, int state)
{
    if(state)
    {
        nextWorld[i][j] = 1;
    }
    else
    {
        nextWorld[i][j] = 0;
    }
}

int getCellState(int world[][J_SIZE], int i, int j)
{
    int state = world[i][j];
    return state;
}

void outputWorld(int world[][J_SIZE], int i_RealSize, int j_RealSize)
{
    
    for(int i = 0; i < i_RealSize; i++)
    {
        printf("\n");
        printf("|");
        for(int j = 0; j < j_RealSize; j++)
        {
            if(world[i][j])
            {
                printf("*|");
            }
            else
            {
                printf(" |");
            }
        }      
    }
}

void finalizeEvolution(int world[][J_SIZE], int nextWorld[][J_SIZE], int i_RealSize, int j_RealSize)
{
    for(int i = 0; i < i_RealSize; i++)
    {
        for(int j = 0; j < j_RealSize; j++)
        {
            world[i][j] = nextWorld[i][j];
        }
    }
    for(int i = 0; i < i_RealSize; i++)
    {
        for(int j = 0; j < j_RealSize; j++)
        {
            nextWorld[i][j] = 0;
        }
    }
}

int getNumber(void)
{

    int ingresado = 0;
    char chequeo;
    int qCounter = 0;
    int length = 0;
   
    int error = 0;

    chequeo = getchar();

    if(chequeo =='\n' && !length)       //Si es enter devuelvo -1
    {
        
        ingresado = -1;                 //Magic number
    }
    else
    {
        while(chequeo != '\n')
        {
            if(chequeo == 'q')
            {
                if(!qCounter)
                {
                    ingresado = -2;
                    qCounter = 1;
                }
                else
                {
                    error = 1;
                }
            }
            else if(chequeo < '0' || chequeo > '9')
            {
                error = 1;
            }
            else
            {
                ingresado = ingresado*10 + chequeo - '0';

                if(qCounter)
                {
                    error = 1;
                }  
            }   
            length++;
            chequeo = getchar();
        }        
    }       
        if(error)
        {
            ingresado = -3;  //Magic number
        }

    return ingresado;
}

void cleanWorld(int world[][J_SIZE], int i_RealSize, int j_RealSize)
{
    for(int i = 0; i<i_RealSize;i++)
    {
        for(int j = 0; j<j_RealSize;j++)
        {
            world[i][j] = 0;
        }
    }
}

//###########################################################################

int lect_char (int j_RealSize, int reset){
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
			a=ALIVE;							//j_RealSizeoco un 1
		}
		else if  (c== ' ' || c== 'D' || c== '0'){	//si la celula esta muertaa
			a=DEAD;									//j_RealSizeoco un 0
		}
		else if (c=='\n'){
			if (cont<j_RealSize){
				c= ERR_world;
				a= ERR_world;
				printf ("Faltan valores para completar la fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}
			else if (cont>j_RealSize){
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

void lect_world (int world [][J_SIZE], int i_RealSize, int j_RealSize){			//carga los valores en la worldriz
	printf ("Ingrese el tablero.\nLas  celulas vivas se pueden ingresar como '1', '*' o 'A' (Alive).\nLas  celulas muertas se pueden ingresar como '0', ' ' (espacio) o 'D' (Dead).\n");
	int reset=0;
	for (int i=0; i<i_RealSize; i++){
		for (int j=0; j<j_RealSize; j++){				
			world [i][j]= lect_char (j_RealSize, reset);
			reset=0;
			if (i==i_RealSize-1 && j==j_RealSize-1){
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