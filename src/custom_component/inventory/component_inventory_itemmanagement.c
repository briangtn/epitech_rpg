/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory item mangamenet fx
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

int inventory_additem(sf_inventory_t *self, const items_t *item)
{
	for (int i = 0; i < INV_SIZE; i++) {
		if (self->backpack[i].name == NULL) {
			self->backpack[i] = *item;
			return (i);
		}
	}
	return (-1);
}

int inventory_removeitem(sf_inventory_t *self, const items_t *item)
{
	for (int i = 0; i < INV_SIZE; i++) {
		if (self->backpack[i].name == item->name) {
			self->backpack[i] = ITEM_LIST[ITEM_NULL];
			return (i);
		}
	}
	return (-1);
}

int inventory_retrieveitem(sf_inventory_t *self, const items_t *item)
{
	for (int i = 0; i < INV_SIZE; i++)
		if (self->backpack[i].name == item->name)
			return (i);
	return (-1);
}