/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Teleport trigger
*/

/* File created the 03/05/2018 at 16:01:42 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "prefabs.h"
#include "parser.h"
#include "rpg.h"

int teleport(gameobject_t *tile, UNUSED gameobject_t *player)
{
	sf_tile_effect_t *effect = get_component(tile, TILE_EFFECT);
	parser_to_game_t *ptg = effect->engine->data;

	if (effect == NULL || ptg == NULL)
		return (84);
	ptg->player_start_pos = (sf_vector_3d_t){(effect->teleport_coords.x - 1\
) * TILE_SIZE, (effect->teleport_coords.y - 1) * TILE_SIZE, 0};
	ptg->active_scene = effect->teleport_scene;
	effect->engine->change_scene(effect->engine, "game", ptg);
	return (0);
}

void set_teleport_tile(sf_collider_2d_t *col, sf_tile_effect_t *effect, \
tile_info_t *info)
{
	col->triggered_func = &teleport;
	effect->teleport_scene = info->event->teleport[0];
	effect->teleport_coords = (sfVector2i){info->event->teleport[1]\
, info->event->teleport[2]};
}