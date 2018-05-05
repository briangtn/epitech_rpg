/*
** EPITECH PROJECT, 2017
** RPG Map editor
** File description:
** Grid componenet
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "components.h"
#include "config.h"

static void destroy_grid_comp(sf_grid_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

void init_grid(sf_engine_t *engine, sf_grid_t *comp)
{
	int x = 0;
	int y = 0;
	gameobject_t *new_go = NULL;
	sf_animation_2d_t *anim = NULL;

	for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
		x = i % MAP_WIDTH;
		y = i / MAP_WIDTH;
		new_go = create_prefab_map_tile(engine, x, y);
		anim = get_component(new_go, ANIMATION_2D);
		if (new_go == NULL || anim == NULL)
			continue;
		sfSprite_setPosition(anim->sprite, (sfVector2f){x * 50, y * 50});
		comp->elements = sf_push(new_go, my_strdup("map_elem"),\
		comp->elements);
	}
}

sf_grid_t *create_grid_comp(gameobject_t *parent)
{
	sf_grid_t *comp = malloc(sizeof(*comp));

	if (comp == NULL)
		return (NULL);
	comp->destroy = &destroy_grid_comp;
	comp->parent = parent;
	comp->elements = NULL;
	comp->offset = (sf_vector_2d_t){0, 0};
	return (comp);
}