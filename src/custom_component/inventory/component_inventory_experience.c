/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** experience fx
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

void inventory_increaseskillpoint(float *skill, float amount, float flr)
{
	*skill += amount;
	if (flr <= *skill)
		*skill = flr;
}

static void update_prgbar(sf_inventory_t *self)
{
	sf_loadbar_t *b_atk = get_component(self->prgbar_atk, LOADBAR);
	sf_loadbar_t *b_def = get_component(self->prgbar_def, LOADBAR);
	sf_loadbar_t *b_dex = get_component(self->prgbar_dex, LOADBAR);
	sf_loadbar_t *b_int = get_component(self->prgbar_int, LOADBAR);
	sf_loadbar_t *b_exp = get_component(self->prgbar_exp, LOADBAR);

	b_atk->current_value = self->s_atk;
	b_def->current_value = self->s_def;
	b_dex->current_value = self->s_dex;
	b_int->current_value = self->s_int;
	b_exp->current_value = self->exp;
}

int inventory_addexp(sf_inventory_t *self, float amount)
{
	self->exp += amount;
	if (50.0f <= self->exp) {
		self->exp -= 50.0f;
		inventory_increaseskillpoint(&(self->s_atk), .2f, 2.0f);
		inventory_increaseskillpoint(&(self->s_def), .2f, 2.0f);
		inventory_increaseskillpoint(&(self->s_dex), .2f, 2.0f);
		inventory_increaseskillpoint(&(self->s_int), .2f, 2.0f);
		inventory_increaseskillpoint(&(self->hp), 5.0f, 100.0f);
		update_prgbar(self);
		self->toggle(self);
		self->toggle(self);
		return (1);
	}
	update_prgbar(self);
	self->toggle(self);
	self->toggle(self);
	return (0);
}