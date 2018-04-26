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

static void destroy_farrow_comp(sf_fight_arrow_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

sf_linked_list_t *get_arrow_elem(sf_fight_arrow_t *arrow)
{
	return (get_elem_at_index(arrow->elem_index, arrow->list));
}

sf_fight_arrow_t *create_farrow_comp(gameobject_t *parent)
{
	sf_fight_arrow_t *farrow = malloc(sizeof(*farrow));

	if (farrow == NULL)
		return (NULL);
	farrow->parent = parent;
	farrow->destroy = &destroy_farrow_comp;
	farrow->elem_index = 0;
	farrow->elem_offset = 100;
	farrow->elem_size = FIGHT_ELEMENT_SIZE;
	farrow->list = NULL;
	farrow->callback_param = NULL;
	farrow->get_elem = &get_arrow_elem;
	farrow->update = &arrow_update;
	farrow->dir = HORIZONTAL;
	farrow->engine = NULL;
	farrow->display_update = &arrow_display_update;
	farrow->callback = NULL;
	return (farrow);
}