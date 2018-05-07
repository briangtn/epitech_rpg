/*
** EPITECH PROJECT, 2017
** My Rpg Map editor
** File description:
** Component for tileset
*/

#include <stdlib.h>
#include "config.h"
#include "components.h"

static void destroy_comp(sf_tileset_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

sf_tileset_t *create_tileset_comp(gameobject_t *go)
{
	sf_tileset_t *tileset = malloc(sizeof(*tileset));

	if (go == NULL || tileset == NULL)
		return (NULL);
	tileset->destroy = &destroy_comp;
	tileset->parent = go;
	tileset->grid_go = NULL;
	tileset->selected_tile_id = 0;
	return (tileset);
}