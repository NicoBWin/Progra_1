#include <stdio.h>
#define I_SIZE 10           
#define J_SIZE 8
#define QPRESS -2
#define ENTERPRESS -1
#define ERROR -3

void outputWorld(int world[][J_SIZE]);
void finalizeEvolution(int world[][J_SIZE], int nextWorld[][J_SIZE]);
int getCellState(int world[][J_SIZE], int i, int j);
void setCellState(int nextWorld[][J_SIZE], int i, int j, int state);
int checkRange(int, int);
int aroundCell(int world[][J_SIZE], int i, int j);
void calculateNext(int world[][J_SIZE], int nextWorld[][J_SIZE]);
void initialitazion(int world[][J_SIZE]);
int getNumber(void);
void cleanWorld(int world[][J_SIZE]);

                                        
int main(void)
{
    int world[I_SIZE][J_SIZE];
    int nextWorld[I_SIZE][J_SIZE];

    int counter=0;
    int ingresado;
    cleanWorld(world);
    cleanWorld(nextWorld);      //ESTE CLEAN A NEXTWORLD CREO QUE ES ALPEDO PERO POR SI ACASO
    do
    {
        printf("Bienvenido!!!!!!!\n");
        initialitazion(world);

        do
        {
            do
            {
                printf("\nIngrese lo que quiere hacer\n");
                ingresado = getNumber();
            }while(ingresado == ERROR);


            if(ingresado!=QPRESS  && ingresado!=ENTERPRESS)
            {
                while(counter < ingresado)
                {
                    calculateNext(world, nextWorld);
                    finalizeEvolution(world, nextWorld);
                    counter++;
                }
                counter = 0;
                outputWorld(world);   

            }
            else if(ingresado==ENTERPRESS && ingresado!=QPRESS )
            {
                calculateNext(world, nextWorld);
                finalizeEvolution(world, nextWorld);
                outputWorld(world);
                
            }

        }
        while(ingresado != QPRESS);

    } 
    while(ingresado == QPRESS);

}
void initialitazion(int world[][J_SIZE])
{
    cleanWorld(world);
    printf("ASI ESTA EL MUNDO ACUTALMENTE\n");
    world[2][1] = 1;      //TESTEO
    world[1][3] = 1;
    world[3][3] = 1;
    world[2][3] = 1;
    world[3][2] = 1;
    outputWorld(world);
}

void calculateNext(int world[][J_SIZE], int nextWorld[][J_SIZE])
{
    int adjacent;
    int cellState;
    for(int i=0; i < I_SIZE; i++)
    {
        for(int j = 0; j < J_SIZE; j++)
        {
            cellState = getCellState(world, i, j);
            adjacent = aroundCell(world, i, j);

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
        }
    }
}

int checkRange(int i, int j) //ANIDADA SOLO EN AROUNDCELL()
{
    int ok = 1;
    if( !((i >= 0 && i < I_SIZE) && (j >= 0 && j < J_SIZE)) )
    {
        ok = 0;        
    }
    return ok;  
}

int aroundCell(int world[][J_SIZE], int i, int j)
{
    int adjacent = 0;
    int ok;

    for(int varI = i - 1; varI < i + 2; varI++)
    {
        for(int varJ = j - 1; varJ < j + 2; varJ++)
        {
            if(!(varI == i && varJ == j))
            {
                ok = checkRange(varI,varJ);
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

void outputWorld(int world[][J_SIZE])
{
    
    for(int i = 0; i < I_SIZE; i++)
    {
        printf("\n");
        printf("|");
        for(int j = 0; j < J_SIZE; j++)
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

void finalizeEvolution(int world[][J_SIZE], int nextWorld[][J_SIZE])
{
    for(int i = 0; i < I_SIZE; i++)
    {
        for(int j = 0; j < J_SIZE; j++)
        {
            world[i][j] = nextWorld[i][j];
        }
    }
    for(int i = 0; i < I_SIZE; i++)
    {
        for(int j = 0; j < J_SIZE; j++)
        {
            nextWorld[i][j] = 0;
        }
    }
}

int getNumber(void){

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
            ingresado = -3;
        }

    return ingresado;
}

void cleanWorld(int world[][J_SIZE])
{
    for(int i = 0; i<I_SIZE;i++)
    {
        for(int j = 0; j<J_SIZE;j++)
        {
            world[i][j] = 0;
        }
    }
}
