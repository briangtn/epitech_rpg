/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** every function in relation with freeing game_info struct and children
*/

#include "my.h"
#include "parsing.h"

void free_tile(tile_info_t **tile)
{
	int i = 0;

	while (tile[i] != NULL)
		i++;
	i--;
	while (i >= 0) {
		free(tile[i]);
		i--;
	}
	free(tile);
}

void free_scene(scene_info_t **scene)
{
	int i = 0;

	while (scene[i] != NULL)
		i++;
	i--;
	while (i >= 0) {
		free_tile(scene[i]->tile);
		free(scene[i]);
		i--;
	}
	free(scene);
}

void free_game_info(game_info_t *game_info)
{
	if (game_info->scene != NULL)
		free_scene(game_info->scene);
	free(game_info);
}