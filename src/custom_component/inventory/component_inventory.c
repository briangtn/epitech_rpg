/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory componentn
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

static void destroy_inventory(sf_inventory_t *obj)
{
	if (obj->sprite != NULL)
		sfSprite_destroy(obj->sprite);
	if (obj->prgbar_atk != NULL)
		obj->prgbar_atk->destroy(obj->prgbar_atk);
	if (obj->prgbar_def != NULL)
		obj->prgbar_def->destroy(obj->prgbar_def);
	if (obj->prgbar_dex != NULL)
		obj->prgbar_dex->destroy(obj->prgbar_dex);
	if (obj->prgbar_int != NULL)
		obj->prgbar_int->destroy(obj->prgbar_int);
	for (int i = 0; i < INV_SIZE; i++) {
		obj->engine->remove_from_layers(obj->engine, \
(void **)&(obj->bp_sprite[i]));
		if (obj->bp_sprite[i] != NULL)
			sfSprite_destroy(obj->bp_sprite[i]);
	}
	free(obj);
}

static void setup_vars(sf_inventory_t *self)
{
	self->screen_pos = (sfVector2i){200, 300};
	self->sprite = NULL;
	self->is_opened = false;
	self->hp = 1.0f;
	for (int i = 0; i < INV_SIZE; i++) {
		self->backpack[i] = ITEM_LIST[ITEM_NULL];
		self->bp_sprite[i] = NULL;
	}
	self->s_atk = (float)(rand() % 2000) / 1000.0f;
	self->s_def = (float)(rand() % 2000) / 1000.0f;
	self->s_int = (float)(rand() % 2000) / 1000.0f;
	self->s_dex = (float)(rand() % 2000) / 1000.0f;
}

int inventory_setup_progressbar(sf_inventory_t *self)
{
	self->prgbar_atk = create_prefab_loadbar(self->engine, \
(sfFloatRect){1.0f, 1.0f, 20.0f, 15.0f}, 2.0f);
	self->prgbar_def = create_prefab_loadbar(self->engine, \
(sfFloatRect){.0f, .0f, 20.0f, 15.0f}, 2.0f);
	self->prgbar_dex = create_prefab_loadbar(self->engine, \
(sfFloatRect){.0f, .0f, 20.0f, 15.0f}, 2.0f);
	self->prgbar_int = create_prefab_loadbar(self->engine, \
(sfFloatRect){.0f, .0f, 20.0f, 15.0f}, 2.0f);
	return (!(self->prgbar_int && self->prgbar_dex && self->prgbar_def &&\
self->prgbar_atk));
}

sf_inventory_t *create_inventory(gameobject_t *parent)
{
	sf_inventory_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->destroy = &destroy_inventory;
	new->toggle = &inventory_toggle;
	new->add_item = &inventory_additem;
	new->remove_item = &inventory_removeitem;
	new->retrieve_item = &inventory_retrieveitem;
	new->parent = parent;
	new->engine = NULL;
	setup_vars(new);
	return (new);
}