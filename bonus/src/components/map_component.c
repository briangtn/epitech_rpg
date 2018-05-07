/*
** EPITECH PROJECT, 2017
** My rpg map editor
** File description:
** Map component
*/

#include <stdlib.h>
#include "config.h"
#include "components.h"

static int select_tile(gameobject_t *go, sfVector2i mpos,\
sf_tileset_t *tileset)
{
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_map_tile_t *tile = get_component(go, MAP_TILE);
	sfVector2f pos;

	if (anim == NULL || tile == NULL)
		return (84);
	pos = sfSprite_getPosition(anim->sprite);
	if (mpos.x >= pos.x && mpos.y >= pos.y && \
	mpos.x <= pos.x + TILE_SIZE && mpos.y <= pos.y + TILE_SIZE) {
		tile->tile_id = tileset->selected_tile_id;
	}
	return (0);
}

int update_map_comp(sf_map_t *map, UNUSED int delta_time)
{
	sfVector2i mpos;
	sf_linked_list_t *copy = map->grid->elements;
	sf_tileset_t *tileset = get_component(map->tileset_go, TILESET);

	if (!sfMouse_isButtonPressed(0))
		return (0);
	while (copy) {
		mpos = sfMouse_getPosition(\
		(sfWindow *)map->grid->engine->window);
		if (select_tile((gameobject_t *)copy->data,\
		mpos, tileset) == 84)
			return (84);
		copy = copy->next;
	}
	return (0);
}

static void destroy_component(sf_map_t *map)
{
	if (map == NULL)
		return;
	free(map);
}

sf_map_t *create_map_comp(gameobject_t *parent)
{
	sf_map_t *map = malloc(sizeof(*map));

	if (map == NULL)
		return (NULL);
	map->destroy = &destroy_component;
	map->parent = parent;
	map->grid = NULL;
	map->tileset_go = NULL;
	return (map);
}