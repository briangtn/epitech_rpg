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
	create_prefab_image(engine, SPRITE_BORDER, BACKGROUND);
	return (0);
}

int loop_pause_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
		if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
			return (1);
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