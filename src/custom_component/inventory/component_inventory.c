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
	if (obj->prgbar_atk)
		obj->prgbar_atk->destroy(obj->prgbar_atk);
	if (obj->prgbar_def)
		obj->prgbar_def->destroy(obj->prgbar_def);
	if (obj->prgbar_dex)
		obj->prgbar_dex->destroy(obj->prgbar_dex);
	if (obj->prgbar_int)
		obj->prgbar_int->destroy(obj->prgbar_int);
	free(obj);
}

static int setup_prgbar_settings(gameobject_t *go)
{
	sf_loadbar_t *prgbar_ptr = get_component(go, LOADBAR);

	if (prgbar_ptr == NULL)
		return (1);
	prgbar_ptr->back_color = sfBlack;
	prgbar_ptr->fore_color = sfBlue;
	prgbar_ptr->max_value = 2.0f;
	prgbar_ptr->current_value = 1.0f;
	return (0);
}

static int setup_prgbar(sf_inventory_t *self)
{
	self->prgbar_atk = create_gameobject("prgbar_atk");
	self->prgbar_def = create_gameobject("prgbar_def");
	self->prgbar_dex = create_gameobject("prgbar_dex");
	self->prgbar_int = create_gameobject("prgbar_int");
	if (!(self->prgbar_atk && self->prgbar_def && self->prgbar_dex && \
self->prgbar_int))
		return (1);
	self->prgbar_atk->add_custom_component(self->prgbar_atk, \
&create_loadbar_comp, LOADBAR);
	self->prgbar_def->add_custom_component(self->prgbar_def, \
&create_loadbar_comp, LOADBAR);
	self->prgbar_dex->add_custom_component(self->prgbar_dex, \
&create_loadbar_comp, LOADBAR);
	self->prgbar_int->add_custom_component(self->prgbar_int, \
&create_loadbar_comp, LOADBAR);
	return (setup_prgbar_settings(self->prgbar_atk) + \
setup_prgbar_settings(self->prgbar_def) + \
setup_prgbar_settings(self->prgbar_dex) + \
setup_prgbar_settings(self->prgbar_int));
}

sf_inventory_t *create_inventory(gameobject_t *parent)
{
	sf_inventory_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->destroy = &destroy_inventory;
	new->parent = parent;
	new->engine = NULL;
	new->screen_pos = (sfVector2i){200, 300};
	new->sprite = NULL;
	new->is_opened = false;
	new->hp = 1.0f;
	for (int i = 0; i < INV_SIZE; i++)
		new->backpack[i] = ITEM_LIST[ITEM_NULL];
	new->toggle = &inventory_toggle;
	new->s_atk = 1.0f;
	new->s_def = 1.0f;
	new->s_int = 1.0f;
	new->s_dex = 1.0f;
	setup_prgbar(new);
	return (new);
}