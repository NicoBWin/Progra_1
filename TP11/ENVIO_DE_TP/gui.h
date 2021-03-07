/***************************************************************************//**
  @file     +allegro.h+
  @brief    +Header de allegro+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef ALLEGRO_H
#define ALLEGRO_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief init_all: Inicializa todos los parametros de allegro
*/
int init_all(void);

/**
 * @brief destroy_all: Libera la memoria que ya no usa cuando finaliza el prorama
*/
void destroy_all(void);

/**
 * @brief drawLEDS: Refresca la pantalla con el estado actual de los LED'S
 * @param ledState[] Descripcion parametro 1
 * @param nLeds Descripcion parametro 2
*/
void drawLEDS(bool ledState[], unsigned int nLeds);

/**
 * @brief al_cycle: Refresca la pantalla con el estado actual de los LED'S
 * @param ledState[] Descripcion parametro 1
 * @param size Descripcion parametro 2
 * @param blink blablabla
*/
bool al_cycle(bool ledState[], unsigned int size, bool blink);

/*******************************************************************************
 ******************************************************************************/

#endif // ALLEGRO_H   