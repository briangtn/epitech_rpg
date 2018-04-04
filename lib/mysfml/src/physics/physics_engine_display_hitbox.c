/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Display all hitbox as a pink rect
*/

#include <stdlib.h>
#include "my_sfml_engine.h"
#include "my_sfml_gameobject.h"

static void display(gameobject_t *obj, sfRectangleShape *shape, \
sf_engine_t *engine);

void display(gameobject_t *obj, sfRectangleShape *shape, sf_engine_t *engine)
{
	sf_transform_t *tr = get_component(obj, TRANSFORM);
	sf_collider_2d_t *col = get_component(obj, COLLIDER_2D);
	int nb = 0;

	if (tr == NULL || col == NULL)
		return;
	free(engine->get_collisions_go(engine, obj, &nb));
	if (nb != 0)
		sfRectangleShape_setOutlineColor(shape, sfGreen);
	else
		sfRectangleShape_setOutlineColor(shape, sfRed);
	sfRectangleShape_setPosition(shape, (sfVector2f){tr->position.x + \
col->hitbox.left + 1, tr->position.y + col->hitbox.top + 1});
	sfRectangleShape_setSize(shape, (sfVector2f){col->hitbox.width, \
col->hitbox.height});
	sfRenderWindow_drawRectangleShape(engine->window, shape, NULL);
}

int display_hitbox(sf_engine_t *engine)
{
	sfRectangleShape *shape = NULL;
	sf_linked_list_t *curr_elem = NULL;

	if (DISPLAY_HITBOX == 0)
		return (0);
	shape = sfRectangleShape_create();
	if (shape == NULL)
		return (84);
	sfRectangleShape_setOutlineColor(shape, (sfColor){255, 20, 147, 255});
	sfRectangleShape_setFillColor(shape, (sfColor){0, 0, 0, 0});
	sfRectangleShape_setOutlineThickness(shape, 1);
	curr_elem = engine->current_scene->physic_engine->physics_objects;
	for (int i = 0; curr_elem != NULL; i++) {
		display(curr_elem->data, shape, engine);
		curr_elem = curr_elem->next;
	}
	sfRectangleShape_destroy(shape);
	return (0);
}