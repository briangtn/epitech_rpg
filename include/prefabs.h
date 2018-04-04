/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Prefabs include
*/

/* File created the 04/04/2018 at 14:11:23 by julian.frabel@epitech.eu */

#ifndef __PREFABS__H_
	#define __PREFABS__H_

	#include "my_sfml.h"

	#pragma region Player
		gameobject_t *create_prefab_player(sf_engine_t *engine);
		void destroy_prefab_player(gameobject_t *player);
	#pragma endregion /* !Player */

#endif /* !__PREFABS__H_ */