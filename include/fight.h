/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fight scene header
*/

/* File created the 04/04/2018 at 12:05:23 by julian.frabel@epitech.eu */

#ifndef __FIGHT__H_
	#define __FIGHT__H_

	typedef struct attack {
		char *name;
		float damage;
		float power;
	} attack_t;

	typedef struct my_fight_enemy {
		float life;
		char *sprite_path;
	} fight_enemy_t;

	typedef struct my_fight {
		char *background_path;
		char *player_sprite_path;
		float player_life;
	} fight_t;

#endif /* !__FIGHT__H_ */