#include <stdio.h>
#define MULTI 10

int pepe(void);

int main ()
 {
	int cont=0, err=0;
	while (err==0){
	cont=pepe();
	if (cont<0){
		err++;
	}
	else {
		printf("%d\n", cont);
	}
 }
 }
 
 int pepe()
 {
	char c;
	int d=0;
	while ((c=getchar()) != '\n' ) {
		if (c>='0' && c<='9') {
				d = (MULTI*d) + (c-'0');	//Empieza a multiplicar por 10
		}
		else if (c=='.' || c==',') {
				printf("Crak ingresaste un punto, solo números enteros\n\n");
				return --d;
			}
		else if (c=='-') {
			printf("Crak ingresaste un menos, solo números enteros\n\n");
			return --d;
		}
		else {
			printf("Ingresa un numero válido crack\n\n");
			return --d;
		}
	}
return d;
 }