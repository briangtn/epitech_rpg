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

static sf_linked_list_t *get_arrow_elem(sf_fight_arrow_t *arrow)
{
	return (get_elem_at_index(arrow->elem_index, arrow->list));
}

static int arrow_update(sf_fight_arrow_t *arrow, UNUSED int delta_time)
{
	if (is_key_just_pressed(sfKeyLeft) && arrow->elem_index > 0) {
		arrow->elem_index--;
	} else if (is_key_just_pressed(sfKeyRight) &&\
get_elem_at_index(arrow->elem_index + 1, arrow->list) != NULL) {
		arrow->elem_index++;
	} else if (is_key_just_pressed(sfKeyReturn)) {
		//TODO
	}
	return (0);
}

static int arrow_display_update(sf_animation_2d_t *anim, UNUSED int delta_time)
{
	sf_transform_t *tr = get_component(anim->parent, TRANSFORM);
	sf_fight_arrow_t *arrow = get_component(anim->parent, FARROW);
	sf_transform_t *other_tr = NULL;
	sf_linked_list_t *arrow_elem = NULL;

	if (tr == NULL || arrow == NULL)
		return (84);
	arrow_elem = get_arrow_elem(arrow);
	if (arrow_elem == NULL)
		return (0);
	other_tr = get_component(\
((arrow_elem_base_t *)arrow_elem->data)->go, TRANSFORM);
	if (other_tr == NULL)
		return (84);
	sfSprite_setPosition(anim->sprite,\
(sfVector2f){other_tr->position.x + arrow->elem_size / 4,\
other_tr->position.y - 100});
	return (0);
}

sf_fight_arrow_t *create_farrow_comp(gameobject_t *parent)
{
	sf_fight_arrow_t *farrow = malloc(sizeof(*farrow));

	if (farrow == NULL)
		return (NULL);
	farrow->parent = parent;
	farrow->destroy = &destroy_farrow_comp;
	farrow->elem_index = 0;
	farrow->elem_size = FIGHT_ELEMENT_SIZE;
	farrow->list = NULL;
	farrow->get_elem = &get_arrow_elem;
	farrow->update = &arrow_update;
	farrow->display_update = &arrow_display_update;
	return (farrow);
}