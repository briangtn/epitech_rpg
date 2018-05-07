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

void init_grid(sf_engine_t *engine, sf_grid_t *comp, sf_vector_2d_t sizes)
{
	int x = 0;
	int y = 0;
	gameobject_t *new_go = NULL;
	sf_map_tile_t *tile = NULL;

	for (int i = 0; i < sizes.x * sizes.y; i++) {
		x = i % (int)sizes.x;
		y = i / sizes.x;
		new_go = create_prefab_map_tile(engine, x, y);
		tile = get_component(new_go, MAP_TILE);
		if (new_go == NULL || tile == NULL)
			continue;
		comp->elements = sf_push(new_go, my_strdup("map_elem"),\
		comp->elements);
		tile->grid = comp;
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
	comp->engine = NULL;
	return (comp);
}