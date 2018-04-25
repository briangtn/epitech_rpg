/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** every function in relation with checking parsing values
*/

#include "my.h"
#include "get_next_line.h"
#include "parsing.h"

int check_tile(tile_info_t *tile)
{
	if (tile->tile_id < 0)
		return (tile->tile_id * -1);
	if (tile->tile_pos.x < 0)
		return (tile->tile_pos.x * -1);
	if (tile->event->event_id < 0)
		return (tile->event->event_id * -1);
	if (tile->tile_type < 0)
		return (tile->tile_type * -1);
	if (tile->layer < 0)
		return (tile->tile_type * -1);
	return (0);
}

int check_npc(npc_info_t *npc)
{
	if (npc->npc_id < 0)
		return (npc->npc_id * -1);
	if (npc->npc_pos.x < 0)
		return (npc->npc_pos.x * -1);
	if (npc->event->event_id < 0)
		return (npc->event->event_id * -1);
	return (0);
}

int check_loot(loot_info_t *loot)
{
	if (loot->loot_id < 0)
		return (loot->loot_id * -1);
	if (loot->loot_pos.x < 0)
		return (loot->loot_pos.x * -1);
	if (loot->event->event_id < 0)
		return (loot->event->event_id * -1);
	return (0);
}

scene_info_t *get_scene_info(scene_info_t *scene, int fd, \
game_info_t *game_info)
{
	char *buffer = NULL;

	scene = get_tileset(scene, fd, game_info);
	if (scene == NULL)
		return (NULL);
	scene = get_background(scene, fd, game_info);
	if (scene == NULL)
		return (NULL);
	buffer = get_next_line(fd);
	free(buffer);
	scene = parse_npc_info(scene, fd, game_info);
	if (scene == NULL)
		return (NULL);
	scene = parse_loot_info(scene, fd, game_info);
	if (scene == NULL)
		return (NULL);
	scene = parse_tile_info(scene, fd, game_info);
	if (scene == NULL)
		return (NULL);
	return (scene);
}