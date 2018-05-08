/*
** EPITECH PROJECT, 2017
** My_rp
** File description:
** Fights
*/

#include "my_sfml.h"
#include "rpg.h"

int run_fight(int id, sf_engine_t *engine)
{
	return (FIGHTS_ID[id - 1](engine));
}

int first_fight(sf_engine_t *engine)
{
	fight_t *fight = NULL;
	fight_enemy_t *enemy = NULL;
	fight_player_t *player = NULL;
	sf_linked_list_t *attacks = NULL;
	sf_linked_list_t *eattacks = NULL;

	add_attack(&attacks, "SwordAttack", 1, 1);
	player = create_fight_player("assets/faces/player.png", attacks);
	fight = create_fight(BACKGROUND_FIGHT_PATH, player);
	add_attack(&eattacks, "SwordAttack", 1, 1);
	enemy = create_enemy(5, ENEMY_ROGUE, "Rogue1", eattacks);
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	enemy = create_enemy(5, ENEMY_ROGUE, "Rogue2", eattacks);
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	engine->change_scene(engine, "fight", fight);
	return (0);
}