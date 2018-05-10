/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** Change the parsed file to something interpretable by the program
*/

/* File created the 23/04/2018 at 16:49:33 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "rpg.h"

parser_to_game_t *create_parser_to_game(char *file_to_parse)
{
	parser_to_game_t *ptg = malloc(sizeof(*ptg));

	if (ptg == NULL)
		return (NULL);
	ptg->active_scene = 1;
	ptg->player_start_pos = (sf_vector_3d_t){23 * TILE_SIZE, \
11 * TILE_SIZE, 0};
	ptg->dont_destroy_on_unload = NULL;
	ptg->game_info = parse_config(file_to_parse);
	ptg->fight = NULL;
	if (ptg->game_info == NULL) {
		destroy_parser_to_game(ptg);
		return (NULL);
	}
	return (ptg);
}

void destroy_parser_to_game(parser_to_game_t *parser_to_game)
{
	sf_linked_list_t *curr = NULL;

	if (parser_to_game == NULL)
		return;
	if (parser_to_game->game_info != NULL)
		free_game_info(parser_to_game->game_info);
	curr = parser_to_game->dont_destroy_on_unload;
	while (curr != NULL) {
		((gameobject_t *)curr->data)->destroy(curr->data);
		curr = parser_to_game->dont_destroy_on_unload;
		sf_remove_node(parser_to_game->dont_destroy_on_unload, \
&(parser_to_game->dont_destroy_on_unload));
	}
	free(parser_to_game);
}