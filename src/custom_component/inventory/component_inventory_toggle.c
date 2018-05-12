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
	sf_loadbar_t *ld_bar = get_component(self->prgbar_exp, LOADBAR);

	for (int i = 0; i < INV_SIZE; i++) {
		if (self->backpack[i].sprite_path)
			self->bp_sprite[i] = \
self->engine->get_sprite(self->engine, self->backpack[i].sprite_path);
		else
			self->bp_sprite[i] = NULL;
		self->engine->add_to_layer(self->engine, GAME + 12, \
(void **)&(self->bp_sprite[i]));
	}
	if (ld_bar != NULL)
		ld_bar->current_value = self->exp;
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

static void hide_pgrbar(sf_inventory_t *self)
{
	hide_load_bar(self->prgbar_atk, self->engine);
	hide_load_bar(self->prgbar_def, self->engine);
	hide_load_bar(self->prgbar_dex, self->engine);
	hide_load_bar(self->prgbar_int, self->engine);
	hide_load_bar(self->prgbar_exp, self->engine);
}

static void show_pgrbar(sf_inventory_t *self)
{
	show_load_bar(self->prgbar_atk, self->engine);
	show_load_bar(self->prgbar_def, self->engine);
	show_load_bar(self->prgbar_dex, self->engine);
	show_load_bar(self->prgbar_int, self->engine);
	show_load_bar(self->prgbar_exp, self->engine);
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
		show_pgrbar(self);
	} else {
		self->engine->remove_from_layers(self->engine, \
(void **)&(self->sprite));
		remove_items(self);
		hide_pgrbar(self);
	}
}