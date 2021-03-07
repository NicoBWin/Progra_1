#ifndef MATH_
#define MATH_

/*
 * @brief suma: Resta los dos operandos que recibe
 * @param x Es el primer numero que se ingreso
 * @param y Es el segundo numero que se ingreso
 * @param *error Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo float para mayor precision 
*/
float sum(float x, float y, int *error);
/*
 * @brief resta: Resta los dos operandos que recibe
 * @param x Es el primer numero que se ingreso
 * @param y Es el segundo numero que se ingreso
 * @param *error Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo double para mayor precision 
*/
float subst(float x, float y, int *error);
/*
 * @brief multip: Resta los dos operandos que recibe
 * @param x Es el primer numero que se ingreso
 * @param y Es el segundo numero que se ingreso
 * @param *error Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo double para mayor precision 
*/
float multip(float x, float y, int *error);
/*
 * @brief expo: Resta los dos operandos que recibe
 * @param x Es el primer numero que se ingreso
 * @param y Es el segundo numero que se ingreso
 * @param *error Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo double para mayor precision 
*/
float expo(float x, float y, int *error);
/*
 * @brief divid: Resta los dos operandos que recibe
 * @param x Es el primer numero que se ingreso
 * @param y Es el segundo numero que se ingreso
 * @param *error Puntero que indica si hay error en la cuenta
 * @return Devuelve el resultado tipo double para mayor precision 
*/
float divi(float x , float y, int *error);

#endif