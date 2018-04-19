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

	#define PLAYER_MOVEMENT_SPEED_MUL 3
	#define PLAYER_ANIMATION_SPEED .2
	#define PLAYER_NB_FRAME_ANIMATION 4
	#define PLAYER_DOWN_ANIM 0
	#define PLAYER_LEFT_ANIM 1
	#define PLAYER_RIGHT_ANIM 2
	#define PLAYER_UP_ANIM 3
	#define PLAYER_SPRITE_SHEET SPRITESHEET_PLAYER

	gameobject_t *create_prefab_player(sf_engine_t *engine);
	void destroy_prefab_player(gameobject_t *player);

	int player_movement(gameobject_t *player, int delta_time);

	#pragma endregion /* !Player */

#endif /* !__PREFABS__H_ */