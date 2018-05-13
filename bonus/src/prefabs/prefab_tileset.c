/*
** EPITECH PROJECT, 2017
** My rpg Map editor
** File description:
** Tileset prefab
*/

#include "my_sfml.h"
#include "config.h"
#include "prefabs.h"
#include "components.h"

static int setup_grid(sf_grid_t *grid)
{
	sf_linked_list_t *copy = grid->elements;
	sf_map_tile_t *tile = NULL;
	int size = my_sf_list_size(copy);

	for (int i = size - 1; copy; i--) {
		tile = get_component((gameobject_t *)copy->data, MAP_TILE);
		if (tile == NULL)
			return (84);
		tile->tile_id = i;
		copy = copy->next;
	}
	return (0);
}

static int setup_components(gameobject_t *go, sf_engine_t *engine)
{
	sf_tileset_t *tileset = get_component(go, TILESET);
	sfSprite *sprite = get_sprite(engine, ASSET_TILESET);
	sf_grid_t *grid = NULL;
	sfFloatRect bounds;

	if (tileset == NULL || sprite == NULL)
		return (84);
	engine->add_update(engine, go, (UPDATER)&update_tileset_comp);
	bounds = sfSprite_getGlobalBounds(sprite);
	tileset->grid_go = create_prefab_grid(engine,\
	(sfIntRect){WINDOW_SIZE_X - bounds.width - 20, 20,\
	bounds.width / TILE_SIZE, bounds.height / TILE_SIZE}, "grid_tileset");
	grid = get_component(tileset->grid_go, GRID);
	if (grid == NULL)
		return (84);
	if (setup_grid(grid) == 84)
		return (84);
	return (0);
}

static int add_components(gameobject_t *go)
{
	if (go->add_custom_component(go,\
	(void *(*)(gameobject_t *))&create_tileset_comp, TILESET) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_tileset_prefab(sf_engine_t *engine)
{
	gameobject_t *go = create_gameobject("tileset");

	if (go == NULL)
		return (NULL);
	if (add_components(go) == 84 || setup_components(go, engine) == 84)
		return (NULL);
	return (go);
}