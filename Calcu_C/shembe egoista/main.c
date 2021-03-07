#include <stdio.h>
#include "math.h"
#include "const.h"
#include "lectura.h"

#define MAX_OPERATORS 6

//Funcion que agrega las direcciones de las funciones de las operaciones en un arreglo
static void add_operation(char o, float (*a) (float, float, int* ));
//Ejecuta la operacion
static float calc_res(float x, float y, char op, int* error);

//Globals
static char operators[MAX_OPERATORS]; //  = {'+', '-', '*'}; ARREGLO donde se guardan los caracteres ascii de los operadores

static float (* actions [MAX_OPERATORS] ) (float, float, int* );  // = {add, sub, mult};  ARREGLO DE PUNTEROS A FUNCION QUE DEVUELVE FLOAT Y SUS ENTRADAS SON (FLOAT, FLOAT, INT)
//End globals



int main(void)
{

    add_operation(OP_MULTI, multip);            //Agrego operaciones
    add_operation(OP_RESTA, subst);
    add_operation(OP_EXP, expo);
    add_operation(OP_SUMA, sum);
    add_operation(OP_DIV, divi);

//    printf("%f\n", (*actions[0])(10,5) );
//    printf("%f\n", (*actions[1])(10,5) );

    float x;
    float y;
    char oprador;
    int errorDetect = 0;
    float result;
    while(1)
    {
        lect(operators, &x, &y, &oprador);
        result = calc_res(x, y, oprador, &errorDetect);
        if(errorDetect == 0)
        {
            printf("RESULTADO: %f\n", result);
        }
        else
        {
            switch(errorDetect)
            {
                case DIV_0X0:
                    printf("ERROR EN LA OPERACION: DIVISION POR CERO\n");
                break;
                case DECIMAL_EXP:
                    printf("ERROR EN LA OPERACION: DECIMAL EXPONENT\n");
                break;
            }
            errorDetect = 0;
        }
        
    }


}

float calc_res(float x, float y, char op, int* error)
{
    int i = 0;
    float result = 0;
    while(operators[i] != op && i < MAX_OPERATORS)  //busco en el arreglo que contiene los caracteres asccii, el caracter asociado con la operacion
    {
        i++;
    }

    result = (*actions[i])(x, y, error);        //Aprovecho el valor de i, para ejecutar la operacion.
    
    return result;    
}

void add_operation(char o, float (*a) (float, float, int *))
{
    int i = 0;
    while(operators[i] != 0)        //BUSCO UN ESPACIO LIBRE PARA PODER GUARDAR EL CARACTER OPERADOR EN EL ARREGLO QUE CONTIENE LOS ASCII DE OPERADORES
    {
        i++;
    }
    operators[i] = o;   

    actions[i] = a;                 //Utilizo la misma variable para posicionar la direccion de memoria de la funcion de la operacion matematica.

}
