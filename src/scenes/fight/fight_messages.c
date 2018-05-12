/*
** EPITECH PROJECT, 2017
** My rpg fight_messages
** File description:
** fight messages
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

char *my_float_to_str(float nb)
{
	int nb_int = (int)nb;
	int after_point = (int)((nb - nb_int) * 100.0);
	char *int_nb = my_int_to_str(nb_int);
	char *float_nb = malloc(sizeof(*float_nb) * (my_strlen(int_nb) + 4));
	int i = 0;

	if (float_nb == NULL)
		return (int_nb);
	for (i = 0; i < my_strlen(int_nb); i++)
		float_nb[i] = int_nb[i];
	float_nb[i++] = '.';
	float_nb[i++] = after_point / 10 + '0';
	float_nb[i++] = after_point % 10 + '0';
	float_nb[i++] = '\0';
	return (float_nb);
}

void ennemy_attack_message(fight_t *fight, fight_enemy_t *enemy)
{
	char *res = my_strdup("You took ");

	my_strdupcat(&res, my_float_to_str(fight->last_attack->damage));
	if (fight->last_attack->damage == 1)
		my_strdupcat(&res, " dmg from ");
	else
		my_strdupcat(&res, " dmgs from ");
	my_strdupcat(&res, enemy->name);
	add_log_message(fight->logs, res);
}

void player_attack_message(fight_t *fight, fight_enemy_t *enemy)
{
	char *res = my_strdup("You did ");

	my_strdupcat(&res, my_float_to_str(fight->last_attack->damage));
	if (fight->last_attack->damage == 1)
		my_strdupcat(&res, " dmg from ");
	else
		my_strdupcat(&res, " dmgs from ");
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