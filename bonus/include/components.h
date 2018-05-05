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
	GRID
};

typedef struct grid_component {
	void (*destroy)();
	gameobject_t *parent;
	sf_linked_list_t *elements;
	sf_vector_2d_t offset;
} sf_grid_t;

sf_grid_t *create_grid_comp(gameobject_t *parent);
void init_grid(sf_engine_t *engine, sf_grid_t *comp);

#endif