/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** every function in relation with freeing game_info struct and children
*/

#include "my.h"
#include "parsing.h"

void free_loot(loot_info_t **loot)
{
	int i = 0;

	while (loot[i] != NULL)
		i++;
	i--;
	while (i >= 0) {
		free(loot[i]);
		i--;
	}
	free(loot);
}

void free_npc(npc_info_t **npc)
{
	int i = 0;

	while (npc[i] != NULL)
		i++;
	i--;
	while (i >= 0) {
		free(npc[i]);
		i--;
	}
	free(npc);
}

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
		if (scene[i]->tile != NULL)
			free_tile(scene[i]->tile);
		if (scene[i]->npc != NULL)
			free_npc(scene[i]->npc);
		if (scene[i]->loot != NULL)
			free_loot(scene[i]->loot);
		if (scene[i]->tileset != NULL)
			free(scene[i]->tileset);
		if (scene[i]->background != NULL)
			free(scene[i]->background);
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