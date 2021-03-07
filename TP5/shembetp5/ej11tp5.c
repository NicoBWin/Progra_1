#include <stdio.h>

#define ERROR 1
#define MAXSIZE 15
#define MAYUSOFFSET 32
#define ENTER '\n'
#define TERMINADOR '\0'
/*##################################################################################
#   -Se le pueden ingresar mayusculas y minusculas, su mayuscula y su minuscula son #
#   vistas como la misma letra                                                     #
#                                                                                  #
####################################################################################*/

//Recibe el espacio de memoria donde se guarda el string ingresado, devuelve un 1 si hubo error
int wordInput(char *word);

//Realiza la comparacion del las dos palabras, devuelve on OK si se puedo formar
int wordFormation(char *word1, char *word2);        

int main(void)
{

    char word1[MAXSIZE];                            
    char word2[MAXSIZE];
    
    do
    {
        printf("INGRESE LA PRIMER PALABRA\n");
    }
    while(wordInput(word1));                                    // hasta que no haya un error en el ingreso se pide que se ingrese la 1er palabra

    do
    {
        printf("INGRESE LA SEGUNDA PALABRA\n");
    }
    while(wordInput(word2));
   
    if(wordFormation(word1, word2))                             
    {
        printf("SE PUEDE FORMAR\n");
    }
    else
    {
        printf("NO SE PUEDE FORMAR\n");
    }

}

int wordFormation(char *word1, char *word2)
{
    int i_word2 = 0;
    int i_word1 = 0;
    int ok = 1 ;
    while(word2[i_word2] != TERMINADOR && ok)                         //Mientras no haya un \n en la segunda palabra y se esten encontrando las letras, se sigue analizando
    {
        ok = 0;                                                 //Hasta el momento, es como si no hubiese encontrado la letra OK = 0
        while(word1[i_word1] != TERMINADOR && !ok)                    //Mientras no haya un \n en la primer palabra y todavia no se haya encontrado la letra, sigo buscando
        {
            if(word1[i_word1] == word2[i_word2])                //Si encontro la letra, ya esta, paso a la siguiente, "borro" la letra de la primer palabra para no tomarla en cuenta de nuevo
            {
                ok = 1;
                word1[i_word1] = 1;
            }
            i_word1++;
        }
        i_word1 = 0;
        i_word2++; 
    }
    return ok;
}

int wordInput(char *word)
{
    char lyric;
    int i = 0;
    int error = 0;
    while( (lyric = getchar() ) != ENTER)
    {
        if( ( lyric >= 'A' && lyric <= 'Z' ) || ( lyric >= 'a' && lyric <= 'z' ) )      //Si esta en ese rango, bien
        {
            if(lyric >= 'A' && lyric <= 'Z')
            {
                lyric += MAYUSOFFSET;                                                   //OFFSET del ascii entre mayusculas y minusculas             
            }                                                                           //Transformo las mayusculas a minusculas para el analisis 

            word[i] = lyric;                                                            //Voy armando el string
            i++;
        }
        else
        {
            error = ERROR;
        }
    }
    if(!i || i == MAXSIZE)                                      //Si presiono enter sin haber ingresado caracteres, error, si se supero la max cantidad, error
    {
        error = ERROR;
    }
    else if(!error)
    {
        word[i] = TERMINADOR;                                         //Agrego el terminador que le corresponden a los string
    }

    return error;
}
