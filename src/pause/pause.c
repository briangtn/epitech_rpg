/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Main file for all pause stuff
*/

/* File created the 26/04/2018 at 13:20:28 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "pause.h"

int goto_pause(sf_engine_t *engine)
{
	engine->pause.is_paused = true;
	engine->pause.scene_before_pause = engine->current_scene;
	engine->current_scene = engine->get_scene(engine, "pause");
	load_pause_scene(engine, NULL);
	return (0);
}

int quit_pause(sf_engine_t *engine)
{
	unload_pause_scene(engine, NULL);
	engine->current_scene = engine->pause.scene_before_pause;
	engine->pause.scene_before_pause = NULL;
	engine->pause.is_paused = false;
	return (0);
}