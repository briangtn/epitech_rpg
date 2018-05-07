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

int run_fight(int id, sf_engine_t *engine)
{
	return (fights[id - 1](engine));
}

int first_fight(sf_engine_t *engine)
{
	fight_t *fight = NULL;
	fight_enemy_t *enemy = NULL;
	fight_player_t *player = NULL;
	sf_linked_list_t *attacks = NULL;
	sf_linked_list_t *eattacks = NULL;

	add_attack(&attacks, "AttaqueKiTuTou", 10, 10);
	add_attack(&attacks, "MegaAttack", 4, 5);
	add_attack(&attacks, "SuperAttack", 2, 1);
	player = create_fight_player("assets/faces/player.png", attacks);
	fight = create_fight("assets/test.png", player);
	add_attack(&eattacks, "EnnemyAttack3", 3, 3);
	add_attack(&eattacks, "EnnemyAttack2", 2, 2);
	add_attack(&eattacks, "EnnemyAttack1", 1, 1);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy1", eattacks);
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy2", eattacks);
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy3", eattacks);
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy4", eattacks);
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	engine->change_scene(engine, "fight", fight);
	return (0);
}