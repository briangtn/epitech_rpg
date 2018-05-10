/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory componentn
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

static void inventory_toggle(sf_inventory_t *self)
{
	self->is_opened = !self->is_opened;
	if (self->is_opened) {
		if (self->sprite == NULL)
			self->sprite = self->engine->get_sprite(self->engine, \
FACE_KING);
		if (self->sprite == NULL)
			return;
		self->engine->add_to_layer(self->engine, GAME + 1, \
(void **)&(self->sprite));
	} else {
		self->engine->remove_from_layers(self->engine, \
(void **)&(self->sprite));
	}
}

static void destroy_inventory(sf_inventory_t *obj)
{
	if (obj->sprite != NULL)
		sfSprite_destroy(obj->sprite);
	free(obj);
}

sf_inventory_t *create_inventory(gameobject_t *parent)
{
	sf_inventory_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->destroy = &destroy_inventory;
	new->parent = parent;
	new->engine = NULL;
	new->sprite = NULL;
	new->is_opened = false;
	new->hp = 1.0f;
	new->s_atk = 1.0f;
	new->s_def = 1.0f;
	new->s_int = 1.0f;
	new->s_dex = 1.0f;
	for (int i = 0; i < INV_SIZE; i++)
		new->backpack[i] = ITEM_LIST[ITEM_NULL];
	new->toggle = &inventory_toggle;
	return (new);
}