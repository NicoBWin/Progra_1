/***************************************************************************/ /**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "raspi.h"
#include "PORT.h"


/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

#define LED0dir "/sys/class/gpio/gpio17/direction"
#define LED0val "/sys/class/gpio/gpio17/value"
#define LED1dir "/sys/class/gpio/gpio4/direction"
#define LED1val "/sys/class/gpio/gpio14/value"
#define LED2dir "/sys/class/gpio/gpio18/direction"
#define LED2val "/sys/class/gpio/gpio18/value"
#define LED3dir "/sys/class/gpio/gpio23/direction"
#define LED3val "/sys/class/gpio/gpio23/value"
#define LED4dir "/sys/class/gpio/gpio24/direction"
#define LED4val "/sys/class/gpio/gpio24/value"
#define LED5dir "/sys/class/gpio/gpio25/direction"
#define LED5val "/sys/class/gpio/gpio25/value"
#define LED6dir "/sys/class/gpio/gpio22/direction"
#define LED6val "/sys/class/gpio/gpio22/value"
#define LED7dir "/sys/class/gpio/gpio27/direction"
#define LED7val "/sys/class/gpio/gpio27/value"

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: unsigned int anio_actual;+

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static void falta_envido (int);+

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static int temperaturas_actuales[4];+

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

int init_raspi()
{
    FILE *handle_exp;
    static int error = 0;

    handle_exp = fopen("/sys/class/gpio/export", "w");
    error += fputs("4", handle_exp);
    error += fputs("17", handle_exp);
    error += fputs("18", handle_exp);
    error += fputs("22", handle_exp);
    error += fputs("23", handle_exp);
    error += fputs("24", handle_exp);
    error += fputs("25", handle_exp);
    error += fputs("27", handle_exp);
    fclose(handle_exp);

    if (error > 0)
    {
        printf("No se pudieron exportar los pines\n");
        return 1;
    }

    error += fputs("out", fopen(LED0dir));
    error += fputs("out", fopen(LED1dir));
    error += fputs("out", fopen(LED2dir));
    error += fputs("out", fopen(LED3dir));
    error += fputs("out", fopen(LED4dir));
    error += fputs("out", fopen(LED5dir));
    error += fputs("out", fopen(LED6dir));
    error += fputs("out", fopen(LED7dir));

    if (error > 0)
    {
        printf("No se pudieron configurar la I\\O de los pines\n");
        return 1;
    }
    return 0;
}

int act_leds(char port)
{
    static int error=0;
    error += fputs((bitGet(port, 0)==1)?"1":"0", fopen(LED0val));
    error += fputs((bitGet(port, 1)==1)?"1":"0", fopen(LED1val));
    error += fputs((bitGet(port, 2)==1)?"1":"0", fopen(LED2val));
    error += fputs((bitGet(port, 3)==1)?"1":"0", fopen(LED3val));
    error += fputs((bitGet(port, 4)==1)?"1":"0", fopen(LED4val));
    error += fputs((bitGet(port, 5)==1)?"1":"0", fopen(LED5val));
    error += fputs((bitGet(port, 6)==1)?"1":"0", fopen(LED6val));
    error += fputs((bitGet(port, 7)==1)?"1":"0", fopen(LED7val));

    /*
    fprintf(fopen(LED0val), "%d", bitGet(port,0)==1);
    fprintf(fopen(LED1val), "%d", bitGet(port,1)==1);
    fprintf(fopen(LED2val), "%d", bitGet(port,2)==1);
    fprintf(fopen(LED3val), "%d", bitGet(port,3)==1);
    fprintf(fopen(LED4val), "%d", bitGet(port,4)==1);
    fprintf(fopen(LED5val), "%d", bitGet(port,5)==1);
    fprintf(fopen(LED6val), "%d", bitGet(port,6)==1);
    fprintf(fopen(LED7val), "%d", bitGet(port,7)==1); 
    */
    
    return error;
}