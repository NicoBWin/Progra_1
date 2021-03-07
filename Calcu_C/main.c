/***************************************************************************//**
  @file     +main.c+
  @brief    +Archivo principal del programa+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include  <stdio.h>

#include "const.h"
#include "lectura.h"
#include "math.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static void welcome(void);    // Imprime mensaje de bienvenida
static void inicializar(void);  // Inicializacion de los operadores
static void add_operation(char op, double (*func)(double,double,int*)); // Función que agrega operaciones a los arreglos
static int continuar(void);   // Funcion que pregunta al usuario si desea continuar
static int getindexOf(char c, char arr[], int size);  // Devuelve la primer posición de un caracter en un arreglo.

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static char operandos[OPMAX];              // Guarda los operandos matemáticos admitidos
static double (*func[OPMAX])(double,double,int*);   // Guarda las direcciones de las fuciones matemáticas

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

int main ()
{
  double num1, num2, res;
  char operador;
  int error = N_ERR;
  welcome();
  inicializar();
  
  do
  {
    lect(operandos, &num1, &num2, &operador);
    int i = getindexOf(operador, operandos, ARRSIZE(operandos));  // Busco el índice del operador
    res = func[i](num1, num2, &error);    // Guardo el resultado de la operación
    
    if (error == N_ERR)   // Calculo exitoso
    {
      printf("\t%f\t%c\t%f\t=\t%f\n",num1, operador, num2, res);    // Impresión del resultado
    }
    else if (error == E_OVF)  // Error de overflow
    {
      PRINT_ERROR("El resultado es demasiado grande. Intente con otra cuenta\n");
    }
    else if (error == E_DIV)  // Error de división por cero
    {
      PRINT_ERROR("No se puede dividir por cero! Ingrese una cuenta valida\n");
    }
    else if (error == E_POT)  // Error de potencia no entera
    {
    PRINT_ERROR("No se puede elevar a potencias no enteras! Intente con otro numero.");
    }
    else 	// Otro error (no deberia entrar aca nunca)
	{    
    PRINT_ERROR("Ocurrió un error inesperado. Vuelva a ingresar la cuenta.");
    }
    
  } while (error != N_ERR || continuar());  // Se repite mientras haya error o el usuario quiera
  
  printf("Gracias por utilizar la calculadora del Grupo 3.\n\n");   // Mensaje de despedida
  
  return OK;
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
 //Muestra la pantalla de inicio
static void welcome() 
{
	printf("*************************************************************************\n");
	printf("*\t\t Bienvenidos a la calculadora del Grupo 3 \t\t*\n");
	printf("*\tEl uso de esta calculadora esta dada por dos operandos y\t*\n");
	printf("*\tuna operacion, a modo de ejemplo: op1+op2. Los numeros  \t*\n");
	printf("*\tpueden ser decimales (con coma(,) o punto(.))\t\t\t*\n");
	printf("*\tLas operaciones validas son suma(+), resta(-), division(/), \t*\n");
	printf("*\tmultiplicacion(*) y potencia(^).\t\t\t\t*\n");
	printf("*\tLos operandos no deben ser mayores a 10⁵\t\t\t*\n");
	printf("*\tSuerte con sus cuentas...\t\t\t\t\t*\n");
	printf("*************************************************************************\n");
}

// Inicializacion de los operadores
static void inicializar() 
{
  add_operation(OP_SUMA,suma);    // Constantes y funciones del módulo math
  add_operation(OP_RESTA,resta);
  add_operation(OP_MULTI,multi);
  add_operation(OP_DIV,div);
  add_operation(OP_EXP,pot);
}

// Función que agrega operaciones a los arreglos
static void add_operation(char op , double (*pfun)(double,double,int*) )
{
  static int i=0;
  operandos[i]=op;
  func[i++]=pfun;
}

// Funcion que pregunta al usuario si desea continuar
// Devuelve TRUE si la confirmacion es positiva, FALSE si es negativa
static int continuar(void)
{
  printf("Desea realizar otra operacion? y/n: ");
  while(TRUE)       // Repito mientras la entrada sea invalida
  {
    char c = getchar();
    if (c == 'y' || c == 'Y') 
    {
      CLEAN_BUFFER();  // Limpio buffer
      return TRUE;  // Desea continuar
    }
    else if (c == 'n' || c == 'N') 
    {
      CLEAN_BUFFER();  // Limpio buffer
      return FALSE; // No desea continuar
    }

    if (c != '\n')    // Solos si se ingreso algo
    {
      CLEAN_BUFFER();  // Limpio buffer
    }

    printf("y/n: ");  // Vuelvo a pedir confirmación
  }
}

// Devuelve la primer posición de un caracter en un arreglo.
// Si el elemento no existe, devuelve -1
static int getindexOf(char c, char arr[], int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == c) {
      return i;
    }
  }
  return -1;
}