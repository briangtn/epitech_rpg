/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Scene management
*/

#include <stdlib.h>
#include "my_sfml_engine.h"

int add_scene(sf_engine_t *engine, sf_scene_t *scene)
{
	if (engine == NULL || scene == NULL)
		return (84);
	if (scene->camera == NULL)
		scene->camera = create_new_camera(engine->window);
	engine->scenes = sf_push(scene, my_strdup(scene->name), engine->scenes);
	return (0);
}

sf_scene_t *get_scene(sf_engine_t *engine, const char *name)
{
	if (engine == NULL || name == NULL)
		return (NULL);
	return ((sf_scene_t *)get_data(name, engine->scenes));
}

static void set_camera_scene(sf_engine_t *engine)
{
	if (!engine->current_scene || !engine->current_scene->camera)
		return;
	if (engine->current_scene->camera->update != NULL) {
		engine->add_update(engine, (void *)engine->current_scene->\
camera, (UPDATER)engine->current_scene->camera->update);
		my_putdebug("[DEBUG]Added camera Updater!\n");
	}
	if (engine->current_scene->camera->camera_view != NULL) {
		sfRenderWindow_setView(engine->window, \
engine->current_scene->camera->camera_view);
		my_putdebug("[DEBUG]View Set!\n");
	}
}

int update_selected_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = get_scene(engine, engine->next_scene);

	if (engine == NULL || engine->next_scene == NULL || new_scene == NULL) {
		if (new_scene == NULL) {
			my_putdebug("[ERROR]Requested scene not found:");
			my_putdebug(engine->next_scene);
		}
		return (84);
	}
	if (engine->current_scene && engine->current_scene->unload)
		engine->current_scene->unload(engine, engine->data);
	engine->remove_update(engine, (engine->current_scene) ? \
(void *)engine->current_scene->camera : NULL);
	engine->current_scene = new_scene;
	if (engine->current_scene && engine->current_scene->load)
		engine->current_scene->load(engine, engine->data);
	set_camera_scene(engine);
	free(engine->next_scene);
	engine->next_scene = NULL;
	engine->scene_changed = true;
	return (0);
}

int change_scene(sf_engine_t *engine, const char *name, void *data)
{
	engine->next_scene = my_strdup(name);
	if (data)
		engine->data = data;
	return (0);
}