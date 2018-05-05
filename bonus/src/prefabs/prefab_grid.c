/*
** EPITECH PROJECT, 2017
** RPG map editor
** File description:
** The prefab of main grid
*/

#include "my_sfml.h"
#include "components.h"

static int setup_components(sf_engine_t *engine, gameobject_t *go)
{
	sf_grid_t *grid = get_component(go, GRID);

	if (grid == NULL)
		return (84);
	init_grid(engine, grid);
	return (0);
}

static int add_components(gameobject_t *go)
{
	if (go->add_custom_component(go,\
	(void *(*)(gameobject_t *))&create_grid_comp, GRID) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_grid(UNUSED sf_engine_t *engine)
{
	gameobject_t *go = create_gameobject("map_grid");

	if (go == NULL)
		return (NULL);
	if (add_components(go) == 84 ||setup_components(engine, go) == 84)
		return (NULL);
	return (go);
}