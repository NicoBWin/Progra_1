#include  <stdio.h>

#define OK	0

#define FALSE	0
#define	TRUE	1

#define MAX_LENGTH	100	// Máxima cantidad de caracteres de cada palabra

#define MAY_TO_MIN	('a'-'A')		// Sumarla para obtener minúscula

#define MIN_TO_MAY	('A'-'a')		// Sumarla para obtener mayúscula

#define IS_LETTER(c)	(((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
// MACRO que devuelve TRUE si c es un caracter válido, mayúscula o minúscula, si no FALSE.

void welcome();
// Imprime mensaje de bienvenida e instrucciones

int readWord(char word[]);
// Devuelve en word la palabra ingresada por el usuario.
// Si la entrada no es válida, imprime un error y devuelve TRUE, caso contrario, devuelve FALSE

int sePuedeFormar(char first[], char second[]);
// Devuelve TRUE si el string de second se puede formar con los caracteres de first.
// first es modificada, cambiando las letras que aparecen en second por (-1)'s

char* getPointerTo(char s[], char c);
// Devuelve un puntero al primer caracter c si se encuentra en el string s, si no, devuelve puntero al terminador.

void copyString(char origin[], char copy[]);
// Copia el string de origin en copy. Asegurarse de que origin tenga terminador.

char* getRemaining(char string[]);
// Devuelve un puntero al primer caracter de string distinto de -1, si no hay, devuelve un puntero al terminador

void cleanBuffer();
// Limpieza del buffer de getchar()


int main() {

	welcome();	// Mensaje de bienvenida e instrucciones

	int error = FALSE;	// Variable de detección de errores

	char firstWord[MAX_LENGTH+1];		// Strings para guardar las palabras
	char secondWord[MAX_LENGTH+1];		// Tamaño máximo: MAX_LENGTH+terminador

	int segunda = FALSE;	// Se activa una vez que se ya se haya validado la primera palabra

	do {
		printf("Ingrese la %s palabra: ", segunda ? "segunda" : "primera");
		error = readWord(segunda ? secondWord : firstWord);	// Guardo la palabra en el string según la pasada
		if (error) {
			printf("La entrada no es válida, ingrese la palabra nuevamente\n");
		}
	} while (error || (segunda = !segunda) );		// Repito hasta que no haya error y ya haya pasado por la segunda palabra

	char firstCopy[MAX_LENGTH+1];		// Realizo una copia del string que va a ser modificado
	copyString(firstWord, firstCopy);	// Para poder imprimirlo al final

	if (sePuedeFormar(firstCopy, secondWord)) {	// Evaluo si la segunda palabra puede ser formada con la primera
		printf("\n\"%s\" puede ser formada con las letras de \"%s\".\n", secondWord, firstWord);
		char *c = getRemaining(firstCopy);
		if  (*c != '\0') {		// Si queda algun caracter sin borrar
			printf("Y sobran las siguientes letras:");
			while ( *(c = getRemaining(firstCopy)) != '\0' ) {
				printf(" '%c'", *c);
				*c = -1;	// Lo borro para no repetir
			}
			printf(".\n");
		} else {			// Todos los caracteres fueron utilizados
			printf("Y utiliza todas las letras.\n");
		}
	} else {
		printf("\n\"%s\" no se puede formar con las letras de \"%s\"\n", secondWord, firstWord);
	}
	printf("\n");	// Por claridad
	return OK;
}

void welcome() {
	printf("#################################################################\n");
	printf("#\t\tBinevenido al juego de las palabras!\t\t#\n");
	printf("#\tSe le pedirá ingresar dos palabras y el programa\t#\n");
	printf("#\tle indicará si la segunda se puede formar solo con\t#\n");
	printf("#\tlas letras de la primera. No está permitido ingresar\t#\n");
	printf("#\tpalabras de más de %d caracteres, tampoco ñ ni\t\t#\n", MAX_LENGTH);
	printf("#\tcaracteres especiales (tildes, dierecis, etc). Solo\t#\n");
	printf("#\tletras del alfabeto inglés, en minúscula o mayúscula.\t#\n");
	printf("#\tLa mayúscula no se considera para la comparación.\t#\n");
	printf("#\tEj: Con las letras de \"morsa\" se puede escribir \"Rosa\".\t#\n");
	printf("#################################################################\n");
}

int readWord(char word[]) {
	char c;
	int i = 0;
	while ((c = getchar()) != '\n') {
		if (IS_LETTER(c)) {	// Acepto las letras mayúsculas y minúsculas,
			word[i] = c;			// Guardo el caracter en el string
			i++;				// y avanzo al siguiente caracter
		} else {			// Caracter erróneo
			cleanBuffer();			// limpio buffer
			return TRUE;			// y regreso con error
		}

		if (i > MAX_LENGTH) {		// Supera el máximo de caracteres
			cleanBuffer();			// limpio buffer
			return TRUE;			// y regreso con error
		}
	}
	if (i == 0) {		// No se ingresó nada.
		return TRUE;
	}
	// Entrada exitosa
	word[i] = '\0';	// Agrego terminador
	return FALSE;	// Salida sin errores
}

int sePuedeFormar(char first[], char second[]) {
	while (*second != '\0') {	// Recorro la segunda palabra
		char *p = getPointerTo(first, *second);	// Me devuelve donde esta el caracter actual en first, si no esta es -1
		if (*p != '\0') {
			*p = -1;	// Lo elimino del string, para que no se repita.
		} else {
			return FALSE;		// Un caracter de second no está en first, no se puede formar
		}
		second++;			// siguiente elemento
	}
	return TRUE;	// Se recorrio todo second y se lograron encontrar todas las letras.
}

char* getPointerTo(char s[], char c) {
	while (*s != '\0') {		// Recorro s hasta el terminador
		if (	(*s == c) ||					// Si:	- coincide exactamente con el elemento
			(*s >= 'a' && *s+MIN_TO_MAY == c) ||	//	- coincide con el elemento en minúscula
			(*s <= 'Z' && *s+MAY_TO_MIN == c) ) {	//	- coincide con el elemento en mayúscula

			return s;						// Elemento encontrado, devuelvo puntero
		}
		s++;				// Siguiente elemento
	}
	return s;	// No se encontró, puntero a '\0'
}

void copyString(char origin[], char copy[]) {
	int i = 0;
	while (origin[i] != '\0') {	// Hasta encontrar el terminador
		copy[i] = origin[i];		// Copio cada caracter
		i++;				// Y paso al siguiente
	}
	copy[i] = '\0';		//Agrego terminador
}

char* getRemaining(char string[]) {
	while (*string != '\0') {	// Busco hasta el terminador
		if (*string != -1) {		// Si no fue borrado
			return string;			// Devuelvo el puntero
		}
		string++;
	}
	return string;	// Todos borrados, devuelvo puntero al terminador
}

void cleanBuffer() {
	while(getchar() != '\n') {	// Me quedo limpiando el buffer hasta encontrar el terminador
		continue;
	}
}
