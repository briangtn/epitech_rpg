/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Main file for all pause stuff
*/

/* File created the 26/04/2018 at 13:20:28 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "pause.h"

int loop_pause_scene(sf_engine_t *engine)
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
	engine->render(engine);
	return (0);
}

int goto_pause(sf_engine_t *engine)
{
	while (!loop_pause_scene(engine)) {
		continue;
	}
	sfClock_restart(engine->main_clock);
	return (0);
}