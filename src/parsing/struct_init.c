/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** every function in relation with structure initialization
*/

#include "my.h"
#include "parsing.h"

tile_info_t **realloc_tile(tile_info_t **tile, int nb_arg)
{
	tile_info_t **new_tile = malloc(sizeof(tile_info_t*) * (nb_arg + 1));

	if (new_tile == NULL)
		return (NULL);
	for (int i = 0; i < nb_arg; i++) {
		if ((new_tile[i] = malloc(sizeof(tile_info_t))) == NULL)
			return (NULL);
		if (tile != NULL && tile[i] != NULL) {
			new_tile[i]->tile_id = tile[i]->tile_id;
			new_tile[i]->tile_pos = tile[i]->tile_pos;
			new_tile[i]->event_id = tile[i]->event_id;
			new_tile[i]->tile_type = tile[i]->tile_type;
			new_tile[i]->layer = tile[i]->layer;
		}
	}
	new_tile[nb_arg] = NULL;
	for (int i = 0; tile != NULL && tile[i] != NULL; i++)
		free(tile[i]);
	if (tile != NULL)
		free(tile);
	return (new_tile);
}

scene_info_t **init_scene(int nb_scene)
{
	scene_info_t **scene = malloc(sizeof(scene_info_t*) * (nb_scene + 1));

	if (scene == NULL)
		return (NULL);
	for (int i = 0; i < nb_scene; i++) {
		scene[i] = malloc(sizeof(scene_info_t));
		if (scene[i] == NULL)
			return (NULL);
	}
	scene[nb_scene] = NULL;
	return (scene);
}

game_info_t *init_game_info(void)
{
	game_info_t *game_info = malloc(sizeof(game_info_t));

	if (game_info == NULL)
		return (NULL);
	game_info->nb_scene = 0;
	game_info->tile_per_scene = (sfVector2i){0, 0};
	game_info->scene = NULL;
	return (game_info);
}