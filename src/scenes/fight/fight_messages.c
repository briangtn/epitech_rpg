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

int enemy_is_dead(fight_t *fight, sf_engine_t *engine, sf_fight_arrow_t *arrow)
{
	if (my_sf_list_size(fight->ennemies) == 0) {
		engine->destroy_gameobject(engine, arrow->parent);
		my_putstr("debug\n");
		end_fight(fight, engine);
		my_putstr("debug1\n");
		return (1);
	}
	if (fight->player->mana > 0)
		select_attack(engine, fight, false);
	else
		enemy_turn(engine, fight);
	return (0);
}