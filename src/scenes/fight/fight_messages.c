/*
** EPITECH PROJECT, 2017
** My rpg fight_messages
** File description:
** fight messages
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

void ennemy_attack_message(fight_t *fight, fight_enemy_t *enemy)
{
	char *res = my_strdup("You take ");

	my_strdupcat(&res, my_int_to_str(fight->last_attack->damage));
	my_strdupcat(&res, " damage from ");
	my_strdupcat(&res, enemy->name);
	add_log_message(fight->logs, res);
}

void player_attack_message(fight_t *fight, fight_enemy_t *enemy)
{
	char *res = my_strdup("You did ");

	my_strdupcat(&res, my_int_to_str(fight->last_attack->damage));
	my_strdupcat(&res, " damage to ");
	my_strdupcat(&res, enemy->name);
	add_log_message(fight->logs, res);
}