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
	#define PLAYER_SPRITE_SHEET SPRITESHEET_PLAYER

	gameobject_t *create_prefab_player(sf_engine_t *engine);
	void destroy_prefab_player(gameobject_t *player);

	#pragma endregion /* !Player */

	#pragma region Fight

	gameobject_t *create_prefab_fbackground(sf_engine_t *engine,\
fight_t *fight);
	gameobject_t *create_prefab_fplayer(sf_engine_t *engine,\
fight_t *fight);
	gameobject_t *create_prefab_fenemy(sf_engine_t *engine,\
fight_enemy_t *enemy, sf_vector_2d_t position);

	#pragma endregion

#endif /* !__PREFABS__H_ */