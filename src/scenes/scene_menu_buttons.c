/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Button on menu
*/

/* File created the 25/04/2018 at 11:52:50 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

void launch_game(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;
	parser_to_game_t *ptg = engine->data;

	if (ptg == NULL)
		return;
	ptg->active_scene = 1;
	engine->change_scene(engine, "game", ptg);
}

void launch_fight(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;
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
}

void quit_app(sf_button_t *button)
{
	sfRenderWindow_close(button->engine->window);
}

void goto_menu(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;

	quit_pause(engine);
	engine->change_scene(engine, "menu", engine->data);
}