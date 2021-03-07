#include <stdio.h>

#define VALIDO 1
#define NVALIDO 0
#define ERROR 1
#define NO_ERROR 	0
#define N 			40
#define OFFSET 		32
#define HLONG 100

void cleanstr(char name[]);			
// Coloca todos 0 en el strin.

void welcome();
// Imprime mensaje de bienvenida e instrucciones

int size (char name[]);
// Ingresa los datos cargados por el teclado en el string e indica la cantidad de caracteres ingresados.

void cleanbuffer();
// Limpia todo el contenido del buffer.

int compare(char *ne1, char *ne2,int n1,int n2 );
// Recorre los caracteres de la segunda palabla e invoca a "findletter" para saber su existe en la primera palabra

int findletter(char *ne1, char *ne2, int n1);
// Compara el caracter recibido de la segunda palabra y busca si existe ese caracter en la primera, si existe 
//   borra en la primera palabra la letra para que no se repita la lectura

int main() {
	welcome();
	while (1) {
		char name1[HLONG];
		cleanstr(name1);			
		char name2[HLONG];
		cleanstr(name2);
		
		char *ne1=name1;		//Puntero para el primer nombre
		char *ne2=name2;		//Puntero para el segundo nombre
		
		/*HAY QUE HACER UN MENU DE INICIO EXPLICANDO EL PROGRAMA*/

		printf("Ingrese la primera palabra: ");
		int n1=size(name1);		//Carga el primer nombre e indica su largo en n1 
		printf("Ingrese la segunda palabra: ");
		int n2=size(name2);		//Carga el segundo nombre e indica su largo en n2
		printf("\n");
		
		if (n2<=n1){		//Si la segunda palabla es mas larga que la primera ni analizamos
			printf("Los nombres ingresados son: %s / %s\n" ,name1 ,name2);
			if (compare(ne1, ne2, n1, n2)==1) {
				printf("La segunda palabra SI se puede formar completamente con las letras contenidas en la primera\n");
			}
			else {
				printf("La segunda palabra NO se puede formar completamente con las letras contenidas en la primera\n");
			}
		}
		else {
			printf("El segundo nombre ingresado es más largo que el\n");
			printf("primero por lo que no se puede comparar: %s / %s\n" ,name1 ,name2);
		}
		printf("\n\n");
	}	
	return 0;
}

void welcome() {
	printf("#################################################################\n");
	printf("#\t\tBinevenido al juego de las palabras!\t\t#\n");
	printf("#\tSe le pedirá ingresar dos palabras y el programa\t#\n");
	printf("#\tle indicará si la segunda se puede formar solo con\t#\n");
	printf("#\tlas letras de la primera. No está permitido ingresar\t#\n");
	printf("#\tpalabras de más de %d caracteres, tampoco ñ ni\t\t#\n", HLONG);
	printf("#\tcaracteres especiales (tildes, dierecis, etc). Solo\t#\n");
	printf("#\tletras del alfabeto inglés, en minúscula o mayúscula.\t#\n");
	printf("#\tLa mayúscula no se considera para la comparación.\t#\n");
	printf("#\tEj: Con las letras de \"morsa\" se puede escribir \"Rosa\".\t#\n");
	printf("#################################################################\n");
}

void cleanstr(char name[]) {
	for(int i=0;i<HLONG;i++) {
		name[i]=0;
	}
}

int size (char name[]) {
	char c;
	int i=0;		//Indice de name
	int error=0;
	int n=0;
	do
    {
		error = NO_ERROR;
		           //Mientras que no apriete enter ni se encuentre error
        while (error!= ERROR && (c=getchar()) != '\n') {	
			if (c>='A' && c<='Z'){
				c=c+OFFSET;		
			}
			if (c>='a' && c<='z'){
				name[i]=c;
				i++;
				n++;
			}
            else {					
			    error=ERROR;							// Si no, es un caracter erroneo y pido que vuelva a ingresar el numero.
				printf ("Palabla no válida, por favor vuelva a ingresarla:\n");	
                cleanbuffer();	
				i=0;
			}
		}
	}
	while (error==ERROR);       // Repetir todo el bucle hasta que se haya ingresado un valor válido.
	return n;
}

void cleanbuffer() {  
    while (getchar() != '\n');
}

int compare (char *ne1, char *ne2,int n1, int n2) {
	int valid=NVALIDO;
	for(int i=0;i<n2;i++) {
		valid=findletter(ne1, (ne2+i), n1);
		if(valid==NVALIDO){
			return valid;
		}
	}
	return valid;
}

int findletter(char *ne1, char *ne2, int n1) {
		int valid=0;
		for(int i=0;i<n1;i++) {
				if(*ne2==*(ne1+i)) {
					*(ne1+i)=0;		//Limpio ese espacio de memoria para que no vuelva a comparar con esa letra
					return valid=VALIDO;
				}
				else {
					valid=NVALIDO;
				}
		}
		return valid;
}