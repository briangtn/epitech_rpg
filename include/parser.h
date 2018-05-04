/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Parser header
*/

/* File created the 04/04/2018 at 12:04:34 by julian.frabel@epitech.eu */

#ifndef __PARSER__H_
	#define __PARSER__H_

	#include "parsing.h"

	typedef struct parser_to_game_s parser_to_game_t;

	struct parser_to_game_s {
		int active_scene;
		sf_linked_list_t *dont_destroy_on_unload;
		game_info_t *game_info;
		sf_vector_3d_t player_start_pos;
	};

	parser_to_game_t *create_parser_to_game(char *file_to_parse);
	void destroy_parser_to_game(parser_to_game_t *parser_to_game);

#endif /* !__PARSER__H_ */