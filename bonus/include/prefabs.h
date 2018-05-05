/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** editor
*/

#ifndef __PREFABS_H_
#define __PREFABS_H_

#include "my_sfml.h"

gameobject_t *create_prefab_map_tile(sf_engine_t *engine, int x, int y);
gameobject_t *create_prefab_grid(UNUSED sf_engine_t *engine,\
sfIntRect bounds, char *name);

#endif