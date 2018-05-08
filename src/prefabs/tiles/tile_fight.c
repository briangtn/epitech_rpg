/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Fights
*/

/* File created the 08/05/2018 at 17:12:40 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "prefabs.h"
#include "parser.h"
#include "rpg.h"

int fight(gameobject_t *tile, UNUSED gameobject_t *player)
{
	sf_tile_effect_t *effect = get_component(tile, TILE_EFFECT);

	if (effect == NULL)
		return (84);
	run_fight(effect->fight_id, effect->engine);
	return (0);
}

void set_fight_tile(sf_collider_2d_t *col, sf_tile_effect_t *effect, \
tile_info_t *info)
{
	if (info->event->fight_id > NB_FIGHTS_ID)
		return;
	col->triggered_func = &fight;
	effect->fight_id = info->event->fight_id;
}