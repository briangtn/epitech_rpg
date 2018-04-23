/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fight arrow component
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

static void destroy_farrow_comp(sf_fight_arrow_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

sf_fight_arrow_t *create_farrow_comp(gameobject_t *parent)
{
	sf_fight_arrow_t *farrow = malloc(sizeof(*farrow));

	if (farrow == NULL)
		return (NULL);
	farrow->parent = parent;
	farrow->destroy = &destroy_farrow_comp;
	farrow->enemy_index = 0;
	farrow->fight = NULL;
	return (farrow);
}

