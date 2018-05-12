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
	if (obj->prgbar_exp != NULL)
		obj->prgbar_exp->destroy(obj->prgbar_exp);
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
	self->exp = .0f;
	for (int i = 0; i < INV_SIZE; i++) {
		self->backpack[i] = ITEM_LIST[ITEM_NULL];
		self->bp_sprite[i] = NULL;
	}
	self->s_atk = (float)(rand() % 400 + 600) / 1000.0f;
	self->s_def = (float)(rand() % 400 + 600) / 1000.0f;
	self->s_int = (float)(rand() % 400 + 600) / 1000.0f;
	self->s_dex = (float)(rand() % 400 + 600) / 1000.0f;
}

static void initialise_pgrbar(sf_inventory_t *self)
{
	sf_loadbar_t *p_atk = get_component(self->prgbar_atk, LOADBAR);
	sf_loadbar_t *p_def = get_component(self->prgbar_def, LOADBAR);
	sf_loadbar_t *p_dex = get_component(self->prgbar_dex, LOADBAR);
	sf_loadbar_t *p_int = get_component(self->prgbar_int, LOADBAR);
	sf_loadbar_t *p_exp = get_component(self->prgbar_exp, LOADBAR);

	p_atk->current_value = self->s_atk;
	p_def->current_value = self->s_def;
	p_dex->current_value = self->s_dex;
	p_int->current_value = self->s_int;
	p_exp->fore_color = (sfColor){255, 255, 0, 255};
	p_atk->fore_color = (sfColor){255, 0, 0, 255};
	p_def->fore_color = (sfColor){0, 0, 255, 255};
	p_dex->fore_color = (sfColor){0, 255, 0, 255};
	p_int->fore_color = (sfColor){255, 0, 255, 255};
	p_exp->back_color = (sfColor){150, 150, 0, 255};
	p_atk->back_color = (sfColor){150, 0, 0, 255};
	p_def->back_color = (sfColor){0, 0, 150, 255};
	p_dex->back_color = (sfColor){0, 150, 0, 255};
	p_int->back_color = (sfColor){150, 0, 150, 255};
}

int inventory_setup_progressbar(sf_inventory_t *self)
{
	self->prgbar_atk = create_prefab_loadbar(self->engine, \
(sfFloatRect){1.0f, 1.0f, 40.0f, 15.0f}, 2.0f);
	self->prgbar_def = create_prefab_loadbar(self->engine, \
(sfFloatRect){.0f, .0f, 40.0f, 15.0f}, 2.0f);
	self->prgbar_dex = create_prefab_loadbar(self->engine, \
(sfFloatRect){.0f, .0f, 40.0f, 15.0f}, 2.0f);
	self->prgbar_int = create_prefab_loadbar(self->engine, \
(sfFloatRect){.0f, .0f, 40.0f, 15.0f}, 2.0f);
	self->prgbar_exp = create_prefab_loadbar(self->engine, \
(sfFloatRect){.0f, .0f, 220.0f, 3.0f}, 50.0f);
	if (!(self->prgbar_int && self->prgbar_dex && self->prgbar_def &&\
self->prgbar_atk && self->prgbar_exp))
		return (1);
	initialise_pgrbar(self);
	hide_load_bar(self->prgbar_atk, self->engine);
	hide_load_bar(self->prgbar_def, self->engine);
	hide_load_bar(self->prgbar_dex, self->engine);
	hide_load_bar(self->prgbar_int, self->engine);
	hide_load_bar(self->prgbar_exp, self->engine);
	return (0);
}

sf_inventory_t *create_inventory(gameobject_t *parent)
{
	sf_inventory_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->destroy = &destroy_inventory;
	new->toggle = &inventory_toggle;
	new->add_exp = &inventory_addexp;
	new->add_item = &inventory_additem;
	new->remove_item = &inventory_removeitem;
	new->retrieve_item = &inventory_retrieveitem;
	new->parent = parent;
	new->engine = NULL;
	setup_vars(new);
	new->backpack[0] = ITEM_LIST[ITEM_POTION_EXP];
	new->backpack[1] = ITEM_LIST[ITEM_POTION_EXP];
	new->backpack[2] = ITEM_LIST[ITEM_POTION_STR];
	new->backpack[3] = ITEM_LIST[ITEM_POTION_DEX];
	return (new);
}