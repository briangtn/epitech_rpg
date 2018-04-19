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

int get_enemy_posx(sf_engine_t *engine, int enemy_count, int pos)
{
	int res = 0;

	if (engine == NULL)
		return (0);
	res = get_enemy_center_position(engine, enemy_count);
	res += pos * (get_total_elem_size()) + FIGHT_ENEMY_SPACE;
	return (res);
}

void scale_elem_to_size(sfSprite *sprite)
{
	sfFloatRect sizes;

	if (sprite == NULL)
		return;
	sizes = sfSprite_getGlobalBounds(sprite);
	sfSprite_setScale(sprite,\
(sfVector2f){FIGHT_ELEMENT_SIZE / sizes.width,\
FIGHT_ELEMENT_SIZE / sizes.height});
}