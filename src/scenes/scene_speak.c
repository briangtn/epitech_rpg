/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Scene when player speaking
*/

/* File created the 01/05/2018 at 14:09:21 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include <stdlib.h>
#include "rpg.h"

int load_speak_scene(sf_engine_t *engine, UNUSED void *data)
{
	gameobject_t *border = NULL;
	gameobject_t *background = NULL;

	if (engine == NULL)
		return (84);
	border = create_prefab_image(engine, SPRITE_SPEAK_BORDER, UI_IMAGE);
	calc_go_to_old_camera(engine, border);
	background = create_prefab_image(engine, SPRITE_SPEAK_BG, UI_IMAGE - 2);
	calc_go_to_old_camera(engine, background);
	return (0);
}

int loop_speak_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
		if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeySpace)
			display_next_line(NULL, engine);
	}
	return (0);
}

int unload_speak_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_speak_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("speak");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_speak_scene;
	new_scene->loop = &loop_speak_scene;
	new_scene->unload = &unload_speak_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}