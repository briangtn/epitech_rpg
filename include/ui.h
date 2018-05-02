/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fight scene header
*/


#ifndef __UI_H_
	#define __UI_H_

	#include "my_sfml.h"

	#define WHITE_SPRITE "assets/spritesheets/white.png"

	#pragma region loadbar

		typedef struct loadbar_comp {
			void (*destroy)();
			gameobject_t *parent;
			float max_value;
			float current_value;
			sfColor fore_color;
			sfColor back_color;
			sf_vector_2d_t sizes;
			gameobject_t *back_go;
			sf_engine_t *engine;
		} sf_loadbar_t;

	sf_loadbar_t *create_loadbar_comp(gameobject_t *go);
	int loadbar_update(void *obj, UNUSED int delta_time);

	#pragma endregion

#endif /* !__UI_H_ */