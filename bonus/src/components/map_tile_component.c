/*
** EPITECH PROJECT, 2017
** My rpg map editor
** File description:
** Map tile component
*/

#include <stdlib.h>
#include "components.h"

static void destroy_comp(sf_map_tile_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

sf_map_tile_t *create_map_tile_comp(gameobject_t *parent)
{
	sf_map_tile_t *tile = malloc(sizeof(*tile));

	if (tile == NULL)
		return (NULL);
	tile->destroy = &destroy_comp;
	tile->parent = parent;
	tile->x = 0;
	tile->y = 0;
	tile->tile_id = -1;
	return (tile);
}