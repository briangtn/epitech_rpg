/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** help scene
*/

/* File created the 26/04/2018 at 14:15:02 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

int load_help_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	create_prefab_image(engine, BACKGROUND_HELP, 0);
	return (0);
}

int loop_help_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed) {
			sfRenderWindow_close(engine->window);
			return (0);
		}
		if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
			return (quit_pause(engine));
	}
	return (0);
}

int unload_help_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_help_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("help");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_help_scene;
	new_scene->loop = &loop_help_scene;
	new_scene->unload = &unload_help_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}