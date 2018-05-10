/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory toggle fx
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

static void add_items(sf_inventory_t *self)
{
	for (int i = 0; i < INV_SIZE; i++) {
		if (self->backpack[i].sprite_path)
			self->bp_sprite[i] = \
self->engine->get_sprite(self->engine, self->backpack[i].sprite_path);
	}
}

void inventory_toggle(sf_inventory_t *self)
{
	self->is_opened = !self->is_opened;
	if (self->is_opened) {
		if (self->sprite == NULL)
			self->sprite = self->engine->get_sprite(self->engine, \
PANEL_INVENTORY);
		if (self->sprite == NULL)
			return;
		self->engine->add_to_layer(self->engine, GAME + 11, \
(void **)&(self->sprite));
	} else {
		self->engine->remove_from_layers(self->engine, \
(void **)&(self->sprite));
	}
}