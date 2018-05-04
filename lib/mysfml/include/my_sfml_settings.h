/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Engine settings un one header
*/

/* File created the 04/04/2018 at 16:35:55 by julian.frabel@epitech.eu */

#ifndef __SETTINGS__H_
	#define __SETTINGS__H_

	#include <stdbool.h>

	/* Should the engine throw debug messages(intern error and researchs) */
	#define DEBUG_MSG_ACTIVE false

	/* Should the engine draw a rectangle around all hitbox in the scene */
	#define DISPLAY_HITBOX true

	/* Display the bounds of cameras (inner and outer) */
	/* Scene bounds: blue/Camera bounds: white/Camera center: yellow point*/
	#define DISPLAY_CAMERA_DEBUG false
	/* Gravity force on axis Y */
	#define GRAVITY_FORCE 0

#endif /* !__SETTINGS__H_ */