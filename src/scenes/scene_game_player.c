/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Scene game player
*/

/* File created the 11/05/2018 at 17:23:13 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

gameobject_t *init_scene_game_player(sf_engine_t *engine)
{
	gameobject_t *player = NULL;

	player = create_prefab_player(engine);
	engine->add_audio(engine, MUSIC_GAME, true);
	engine->play(engine, MUSIC_GAME);
	return (player);
}

int comming_from_fight(sf_engine_t *engine, parser_to_game_t *data)
{
	data->come_from_fight = false;
	engine->play(engine, MUSIC_GAME);
	return (0);
}

void reset_scene_except_go(sf_engine_t *engine)
{
	sf_linked_list_t *curr_go = engine->current_scene->gameobjects;
	sf_linked_list_t *next = NULL;
	gameobject_t *go = NULL;

	while (curr_go != NULL) {
		next = curr_go->next;
		go = curr_go->data;
		if (my_strcmp(go->name, "player"))
			engine->destroy_gameobject(engine, go);
		curr_go = next;
	}
	engine->current_scene->graphical_engine->particle_manager->destroy(\
engine->current_scene->graphical_engine->particle_manager);
	engine->current_scene->graphical_engine->particle_manager = \
create_manager();
	engine->remove_update(engine, engine->current_scene->physic_engine);
}