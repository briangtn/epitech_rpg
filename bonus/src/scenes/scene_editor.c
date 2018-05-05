/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map editor
*/

#include "my.h"
#include "my_sfml.h"
#include "config.h"

static int unload_editor_scene(sf_engine_t *engine, UNUSED void *data)
{
	reset_scene(engine->current_scene);
	return (0);
}

static int loop_editor_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(engine->window, &event))
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
	return (0);
}

static int set_tileset_grid(sf_engine_t *engine)
{
	sfSprite *sprite = get_sprite(engine, "assets/tilesets/outside_b.png");
	sfFloatRect bounds;
	gameobject_t *go = NULL;
	sf_grid_t *grid = NULL;
	sf_map_tile_t *tile = NULL;
	sf_linked_list_t *copy = NULL;

	if (sprite == NULL)
		return (84);
	bounds = sfSprite_getGlobalBounds(sprite);
	go = create_prefab_grid(engine,\
	(sfIntRect){WINDOW_SIZE_X - bounds.width - 20, 20,\
	bounds.width / TILE_SIZE, bounds.height / TILE_SIZE}, "grid_tileset");
	grid = get_component(go, GRID);
	if (grid == NULL)
		return (84);
	copy = grid->elements;
	for (int i = 0; copy; i++) {
		tile = get_component((gameobject_t *)copy->data, MAP_TILE);
		tile->tile_id = i;
		copy = copy->next;
	}
	return (0);
}

static int load_editor_scene(sf_engine_t *engine, UNUSED void *data)
{
	create_prefab_grid(engine, (sfIntRect){20, 20, MAP_WIDTH, MAP_HEIGHT},\
	"map_grid");
	set_tileset_grid(engine);
	return (0);
}

sf_scene_t *create_editor_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("editor");

	if (new_scene == NULL)
		return (NULL);
	new_scene->load = &load_editor_scene;
	new_scene->loop = &loop_editor_scene;
	new_scene->unload = &unload_editor_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}
