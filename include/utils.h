/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Utils header
*/

#ifndef UTILS
	#define UTILS

	#include "my_sfml.h"

	bool is_key_just_pressed(sfKeyCode key_code);
	fight_enemy_t *create_enemy(int life, char *path, char *name);
	fight_t *create_fight(char *path, fight_player_t player);
	sf_linked_list_t *get_elem_at_index(int index, sf_linked_list_t *list);

#endif
