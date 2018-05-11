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
		else
			self->bp_sprite[i] = NULL;
		self->engine->add_to_layer(self->engine, GAME + 12, \
(void **)&(self->bp_sprite[i]));
	}
}

static void remove_items(sf_inventory_t *self)
{
	for (int i = 0; i < INV_SIZE; i++) {
		self->engine->remove_from_layers(self->engine, \
(void **)&(self->bp_sprite[i]));
		if (self->bp_sprite[i] == NULL)
			continue;
		sfSprite_destroy(self->bp_sprite[i]);
		self->bp_sprite[i] = NULL;
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
		add_items(self);
	} else {
		self->engine->remove_from_layers(self->engine, \
(void **)&(self->sprite));
		remove_items(self);
	}
}

void initialize_items(sf_inventory_t *self)
{
	for (int i = 0; i < INV_SIZE; i++) {
		self->engine->add_to_layer(self->engine, GAME + 12, \
(void **)&(self->bp_sprite[i]));
	}
}