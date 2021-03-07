#include <stdio.h>
#define NUMERO 123456

int suma_digitos(int);

int main(void)
{
    printf("%d", suma_digitos(NUMERO));
}
int suma_digitos(int n1)
{
    if (n1 == 0)
    {
        return 0; //caso base
    }
    else
    {
        return ((n1 % 10) + suma_digitos(n1 / 10)); //caso recursivo
    }
}