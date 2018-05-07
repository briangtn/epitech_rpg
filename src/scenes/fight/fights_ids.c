/*
** EPITECH PROJECT, 2017
** My_rp
** File description:
** Fights
*/

#include "my_sfml.h"
#include "rpg.h"

int (*fights[])() = {
	&first_fight
};

int run_fight(int id)
{
	fights[id - 1]();
}

int first_fight()
{
	//fight_player_t *player =  create_fight_player();
	//fight_t *fight = create_fight();
}