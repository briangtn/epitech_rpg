/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fight creator utils
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

fight_enemy_t *create_enemy(int life, char *path, char *name,\
sf_linked_list_t *attacks)
{
	fight_enemy_t *enemy = malloc(sizeof(*enemy));

	if (enemy == NULL)
		return (NULL);
	enemy->life = life;
	enemy->sprite_path = path;
	enemy->name = name;
	enemy->go = NULL;
	enemy->attacks = attacks;
	return (enemy);
}

fight_t *create_fight(char *path, fight_player_t *player)
{
	fight_t *fight = malloc(sizeof(*fight));

	if (fight == NULL)
		return (NULL);
	fight->background_path = path;
	fight->player = player;
	fight->ennemies = NULL;
	fight->last_attack = NULL;
	fight->end_callback = NULL;
	fight->end_datas = NULL;
	fight->logs = NULL;
	return (fight);
}

void add_attack(sf_linked_list_t **list, char *name, float damage, int cost)
{
	attack_t *attack = malloc(sizeof(*attack));

	if (attack == NULL)
		return;
	attack->name = name;
	attack->damage = damage;
	attack->mana_cost = cost;
	*list = sf_push(attack, my_strdup(name), *list);
}

fight_player_t *create_fight_player(char *path, sf_linked_list_t *attacks)
{
	fight_player_t *player = malloc(sizeof(*player));

	if (player == NULL)
		return (NULL);
	player->go = NULL;
	player->life = 10;
	player->sprite_path = path;
	player->position = (sf_vector_2d_t){600, 600};
	player->attacks = attacks;
	player->max_mana = 10;
	player->curr_max_mana = 0;
	player->mana = 0;
	return (player);
}