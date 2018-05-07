/*
** EPITECH PROJECT, 2017
** My rpg map editor
** File description:
** Tile set updater
*/

#include "my_sfml.h"
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
		tileset->selected_tile_id = tile->tile_id;
	}
	return (0);
}

static int click_detection_update(sf_grid_t *grid, sf_tileset_t *tileset)
{
	sf_linked_list_t *copy = grid->elements;
	gameobject_t *go = NULL;
	sfVector2i mouse_pos;

	if (!sfMouse_isButtonPressed(0))
		return (0);
	while (copy) {
		mouse_pos = sfMouse_getPosition(\
		(sfWindow *)grid->engine->window);
		go = (gameobject_t *)copy->data;
		if (select_tile(go, mouse_pos, tileset) == 84)
			return (84);
		copy = copy->next;
	}
	return (0);
}

static int set_tile_color(gameobject_t *go)
{
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
	click_detection_update(grid, tileset);
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