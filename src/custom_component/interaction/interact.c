/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Run all interactions in the given square
*/

/* File created the 19/04/2018 at 14:59:48 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static sfIntRect get_rect_in_front(gameobject_t *from)
{
	sf_collider_2d_t *col = get_component(from, COLLIDER_2D);
	sf_transform_t *tr = get_component(from, TRANSFORM);
	sf_animation_2d_t *anim = get_component(from, ANIMATION_2D);
	sfIntRect rect = col->hitbox;

	rect.left += tr->position.x;
	rect.top += tr->position.y;
	if (anim->view_rect.top == 0 * TILE_SIZE)
		rect.top += 1 * TILE_SIZE;
	if (anim->view_rect.top == 1 * TILE_SIZE)
		rect.left += -1 * TILE_SIZE;
	if (anim->view_rect.top == 2 * TILE_SIZE)
		rect.left += 1 * TILE_SIZE;
	if (anim->view_rect.top == 3 * TILE_SIZE)
		rect.top += -1 * TILE_SIZE;
	return (rect);
}

void run_interactions(sf_engine_t *engine, gameobject_t *from)
{
	int nb_col = 0;
	gameobject_t **cols = NULL;
	sf_interaction_t *curr = NULL;
	sfIntRect rect = get_rect_in_front(from);

	cols = engine->get_collisions_rect(engine, rect, &nb_col, NULL);
	for (int i = 0; i < nb_col; i++) {
		curr = get_component(cols[i], INTERACTION);
		if (curr != NULL)
			curr->interaction(cols[i], curr->engine);
	}
	free(cols);
}