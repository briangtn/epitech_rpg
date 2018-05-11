/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Fight callback
*/

/* File created the 11/05/2018 at 10:37:34 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "rpg.h"

int end_fight_win(sf_engine_t *engine, gameobject_t *player)
{
	dprintf(2, "You win\n");
	return (0);
}

int end_fight_lose(sf_engine_t *engine, gameobject_t *player)
{
	dprintf(2, "You lose\n");
	return (0);
}

int end_callback_fight(fight_t *fight, void *datas,\
bool win, sf_engine_t *engine)
{
	parser_to_game_t *ptg = engine->data;

	if (datas == NULL || ptg == NULL)
		return (84);
	if (win) {
		end_fight_win(engine, datas);
	} else {
		end_fight_lose(engine, datas);
	}
	return (engine->change_scene(engine, "game", ptg));
}