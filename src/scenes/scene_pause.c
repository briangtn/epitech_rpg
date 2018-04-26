/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Pause scene
*/

/* File created the 26/04/2018 at 14:15:02 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

int load_pause_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	create_prefab_image(engine, SPRITE_BORDER, 0);
	return (0);
}

int loop_pause_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	engine->pause.scene_before_pause->graphical_engine->render(\
engine->pause.scene_before_pause->graphical_engine, engine->window);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
		if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
			quit_pause(engine);
	}
	return (0);
}

int unload_pause_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_pause_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("pause");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_pause_scene;
	new_scene->loop = &loop_pause_scene;
	new_scene->unload = &unload_pause_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}