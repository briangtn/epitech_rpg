/*
** EPITECH PROJECT, 2017
** My rpg map editor
** File description:
** Map tile component
*/

#include <stdlib.h>
#include "components.h"
#include "config.h"

sfIntRect get_default_rect(sfSprite *sprite)
{
	sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
	sfIntRect res = {0, 0, bounds.width, bounds.height};

	return (res);
}

sfVector2f tile_id_to_pos(int tile_id, sfSprite *sprite)
{
	sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
	sfVector2f res;

	bounds.width /= TILE_SIZE;
	bounds.height /= TILE_SIZE;
	res.x = tile_id % (int)bounds.width;
	res.y = tile_id / (int)bounds.width;
	return (res);
}

int map_tile_update(gameobject_t *go, UNUSED int delta_time)
{
	sf_map_tile_t *tile = get_component(go, MAP_TILE);
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	float scale = (float)TILE_SIZE / 50;
	sfVector2f tile_pos = {0, 0};
	sf_vector_2d_t off = tile->grid->offset;

	if (tile == NULL || anim == NULL || tile->engine == NULL)
		return (84);
	if (tile->tile_id == -1) {
		anim->sprite = tile->sprite_none;
		sfSprite_setScale(anim->sprite, (sfVector2f){scale, scale});
	} else {
		anim->sprite = get_sprite(tile->engine, \
"assets/tilesets/outside_b.png");
		tile_pos = tile_id_to_pos(tile->tile_id, anim->sprite);
		sfSprite_setTextureRect(anim->sprite, (sfIntRect){tile_pos.x * \
TILE_SIZE, tile_pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE});
	}
	sfSprite_setPosition(anim->sprite,\
	(sfVector2f){off.x + tile->x * TILE_SIZE, off.y + tile->y * TILE_SIZE});
	return (0);
}

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
	tile->grid = NULL;
	tile->engine = NULL;
	tile->sprite_none = NULL;
	tile->sprite_tileset = NULL;
	return (tile);
}