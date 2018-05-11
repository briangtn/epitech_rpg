/*
** EPITECH PROJECT, 2017
** My_rpg
** File description:
** End of a fight
*/

#include "my_sfml.h"
#include "rpg.h"

void end_fight(fight_t *fight, sf_engine_t *engine)
{
	bool win = true;

	if (fight == NULL)
		return;
	if (fight->player->life <= 0)
		win = false;
	if (fight->end_callback != NULL)
		fight->end_callback(fight, fight->end_datas, win, engine);
}