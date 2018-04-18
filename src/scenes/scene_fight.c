/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** The scene for the fighting system
*/

#include "rpg.h"

static int load_fight_scene(sf_engine_t *engine, fight_t *fight)
{
	sf_linked_list_t *current = fight->ennemies;
	sf_vector_2d_t pos = {100, 100};

	create_prefab_fbackground(engine, fight);
	create_prefab_fplayer(engine, fight);
	while (current) {
		create_prefab_fenemy(engine, current->data, pos);
		pos.x += 50;
		current = current->next;
	}
	return (0);
}

static int loop_fight_scene(sf_engine_t *engine, UNUSED void *data)
{
	sfEvent evt;

	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &evt)) {
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
	}
	return (0);
}

static int unload_fight_scene(sf_engine_t *engine, UNUSED void *data)
{
	if (engine == NULL)
		return (84);
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_fight_scene(sf_engine_t *engine, UNUSED fight_t *fight)
{
	sf_scene_t *new_scene = create_scene("fight");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_fight_scene;
	new_scene->loop = &loop_fight_scene;
	new_scene->unload = &unload_fight_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}