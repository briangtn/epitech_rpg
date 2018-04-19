/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fight utils
*/

#include "my_sfml.h"
#include "rpg.h"

int get_enemy_center_position(sf_engine_t *engine, int enemy_count)
{
	sfVector2u window_sizes;
	int total_size = FIGHT_ELEMENT_SIZE + FIGHT_ENEMY_SPACE;

	if (engine == NULL)
		return (0);
	window_sizes = sfRenderWindow_getSize(engine->window);
	return (window_sizes.x / 2 - (enemy_count * (total_size)) / 2);
}

int get_total_elem_size(void)
{
	return (FIGHT_ELEMENT_SIZE + FIGHT_ENEMY_SPACE);
}