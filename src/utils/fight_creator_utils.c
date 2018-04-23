/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fight creator utils
*/

#include <stdlib.h>
#include "rpg.h"

fight_enemy_t *create_enemy(int life, char *path, char *name)
{
	fight_enemy_t *enemy = malloc(sizeof(*enemy));

	enemy->life = life;
	enemy->sprite_path = path;
	enemy->name = name;
	enemy->go = NULL;
	return (enemy);
}

fight_t *create_fight(char *path, fight_player_t player)
{
	fight_t *fight = malloc(sizeof(*fight));

	fight->background_path = path;
	fight->player = player;
	fight->ennemies = NULL;
	return (fight);
}