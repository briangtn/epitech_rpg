/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** potion use effects
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

void potion_exp_use(items_t *self, sf_inventory_t *inv)
{
	inventory_increaseskillpoint(&(inv->s_int), self->value, 2.0f);
	inv->add_exp(inv, 25.0f);
	*self = ITEM_LIST[ITEM_NULL];
	inv->toggle(inv);
	inv->toggle(inv);
}

void potion_str_use(items_t *self, sf_inventory_t *inv)
{
	inventory_increaseskillpoint(&(inv->s_atk), self->value, 2.0f);
	inv->add_exp(inv, 5.0f);
	*self = ITEM_LIST[ITEM_NULL];
	inv->toggle(inv);
	inv->toggle(inv);
}

void potion_dex_use(items_t *self, sf_inventory_t *inv)
{
	inventory_increaseskillpoint(&(inv->s_dex), self->value, 2.0f);
	inv->add_exp(inv, 5.0f);
	*self = ITEM_LIST[ITEM_NULL];
	inv->toggle(inv);
	inv->toggle(inv);
}