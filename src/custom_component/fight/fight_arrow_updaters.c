/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fight arrow updaters
*/

#include "utils.h"
#include "rpg.h"

static bool key_pressed(sf_fight_arrow_t *arrow, bool back)
{
	if (back) {
		if (arrow->dir == HORIZONTAL && is_key_just_pressed(sfKeyLeft))
			return (true);
		if (arrow->dir == VERTICAL && is_key_just_pressed(sfKeyUp))
			return (true);
	} else {
		if (arrow->dir == HORIZONTAL && is_key_just_pressed(sfKeyRight))
			return (true);
		if (arrow->dir == VERTICAL && is_key_just_pressed(sfKeyDown))
			return (true);
	}
	return (false);
}

int arrow_update(sf_fight_arrow_t *arrow, UNUSED int delta_time)
{
	if (key_pressed(arrow, true) && arrow->elem_index > 0) {
		arrow->elem_index--;
	} else if (key_pressed(arrow, false) &&\
get_elem_at_index(arrow->elem_index + 1, arrow->list) != NULL) {
		arrow->elem_index++;
	} else if (is_key_just_pressed(sfKeyReturn) && arrow->callback) {
		arrow->callback(arrow->callback_param, get_arrow_elem(arrow));
	}
	return (0);
}

static sfVector2f get_position(sf_fight_arrow_t *arrow, sf_transform_t *tr,\
sf_animation_2d_t *anim)
{
	sfFloatRect rect;

	if (anim == NULL)
		return ((sfVector2f){0, 0});
	rect = sfSprite_getGlobalBounds(anim->sprite);
	if (arrow->dir == HORIZONTAL)
		return ((sfVector2f){\
tr->position.x + arrow->elem_size / 2 - rect.width / 2,\
tr->position.y - arrow->elem_offset});
	if (arrow->dir == VERTICAL)
		return ((sfVector2f){tr->position.x - arrow->elem_offset,\
tr->position.y + arrow->elem_size / 2 - rect.height / 2});
	return ((sfVector2f){0, 0});
}

int arrow_display_update(sf_animation_2d_t *anim, UNUSED int delta_time)
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
	sfSprite_setPosition(anim->sprite, get_position(arrow, other_tr,\
anim));
	return (0);
}
