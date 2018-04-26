/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Rpg enemy component
*/

/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fight arrow component
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

static void destroy_enemy_comp(sf_enemy_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

sf_enemy_t *create_enemy_comp(gameobject_t *parent)
{
	sf_enemy_t *enemy = malloc(sizeof(*enemy));

	if (enemy == NULL)
		return (NULL);
	enemy->parent = parent;
	enemy->destroy = &destroy_enemy_comp;
	enemy->fight = NULL;
	enemy->datas = NULL;
	return (enemy);
}