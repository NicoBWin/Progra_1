#include <stdio.h>

#define MAXLENGTH   50
#define OFFSET      '0'
#define NOERROR     0
#define ERROR       1
#define TERMINADOR  '\n'
#define EQUALS      1
#define NOTEQUALS   0

#define SELECT_PALABRA(x)  (((x)==1)? "primer":"segunda")
#define VALORES_ADMISIBLES(x)  (((x)>= 'A' && (x)<= 'Z') || ((x) >= 'a' && (x) <= 'z') || (x)==TERMINADOR)

void cleanBuffer();
// Limpia todo el contenido del buffer.

void lecture(char palabra[MAXLENGTH], int nPalabra);
void compare(char palabra1[MAXLENGTH], char palabra2[MAXLENGTH]);
void cleanword(char palabra[MAXLENGTH]);



int main ()
{
    char palabra1[MAXLENGTH];
    char palabra2[MAXLENGTH];
	
	cleanword(palabra1);
	cleanword(palabra2);
	

    int palabra = 1;
    lecture(palabra1, palabra);  // Leo la primer palabra.
    palabra = 2;
    lecture(palabra2, palabra);  // Leo la segunda palabra.
    
    printf("P1: %s", palabra1);
    printf("P2: %s", palabra2);
    
    compare (palabra1, palabra2);
    return 0;
}

void lecture(char palabra[MAXLENGTH], int nPalabra)
{
    int error=ERROR;
    char *p;
    int cont=0;

    while (error==ERROR)
    {
        printf("Ingrese la %s palabra:", SELECT_PALABRA(nPalabra));
        
        p = palabra;
        error = NOERROR;
        int c;
        do
        {
            c = getchar();
            
            if (VALORES_ADMISIBLES(c))
            {
                *(p++)=c;
                if ((++cont)==MAXLENGTH)
                {
                    cont=0;
                    if (c!=TERMINADOR) {
                        cleanBuffer();
                    }
                    error=ERROR;
                    cleanword(palabra);
                    printf("Se excedió la cantidad máxima de caracteres\n");
                }
            }
            else
            {
                error=ERROR;
                cleanBuffer();
                cleanword(palabra);
                cont=0;
                printf("Por favor ingrese una palabra con caracteres válidos.\n");
            }
        } while (c!=TERMINADOR && error!=ERROR);
        
        if (palabra[0]=='\n')
        {
            error=ERROR;
            printf("Por favor la ingrese una palabra con al menos un caracter.\n");
            cont=0;
        }
    }
    
}

void compare(char palabra1[MAXLENGTH], char palabra2[MAXLENGTH])
{   
    char *p2= palabra2, *p1= palabra1;
    int equals = EQUALS;
    int encontrado;
    while(*p2!=TERMINADOR && equals==EQUALS)
    {
        p1 = palabra1;     // Cada vez que quiero comparar un nuevo caracter de la segunda palabra,
                            // apunto con un puntero al inicio de la primer palabra.
        encontrado = 0;   
        do
        {
            if (*p1==*p2)
            {               // Si encontre en la primer la palabra el caracter de la segunda palabra sin haber sido utilizado,
                *p1=0;   //lo borro para ya no tenerlo en cuenta en analisis posteriores.
                encontrado = 1;
            }                  

        } while (encontrado==0 && *(++p1)!=TERMINADOR);    //Mientras que no haya llegado al final de la primer palabra ni haya encontrado
                                                    // el caracter de la segunda palabra en la segunda, sigo buscando. 
    
        p2++;   //apunto al siguiente caracter de la primer palabra
        
        if (*p1==TERMINADOR)    // Si llegue al terminador de la segunda palabra:
        {                       //entonces no me quedan letras para comparar y 
            equals = NOTEQUALS; //por conclusión no puedo armar la primera con la segunda 
        }
    }

    if (equals==EQUALS)
    {
        printf ("Se puede formar la segunda palabra con las letras de la primera.\n");
    }
    else
    {
        printf ("No se puede formar la segunda palabra con las letras de la primera.\n");
    }   
}

void cleanBuffer()
{  
    while (getchar() != '\n');
}

void cleanword(char palabra[MAXLENGTH])
{
    char *p=palabra; 
    while ((p-palabra)<=MAXLENGTH-1)
    {
        *p=0;
        p++;
    }
}