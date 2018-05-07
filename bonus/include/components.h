/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** editor
*/

#ifndef __COMPONENTS_H_
#define __COMPONENTS_H_

#include "my_sfml.h"

enum component_types {
	GRID,
	MAP_TILE,
	TILESET
};

typedef struct grid_component {
	void (*destroy)();
	gameobject_t *parent;
	sf_linked_list_t *elements;
	sf_vector_2d_t offset;
} sf_grid_t;

sf_grid_t *create_grid_comp(gameobject_t *parent);
void init_grid(sf_engine_t *engine, sf_grid_t *comp, sf_vector_2d_t sizes);

typedef struct map_tile_component {
	void (*destroy)();
	gameobject_t *parent;
	sf_grid_t *grid;
	int x;
	int y;
	int tile_id;
	sf_engine_t *engine;
	sfSprite *sprite_none;
	sfSprite *sprite_tileset;
} sf_map_tile_t;

sf_map_tile_t *create_map_tile_comp(gameobject_t *parent);
int map_tile_update(gameobject_t *go, UNUSED int delta_time);

typedef struct tileset_component {
	void (*destroy)();
	gameobject_t *parent;
	gameobject_t *grid_go;
	int selected_tile_id;
} sf_tileset_t;

int update_tileset_comp(gameobject_t *go, UNUSED int delta_time);
sf_tileset_t *create_tileset_comp(gameobject_t *go);

#endif