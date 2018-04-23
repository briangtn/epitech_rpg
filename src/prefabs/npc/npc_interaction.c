/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** nbp interaction
*/

/* File created the 19/04/2018 at 14:20:31 by julian.frabel@epitech.eu */

#include <stdio.h>
#include "my_sfml.h"
#include "rpg.h"
#include "my.h"

void npc_interaction(UNUSED gameobject_t *npc, UNUSED sf_engine_t *engine)
{
	sf_npc_t *npc_comp = get_component(npc, NPC);

	if (npc_comp == NULL || npc_comp->text == NULL)
		return;
	my_printf(npc_comp->text);
}