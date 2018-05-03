/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Create and destroy tile effect component
*/

/* File created the 03/05/2018 at 16:12:04 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "prefabs.h"
#include "my_sfml.h"

void destroy_tile_effect(sf_tile_effect_t *effect)
{
	if (effect == NULL)
		return;
	free(effect);
}

sf_tile_effect_t *create_tile_effect(gameobject_t *parent)
{
	sf_tile_effect_t *effect = malloc(sizeof(*effect));

	effect->parent = parent;
	effect->destroy = &destroy_tile_effect;
	effect->engine = NULL;
	effect->teleport_coords = (sfVector2i){0, 0};
	effect->teleport_scene = 1;
	return (effect);
}