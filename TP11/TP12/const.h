/***************************************************************************/ /**
  @file     +const.h+
  @brief    +Constantes en comun en todo el programa+
  @author   +Grupo 3+
 ******************************************************************************/

#ifndef CONST_H
#define CONST_H

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define CANT_LEDS 8
#define PORT 'A'

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum COND
{
	FALSE,
	TRUE
};

enum ERRORES		// Distintos tipos de errores
{
	NO_ERROR = -2,
	ERROR = -1
};

enum STATES			// Estados utilizados para la comprensión de diferentes tareas
{
	NUMERO =	'n',
	TOGGLE =	't',
	CLEAR =		'c',
	SET =		's',
	QUIT =		'q',
	LECTURE =	'l',
	BLINK =		'b'
};

/*******************************************************************************
 ******************************************************************************/

#endif // CONST_H