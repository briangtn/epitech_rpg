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

static int load_game_scene(sf_engine_t *engine, UNUSED void *data)
{
	sf_camera_t *camera = engine->current_scene->camera;
	gameobject_t *player = NULL;

	if (engine == NULL || camera == NULL)
		return (84);
	player = create_prefab_player(engine);
	camera->scene_size = (sfIntRect){0, 0, 2000, 2000};
	camera->target = player;
	camera->follow_target = true;
	initialize_physic_state(engine);
	return (0);
}

static int handle_key_pressed(sf_engine_t *engine)
{
	gameobject_t *player = engine->get_gameobject(engine, "player");
	sf_rigidbody_2d_t *rb = get_component(player, RIGIDBODY_2D);
	sfVector2f axis = (sfVector2f){0, 0};

	if (player == NULL || rb == NULL) {
		my_puterror("PLAYER NOT FOUND!\n");
		return (84);
	}
	axis.x = sfKeyboard_isKeyPressed(72) - sfKeyboard_isKeyPressed(71);
		rb->speed.x = 32 * axis.x * 2;
	axis.y = sfKeyboard_isKeyPressed(74) - sfKeyboard_isKeyPressed(73);
		rb->speed.y = 32 * axis.y * 2;
	return (0);
}

static int loop_game_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
	}
	handle_key_pressed(engine);
	return (0);
}

static int unload_game_scene(sf_engine_t *engine, UNUSED void *data)
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