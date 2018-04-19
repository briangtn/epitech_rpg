/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fight scene header
*/

/* File created the 04/04/2018 at 12:05:23 by julian.frabel@epitech.eu */

#ifndef __FIGHT__H_
	#define __FIGHT__H_

	#include "my_sfml.h"
	#define FIGHT_ELEMENT_SIZE 64
	#define FIGHT_ENEMY_SPACE 50

	typedef struct attack {
		char *name;
		float damage;
		float power;
	} attack_t;

	typedef struct fight_enemy {
		float life;
		char *sprite_path;
	} fight_enemy_t;

	typedef struct fight_player {
		float life;
		char *sprite_path;
		sf_vector_2d_t position;
	} fight_player_t;

	typedef struct my_fight {
		char *background_path;
		fight_player_t player;
		sf_linked_list_t *ennemies;
	} fight_t;

#endif /* !__FIGHT__H_ */