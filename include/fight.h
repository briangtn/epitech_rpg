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
		char *name;
		float life;
		char *sprite_path;
		gameobject_t *go;
	} fight_enemy_t;

	typedef struct fight_player {
		float life;
		char *sprite_path;
		sf_vector_2d_t position;
		gameobject_t *go;
	} fight_player_t;

	typedef struct my_fight {
		char *background_path;
		fight_player_t player;
		sf_linked_list_t *ennemies;
	} fight_t;

	#pragma region components

	typedef struct fight_arrow {
		void (*destroy)();
		gameobject_t *parent;
		int enemy_index;
		fight_t *fight;
	} sf_fight_arrow_t;

	sf_fight_arrow_t *create_farrow_comp(gameobject_t *parent);

	#pragma endregion

	int get_enemy_center_position(sf_engine_t *engine, int enemy_count);
	int get_total_elem_size(void);
	int get_enemy_posx(sf_engine_t *engine, int enemy_count, int pos);
	void scale_elem_to_size(sfSprite *sprite);

#endif /* !__FIGHT__H_ */