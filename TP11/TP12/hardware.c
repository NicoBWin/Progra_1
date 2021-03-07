/***************************************************************************//**
  @file     +hardware.c+
  @brief    +Archivo fuente del módulo hardware, para controlar GPIO de la Raspi+
  @author   +Grupo 3+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "hardware.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
#define LED0dir "/sys/class/gpio/gpio17/direction"
#define LED0val "/sys/class/gpio/gpio17/value"
#define LED1dir "/sys/class/gpio/gpio4/direction"
#define LED1val "/sys/class/gpio/gpio4/value"
#define LED2dir "/sys/class/gpio/gpio18/direction"
#define LED2val "/sys/class/gpio/gpio18/value"
#define LED3dir "/sys/class/gpio/gpio23/direction"
#define LED3val "/sys/class/gpio/gpio23/value"
#define LED4dir "/sys/class/gpio/gpio24/direction"
#define LED4val "/sys/class/gpio/gpio24/value"
#define LED5dir "/sys/class/gpio/gpio16/direction"      // Cambiar por 25
#define LED5val "/sys/class/gpio/gpio16/value"          // Cambiar por 25
#define LED6dir "/sys/class/gpio/gpio22/direction"
#define LED6val "/sys/class/gpio/gpio22/value"
#define LED7dir "/sys/class/gpio/gpio27/direction"
#define LED7val "/sys/class/gpio/gpio27/value"

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

int init_raspi()
{
    FILE *handle_pin_exp;
    static int error = 0;
    
    fin_raspi();    // Por si hay algún GPIO exportado, no mostrar error

    if( (handle_pin_exp = fopen("/sys/class/gpio/export", "w"))==NULL)
    {
        printf("Cannot open EXPORT File. Try again later.\n");
        return ERROR;
    }
    
    error += fputs("4", handle_pin_exp) != EOF ? 0 : -1;
    fflush(handle_pin_exp);
    error += fputs("17", handle_pin_exp) != EOF ? 0 : -1;
    fflush(handle_pin_exp);
    error += fputs("18", handle_pin_exp) != EOF ? 0 : -1;
    fflush(handle_pin_exp);
    error += fputs("22", handle_pin_exp) != EOF ? 0 : -1;
    fflush(handle_pin_exp);
    error += fputs("23", handle_pin_exp) != EOF ? 0 : -1;
    fflush(handle_pin_exp);
    error += fputs("24", handle_pin_exp) != EOF ? 0 : -1;
    fflush(handle_pin_exp);
    error += fputs("16", handle_pin_exp) != EOF ? 0 : -1;
    fflush(handle_pin_exp);
    error += fputs("27", handle_pin_exp) != EOF ? 0 : -1;
    fclose(handle_pin_exp);

    if (error < 0)      // Fallo algun export
    {
        printf("No se pudieron exportar los pines\n");
        fin_raspi();
        return ERROR;
    }

    printf ("Se pudieron exportar los pines\n");
    error=0;
    
    printf("Presione enter para continuar\n");
    while (getchar() != '\n') continue;     // PAUSA para que se exporten los pines correctamente
    
    FILE *handle_dir;   // Declaramos todas direcciones como salida
    
    handle_dir = fopen(LED0dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);

    handle_dir = fopen(LED1dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);

    handle_dir = fopen(LED2dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);
    
    handle_dir = fopen(LED3dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);
    
    handle_dir = fopen(LED4dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);
    
    handle_dir = fopen(LED5dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);
        
    handle_dir = fopen(LED6dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);
    
    handle_dir = fopen(LED7dir,"w");
    error += fputs("out", handle_dir) != EOF ? 0 : -1;
    fclose(handle_dir);


    if (error < 0)  // Error en algun pin
    {
        printf("No se pudieron configurar la I\\O de los pines\n");
        fin_raspi();
        return ERROR;
    }

    printf("Se pudo configurar la I\\O de los pines\n");
    return NO_ERROR;
}

int act_leds(char port)
{
    static int error=0;

    FILE *handle_pin;

    handle_pin = fopen(LED0val,"w");
    error += fputs((bitGet(port, 0)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);

    handle_pin = fopen(LED1val,"w");
    error += fputs((bitGet(port, 1)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);

    handle_pin = fopen(LED2val,"w");
    error += fputs((bitGet(port, 2)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);

    handle_pin = fopen(LED3val,"w");
    error += fputs((bitGet(port, 3)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);

    handle_pin = fopen(LED4val,"w");
    error += fputs((bitGet(port, 4)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);

    handle_pin = fopen(LED5val,"w");
    error += fputs((bitGet(port, 5)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);
    
    handle_pin = fopen(LED6val,"w");
    error += fputs((bitGet(port, 6)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);
    
    handle_pin = fopen(LED7val,"w");
    error += fputs((bitGet(port, 7)==1)?"1":"0", handle_pin) != EOF ? 0 : -1;
    fclose(handle_pin);
    
    /*
    fprintf(fopen(LED0val), "%d", bitGet(port,0)==1);
    fprintf(fopen(LED1val), "%d", bitGet(port,1)==1);
    fprintf(fopen(LED2val), "%d", bitGet(port,2)==1);
    fprintf(fopen(LED3val), "%d", bitGet(port,3)==1);
    fprintf(fopen(LED4val), "%d", bitGet(port,4)==1);
    fprintf(fopen(LED5val), "%d", bitGet(port,5)==1);
    fprintf(fopen(LED6val), "%d", bitGet(port,6)==1);
    fprintf(fopen(LED7val), "%d", bitGet(port,7)==1); 
    */           //otra forma de hacer lo mismo que arriba
    
    if (error < 0)
    {
        printf("No se pudo cargar la salida de los pines\n");
        fin_raspi();
        return ERROR;
    }
    return NO_ERROR;
}

void fin_raspi() 
{
    FILE *handle_pin_exp;
    handle_pin_exp = fopen("/sys/class/gpio/unexport", "w");
    fputs("4", handle_pin_exp);
    fflush(handle_pin_exp);
    fputs("17", handle_pin_exp);
    fflush(handle_pin_exp);
    fputs("18", handle_pin_exp);
    fflush(handle_pin_exp);
    fputs("22", handle_pin_exp);
    fflush(handle_pin_exp);
    fputs("23", handle_pin_exp);
    fflush(handle_pin_exp);
    fputs("24", handle_pin_exp);
    fflush(handle_pin_exp);
    fputs("16", handle_pin_exp);
    fflush(handle_pin_exp);
    fputs("27", handle_pin_exp);
    fclose(handle_pin_exp);
}