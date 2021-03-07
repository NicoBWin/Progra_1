#include <stdio.h>

#define MAT_SIZE	100
#define ALIVE   	1   	// Constantes para los estados de las células
#define DEAD		0       

#define CHAROFFSET  '0'

#define CORRIENDO   1       // Constantes que establecen el estado de la máquina
#define APAGADO     0       //de estados.

#define EQUAL       1       // Constantes que indican si una matriz es igual a 
#define NOTEQUAL    0       // otra o no.

#define ERROR       1       // Constantes que representan diferentes errores al 
#define ERROR_MAT   -1      //cargar la matriz.

#define RESETMAT    1       // Constantes que representan si es o no necesario
#define NORESETMAT  0       //resetear la matriz.

#define GENLIMIT    100     // Cantidad de generaciones máxima hasta encontrar la matriz terminal.

enum CARGAMOS {FILAS, COLUMNAS, MATRIZ};                                // Constante que representa que tipo de dato estamos cargando de la consola.
enum STATES {NUMERO, ENTER='\n', FIN='q', TERMINAL='i', CARGA='l'};     // Diferentes estados del menú.

void welcome (void);
// printf's de la introducción inicial.

int load (int cargando, int mat [][MAT_SIZE], int row, int col);
// Gestiona la entrada de datos según lo que se ingrese.

unsigned int lectNum(void);
//Carga los numeros de fila y columna de la matriz 

void lectMat (int mat [][MAT_SIZE], int row, int col);
//Carga los valores en la matriz.

int lectChar (int col, int reset);
//Analiza los caracteres ingresados a la hora de cargar la matriz.

void loadingInstructor();
//printf's con las instrucciones para cargar la matriz.

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

void showResult(int mat[][MAT_SIZE],int filas, int columnas);
// Muestra esteticamente por consola mat[][].

void cleanBuffer();
// Limpia todo el contenido del buffer.

void pressKey();
// printf's de los comandos a utilizar.

int comparison(int mat[][MAT_SIZE],int mat2[][MAT_SIZE], int filas, int columnas);
// Determina cuando todos los elementos de mat son iguales a los de mat2.



int main ()
{
	int filas=0, col=0;
    int mat[MAT_SIZE][MAT_SIZE];

    welcome();                                  // Muestro el mensaje de bienvenida.

    int cargando = FILAS;           
    filas = load(cargando, mat, filas, col);    // Comienzo cargando por consola el numero de filas.

    cargando = COLUMNAS;
    col = load(cargando, mat, filas, col);      // Cargo el numero de columnas.

    cargando = MATRIZ;
    load(cargando, mat, filas, col);            // Cargo la matriz.
   
    pressKey();                                 // Muestro que comandos se pueden ejecutar.
    menu(mat, filas, col);                      // Dependiendo del comando solicitado, actuo.
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

int load(int cargando, int mat [][MAT_SIZE], int row, int col)
{
    if (cargando==FILAS)
    {
        int filas = 0;                                            

        do                                                                  
        {
		    printf ("Ingrese una cantidad de filas menor a %d:\n", MAT_SIZE+1);  // Si estoy cargando cant de filas, leo la cantidad ingresada por
		    filas= lectNum();                                                       //consola y la devuelvo si es un valor válido.
	    }
	    while (filas>MAT_SIZE);
        return  filas;   
    }
    
    else if (cargando==COLUMNAS)
    {
        int cols=0;                                          // Si estoy cargando cant de columnas, leo la cantidad ingresada por
        do                                                   //consola y la devuelvo si es un valor válido.
        {
		    printf ("Ingrese una cantidad de columnas menor a %d:\n", MAT_SIZE+1);
		    cols= lectNum();
	    }
	    while (cols>MAT_SIZE);
        return  cols;
    }

    else if (cargando==MATRIZ)
    {
        lectMat(mat, row, col);                             //sea correcta y lo guardo en una matriz.
        printf ("\n\n\n La matriz cargada fue:\n");         
        showResult (mat, row, col);                         // Para mejor experiencia de usuario, muestro la matriz cargada.
        
    }
    return 0;
}

unsigned int lectNum(void)
{
	int c=0;								 	//Caracter ingresado.	
	unsigned int num=0;                         // Cuenta parcial del numero ingresado.
	int error=0;
	do
    {
		error = 0;
		while ( error!= ERROR && (c=getchar()) != '\n')           //Mientras que no apriete enter ni se encuentre error
        {	
			if (c>='0' && c<='9')
            {					
			    num=num*10+ c - CHAROFFSET;				//Si el numero es entero, lo multiplico por	
				    									//10 y le sumo el siguiente (para conformar
			}		    								//el numero)
			else 
            {
				error=ERROR;							// Si no, es un caracter erroneo y pido que vuelva a ingresar el numero.
				printf ("Cantidad erronea, por favor vuelva a ingresarla:\n");	
                cleanBuffer();		
			}
		}
		if (num==0 && error!=ERROR)
        {
			error=ERROR;								                        // Si primero ingresaste un enter o solo ingresaste un 0
			printf ("Cantidad erronea, por favor vuelva a ingresalarla:\n");    //pido que vuelva a ingresar el numero.
            
            if(c!='\n')
            {
                cleanBuffer();
            }
        }
	}
	while (error==ERROR);       // Repetir todo el bucle hasta que se haya ingresado un valor válido.
	return num;
}

void lectMat (int mat [][MAT_SIZE], int row, int col)
{
	loadingInstructor();                        // Indico las instrucciones de carga de matriz.
    int reset=RESETMAT;                         
	for (int i=0; i<row; i++)
    {
		for (int j=0; j<col; j++)
        {				
			mat [i][j]= lectChar (col, reset);  // Cargo los valores ij de la matriz.
			reset=NORESETMAT;
			if (i==row-1 && j==col-1){          // Si la matriz no termina con un ENTER.
				if (getchar()!='\n')            //Reinicio la carga de la matriz.
                {					
					i=0;
					j=-1;
					cleanBuffer();
					printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
					reset=RESETMAT;
				}
			}
			if (mat [i][j]==ERROR_MAT){			//Si es un caracter no deseado
				i=0;                            //reinicio la escrtiura de matriz
				j=-1;                           //termino de leer la "basura" restante hasta completar la fila.		
			}
			
		}
	}
}

int lectChar (int col, int reset)
{
	int c;											// Caracter leído.	
	int a=0;                                        // Estado de la celula.
	static int cont=-1;                             // Contador de celulas cargadas por fila.
	
    if (reset==RESETMAT)
    {
		cont=-1;                                    // Si necesito empezar de cero reinicio el contador
	}
	
    cont++;                                         // Por cada caracter leído, incremento el contador de celulas cargadas por fila. 
    do
    {
		c=getchar();
		
        if (c== '*' || c== 'A' || c== '1')
        {                                       //Si la celula esta viva
			a=ALIVE;							//coloco un 1.
		}
		
        else if  (c== ' ' || c== 'D' || c== '0')
        {                                          	//Si la celula esta muerta
			a=DEAD;									//coloco un 0.
		}
		
        else if (c=='\n')
        {
			if (cont<col)                           // Si se cargaron menos celulas de las que deberían
            {                                       //aviso por consola y reseteo la carga de matriz.
				c= ERROR_MAT;
				a= ERROR_MAT;
				printf ("Faltan valores para completar la fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}
			else if (cont>col)                          // Si se cargaron más celulas de las que deberían
            {                                           //aviso por consola y reseteo la carga de matriz.
				c=ERROR_MAT;
				a=ERROR_MAT;
				printf ("Se excedio de la cantidad de valores por fila. Por favor vuelva a ingresar el tablero.\n");
				cont=-1;
			}	
			else
            {
				cont=0; 
			}
		}
		else
        {
			printf ("El caracter ingresado fue erróneo. Por favor vuelva a ingresar el tablero.\n");
			a=ERROR_MAT;									//  Si se ingreso un caracter no deseado,
			cont=-1;                                        //que vuelva a ingresar la matriz e 
            cleanBuffer();                                 //ignoro todos los datos siguientes.
		}		
	}
	while (c == '\n');                                      //  Repito el bucle hasta que encuentre el caracter terminador "\n"
	
	return a;
}	

void loadingInstructor ()
{
    printf ("Ingrese el tablero fila por fila.\n");
	printf("Las  celulas vivas se pueden ingresar como '1', '*' o 'A' (Alive).\n");
    printf("Las  celulas muertas se pueden ingresar como '0', ' ' (espacio) o 'D' (Dead).\n"); 
    printf ("Al terminar de cargar una fila, persione ENTER.\n");
}

void menu(int mat[][MAT_SIZE], int fils, int cols)
{
    int juego = CORRIENDO;
    int generaciones=0;         // Variable que indica la cantidad de generaciones a saltar.
    int filas = fils;           // Creo una variable filas para poder modificar desde el menu el tamaño de la matriz.
    int columnas = cols;        // Creo una variable columnas para poder modificar desde el menu el tamaño de la matriz.

    while (juego == CORRIENDO)          // Mientras que no aprete 'q', me quedo en el bucle esperando que me indiquen las generaciones.
    {
        int comando=getchar();
        int num=comando-CHAROFFSET;     
        int mat2[MAT_SIZE][MAT_SIZE];   // Matriz que contiene la generacion anterior.
        int equals;                     // Variable que indica si la generacion anterior es igual a la actual.
        unsigned int cont_generaciones = 0; // Variable que indica la cantidad de generaciones entre la terminal y la inicial. 

        if(num>=0 && num<=9)
        {
            comando=NUMERO;             // Si el caracter es númerico, corrijo para que comando sea modo numerico.
        }
    
        switch (comando)
        {
            case NUMERO:
                generaciones = generaciones*10+num;    // Si comando es un numero, actualizo el numero de generaciones a correr.
                break;

            case ENTER:
                if (generaciones!=0)        //  a) Si ingrese ningún número 'n', salto 'n' generaciones.  
                {
                    newGeneration(mat, filas, columnas, generaciones);
                    generaciones=0;
                    printf("Matriz resultante:\n");
                    showResult(mat, filas, columnas);
                    pressKey();
                }
                else            //  b) Si no ingrese ningún número, salto una sola generación.
                {
                    newGeneration(mat, filas, columnas, 1);    
                    printf("Matriz resultante:\n");
                    showResult(mat, filas, columnas);
                    pressKey();
                }
                break;

            case FIN:
                juego = APAGADO;                        // Si se apretó "q", salgo del bloque menú modificando la variable juego.
                printf("\n\n\n\n\nHa salido del juego, esperamos que se haya divertido.\n");
                break;
            
            case TERMINAL:
                
                cont_generaciones = 0;                  // Reinicio la variable que indica la cantidad de generaciones entre la terminal y la inicial.
                do
                {
                    cont_generaciones++;                        // Por cada nueva generacion incremento cont_generaciones.
                    copyMat(mat, mat2, filas, columnas);        // Hago backup de la generación anterior.
                    newGeneration(mat, filas, columnas, 1);     // Genero la nueva generación.

                    equals = comparison(mat ,mat2, filas, columnas);    // Reviso si las matrices son iguales.
                    
                    if (equals==EQUAL)                                  // Si las matrices son iguales,
                    {                                                   //muestro la matriz terminal e indico en
                                                                        //cuantas generaciones se llegó.

                        printf("\nSe llega a la matriz terminal en %u generaciones, o sea,\n", cont_generaciones-1);
                        printf("nada se modifica despues de la generación %u.\n", cont_generaciones);
                        printf("\nMatriz resultante:\n");
                        showResult(mat, filas, columnas);
                    }
                } while (equals==NOTEQUAL && cont_generaciones < GENLIMIT);

                if (equals==NOTEQUAL)                                   // Si no se llegó a una matriz terminal,
                {                                                       //lo informo por consola.
                    printf ("No se encontró a la matriz terminal en %u generaciones.\n :( \n", GENLIMIT);
                }

                cleanBuffer();                              // Limpio el buffer para comenzar correctamente.
                pressKey();                                 // Indico los comandos admisibles.
                break;

            case CARGA:
                cleanBuffer();

                int cargando = FILAS;                           
                filas = load(cargando, mat, filas, columnas);   // Cargo cantidad de filas.
                cargando = COLUMNAS;
                columnas = load(cargando, mat, filas, columnas);    // Cargo cantidad de columnas.
                cargando = MATRIZ;
                load(cargando, mat, filas, columnas);           // Llamo a la función que me carga la matriz.

                pressKey();                                     // Indico los comandos admisibles.
                break;

            default:
                printf("Ingrese un comando válido.\n");    // Si no se apreto ningun comando reconocible:
                cleanBuffer();                          // lo indico por consola y aviso cuales son los 
                break;                                  // comandos admisibles.
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

void cleanBuffer()
{  
    while (getchar() != '\n');
}

void pressKey()
{
    printf("\nPresione 'l' para cargar una nueva matriz.\n");
    printf("Presione 'i' para saltar hasta la generación terminal.\n");
    printf("Presione ENTER por saltar una generación.\n");
    printf("Presione la cantidad de generaciones que quiera saltar (Números naturales) y luego ENTER para saltar dicha cantidad de generaciones.\n");
    printf("Presione 'q' para salir del juego.\n");
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
                equal=NOTEQUAL;                 // En cuanto encuentro una casilla distinta 
            }                                   //aviso que las matrices son distintas.
        }
        
        if (equal==NOTEQUAL)
        {
            break;
        }
    }
    return  equal;
}
