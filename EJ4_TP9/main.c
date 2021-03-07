/***************************************************************************/ /**
  @file     +main.c+
  @brief    +Archivo principal del programa+
  @author   +Grupo 3+
 ******************************************************************************/
#include <stdio.h>

#include "const.h"
#include "lectura.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
/**
 * @brief is_palindromo: dado un string, analiza si es palíndromo
 * @param *p1: Ptro a primera posicion del string 
 * @param *p2 Ptro a última posicion del string
 * @return Devuelve un BOOLEAN (1 si es palindromo, 0 si no lo es)
*/
static int is_palindromo(char *p1, char *p2);

/**
 * @brief Imprime un mensaje de bienvenida e instrucciones por pantalla
*/
static void welcome(void);

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
int main()
{
  char phrase[MAX_LENG];
  welcome();
  char *s = phrase; //puntero al comienzo de la cadena
  char *sf;         //Puntero al último elemento de la cadena
  int size = lect(phrase, MAX_LENG);
  sf = s + size-1; //El final de la cadena
  
  if (is_palindromo(s, sf) == OK)
  {
    printf("La cadena es un palindromo\n");
  }
  else
  {
    printf("La cadena NO es un palindromo\n");
  }
  return 0;
}
/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static void welcome() {
  printf("Ingrese una frase menor a %u caracteres y se le indicará si es un palíndromo.\n", MAX_LENG);
  printf("Tenga en cuenta que cualquier caracter que no sea una letra del alfabeto inglés (a-z;A-Z)\n");
  printf("será ignorado para el análisis (Por ejemplo: letras acentuadas, números, caracteres especiales, ñ, etc.)\n");
}

static int is_palindromo(char *p1, char *p2)
{
  
  *p1= MAY_TO_MIN(*p1);   // Paso los caracteres a minúscula
  *p2= MAY_TO_MIN(*p2);   //sólo si son letras mayúsculas. 

  if (p1 >= p2) // Si los punteros se cruzaron (caso base)
  {
    return OK;  // El mensaje es palindromo.
  }

  else if (*p1 < 'a' || *p1 > 'z')    // No es una letra
  {
    return is_palindromo(p1+1, p2);   // Llamo de nuevo ignorandolo
  }

  else if (*p2 < 'a' || *p2 > 'z')    // No es una letra
  {
    return is_palindromo(p1, p2-1);   // Llamo de nuevo ignorandolo.
  }

  else  // Si la letra es interpretable, analizo recursivamente la siguiente pareja de caracteres.
  {
    return (*p1 == *p2) && is_palindromo(p1 + 1, p2 - 1);
  }
}