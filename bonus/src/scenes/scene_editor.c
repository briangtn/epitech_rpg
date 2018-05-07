/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map editor
*/

#include "my.h"
#include "my_sfml.h"
#include "prefabs.h"
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

static int load_editor_scene(sf_engine_t *engine, UNUSED void *data)
{
	gameobject_t *tileset_go = create_tileset_prefab(engine);
	create_map_prefab(engine, tileset_go);
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
