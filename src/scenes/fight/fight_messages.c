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
	char *res = my_strdup("You took ");

	my_strdupcat(&res, my_int_to_str(fight->last_attack->damage));
	if (fight->last_attack->damage == 1)
		my_strdupcat(&res, " damage from ");
	else
		my_strdupcat(&res, " damages from ");
	my_strdupcat(&res, enemy->name);
	add_log_message(fight->logs, res);
}

void player_attack_message(fight_t *fight, fight_enemy_t *enemy)
{
	char *res = my_strdup("You did ");

	my_strdupcat(&res, my_int_to_str(fight->last_attack->damage));
	if (fight->last_attack->damage == 1)
		my_strdupcat(&res, " damage from ");
	else
		my_strdupcat(&res, " damages from ");
	my_strdupcat(&res, enemy->name);
	add_log_message(fight->logs, res);
}

int enemy_is_dead(fight_t *fight, sf_engine_t *engine, sf_fight_arrow_t *arrow)
{
	if (my_sf_list_size(fight->ennemies) == 0) {
		if (fight->end_callback == NULL)
			engine->destroy_gameobject(engine, arrow->parent);
		end_fight(fight, engine);
		return (1);
	}
	if (fight->player->mana > 0)
		select_attack(engine, fight, false);
	else
		enemy_turn(engine, fight);
	return (0);
}