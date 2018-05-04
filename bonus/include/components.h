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
	TEST
};

typedef struct grid_component sf_grid_t;

struct test_component {
	void (*destroy)();
	gameobject_t *parent;
	gameobject_t ***grid;
};

int update_test_comp(sf_test_t *component, UNUSED int delta_time);
sf_test_t *create_test_comp(gameobject_t *gameobject);

#endif