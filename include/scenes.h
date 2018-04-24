/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Scenes
*/

/* File created the 04/04/2018 at 13:55:18 by julian.frabel@epitech.eu */

#ifndef __SCENES__H_
	#define __SCENES__H_

	#include "my_sfml.h"

	sf_scene_t *create_game_scene(sf_engine_t *engine);
	void load_parsing_to_game_scene(parser_to_game_t *ptg, \
sf_engine_t *engine);

	sf_scene_t *create_fight_scene(sf_engine_t *engine, fight_t *fight);


#endif /* !__SCENES__H_ */