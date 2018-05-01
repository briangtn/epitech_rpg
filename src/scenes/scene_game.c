/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Game scene
*/

/* File created the 04/04/2018 at 13:48:08 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static int load_game_scene(sf_engine_t *engine, parser_to_game_t *data)
{
	sf_camera_t *camera = engine->current_scene->camera;
	gameobject_t *player = NULL;

	if (engine == NULL || camera == NULL || data == NULL)
		return (84);
	player = create_prefab_player(engine);
	((sf_transform_t *)get_component(player, TRANSFORM))->position.x = 100;
	camera->target = player;
	camera->follow_target = true;
	initialize_physic_state(engine);
	load_parsing_to_game_scene(data, engine);
	create_prefab_npc(engine);
	destroy_parser_to_game(data);
	return (0);
}

static void handle_key_pressed(sf_engine_t *engine, sfEvent evt)
{
	gameobject_t *player = engine->get_gameobject(engine, "player");

	if (player == NULL)
		return;
	if (evt.key.code == sfKeySpace)
		run_interactions(engine, player);
	if (evt.key.code == sfKeyEscape)
		goto_pause(engine, "pause");
}

static int loop_game_scene(sf_engine_t *engine, UNUSED parser_to_game_t *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
		if (evt.type == sfEvtKeyPressed)
			handle_key_pressed(engine, evt);
	}
	return (0);
}

static int unload_game_scene(sf_engine_t *engine, UNUSED parser_to_game_t *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_game_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("game");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_game_scene;
	new_scene->loop = &loop_game_scene;
	new_scene->unload = &unload_game_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}