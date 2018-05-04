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

int teleport(gameobject_t *tile, UNUSED gameobject_t *player)
{
	sf_tile_effect_t *effect = get_component(tile, TILE_EFFECT);
	parser_to_game_t *ptg = effect->engine->data;

	if (effect == NULL || ptg == NULL)
		return (84);
	ptg->player_start_pos = (sf_vector_3d_t){effect->teleport_coords.x, \
effect->teleport_coords.y, 0};
	ptg->active_scene = effect->teleport_scene;
	effect->engine->change_scene(effect->engine, "game", ptg);
	return (0);
}