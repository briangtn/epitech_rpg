/*
** EPITECH PROJECT, 2017
** My Rpg Map editor
** File description:
** Component for tileset
*/

#include <stdlib.h>
#include "components.h"

static int set_tile_color(gameobject_t *go)
{
	sf_map_tile_t *tile = get_component(go, MAP_TILE);
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);

	if (anim == NULL)
		return (84);
	sfSprite_setColor(anim->sprite, sfGreen);
	return (0);
}

int update_tileset_comp(gameobject_t *go, UNUSED int delta_time)
{
	sf_tileset_t *tileset = get_component(go, TILESET);
	sf_grid_t *grid = NULL;
	gameobject_t *tmp_go = NULL;
	sf_map_tile_t *tile = NULL;
	sf_linked_list_t *copy = NULL;

	if (tileset == NULL)
		return (84);
	grid = get_component(tileset->grid_go, GRID);
	if (grid == NULL)
		return (84);
	copy = grid->elements;
	while (copy) {
		tmp_go = (gameobject_t *)copy->data;
		tile = get_component(tmp_go, MAP_TILE);
		if (tile != NULL && tile->tile_id == tileset->selected_tile_id)
			set_tile_color(tmp_go);
		copy = copy->next;
	}
	return (0);
}

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
	tileset->selected_tile_id = 1;
	return (tileset);
}