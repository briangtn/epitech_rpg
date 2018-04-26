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
	parser_to_game_t *ptg = create_parser_to_game("test_config");

	engine->change_scene(engine, "game", ptg);
}

void launch_fight(sf_button_t *button)
{
	sf_engine_t *engine = button->engine;
	fight_t *fight = NULL;
	fight_enemy_t *enemy = NULL;
	fight_player_t *player = NULL;
	sf_linked_list_t *attacks = NULL;

	add_attack(&attacks, "SuperAttack", 2);
	add_attack(&attacks, "MegaAttack", 4);
	add_attack(&attacks, "AttaqueKiTuTou", 10);
	player = create_fight_player("assets/faces/player.png", attacks);
	fight = create_fight("assets/test.png", player);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy1");
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy2");
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy3");
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	enemy = create_enemy(10, "assets/dragon.png", "Enemy4");
	fight->ennemies = sf_push(enemy, my_strdup("enemy"), fight->ennemies);
	engine->change_scene(engine, "fight", fight);
}

void quit_app(sf_button_t *button)
{
	sfRenderWindow_close(button->engine->window);
}