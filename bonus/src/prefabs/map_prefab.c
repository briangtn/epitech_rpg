/*
** EPITECH PROJECT, 2017
** My rpg map editor
** File description:
** Map prefab
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "config.h"

static int setup_components(sf_engine_t *engine, gameobject_t *go, \
gameobject_t *tileset_go)
{
	sf_map_t *map = get_component(go, MAP);
	gameobject_t *grid_go = NULL;

	if (map == NULL)
		return (84);
	grid_go = create_prefab_grid(engine, (sfIntRect){20, 20,\
	MAP_WIDTH, MAP_HEIGHT}, "map_grid");
	map->grid = get_component(grid_go, GRID);
	if (map->grid == NULL)
		return (84);
	map->tileset_go = tileset_go;
	return (0);
}

static int add_components(gameobject_t *go)
{
	if (go->add_custom_component(go,\
	(void *(*)(gameobject_t *))&create_map_comp, MAP) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_map_prefab(sf_engine_t *engine, gameobject_t *tileset_go)
{
	gameobject_t *go = create_gameobject("map");

	if (go == NULL)
		return (NULL);
	if (add_components(go) == 84 ||\
	setup_components(engine, go, tileset_go) == 84)
		return (NULL);
	engine->add_update(engine, get_component(go, MAP), \
(UPDATER)&update_map_comp);
	return (go);
}