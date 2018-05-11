/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fighting file
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

void enemy_attack(UNUSED sf_engine_t *engine,\
fight_t *fight, fight_enemy_t *enemy)
{
	int attack_count = my_sf_list_size(enemy->attacks);
	int attack_index = rand() % attack_count;
	sf_linked_list_t *elem = get_elem_at_index(attack_index,\
enemy->attacks);

	if (elem == NULL)
		return;
	fight->last_attack = (attack_t *)elem->data;
	fight->player->life -= fight->last_attack->damage;
	ennemy_attack_message(fight, enemy);
}

void enemy_turn(sf_engine_t *engine, fight_t *fight)
{
	sf_linked_list_t *copy = fight->ennemies;

	while (copy) {
		enemy_attack(engine, fight, (fight_enemy_t *)copy->data);
		copy = copy->next;
	}
	if (fight->player->life <= 0) {
		end_fight(fight, engine);
		return;
	}
	select_attack(engine, fight, true);
}

static int when_enemy_selected(void *data, sf_linked_list_t *elem,\
sf_fight_arrow_t *arrow)
{
	fight_t *fight = (fight_t *)data;
	fight_enemy_t *enemy = (fight_enemy_t *)elem->data;
	sf_engine_t *engine = NULL;

	if (fight == NULL || enemy == NULL)
		return (84);
	engine = arrow->engine;
	enemy->life -= fight->last_attack->damage;
	fight->player->mana -= fight->last_attack->mana_cost;
	player_attack_message(fight, enemy);
	if (enemy->life <= 0) {
		destroy_enemy(engine, enemy->go);
		sf_remove_node(elem, &fight->ennemies);
	}
	if (enemy_is_dead(fight, engine, arrow))
		return (0);
	engine->destroy_gameobject(engine, arrow->parent);
	return (0);
}

void select_attack(sf_engine_t *engine, fight_t *fight, bool new_round)
{
	if (new_round) {
		if (fight->player->curr_max_mana < fight->player->max_mana)
			fight->player->curr_max_mana++;
		fight->player->mana = fight->player->curr_max_mana;
	}
	create_prefab_fattack_menu(engine, fight);
}

void select_enemy(sf_engine_t *engine, fight_t *fight)
{
	gameobject_t *go = create_prefab_farrow(engine,\
fight->ennemies, &when_enemy_selected, "assets/spritesheets/arrow.png");
	sf_fight_arrow_t *arrow = get_component(go, FARROW);

	if (arrow == NULL)
		return;
	arrow->callback_param = fight;
}