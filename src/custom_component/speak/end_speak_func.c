/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Functions run at the end of a speak
*/

/* File created the 10/05/2018 at 13:50:28 by julian.frabel@epitech.eu */

#include "rpg.h"

int king_end_game(sf_engine_t *engine, UNUSED gameobject_t *parent)
{
	return (engine->change_scene(engine, "end", engine->data));
}

int evil_king_fight(sf_engine_t *engine, gameobject_t *parent)
{
	run_fight(2, engine, parent);
	return (0);
}