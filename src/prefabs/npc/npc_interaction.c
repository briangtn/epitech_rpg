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

void npc_interaction(gameobject_t *npc, sf_engine_t *engine)
{
	sf_npc_t *npc_comp = get_component(npc, NPC);

	if (npc_comp == NULL || npc_comp->speak == NULL || \
npc_comp->speak->text == NULL || npc_comp->speak->text[0] == '\0')
		return;
	npc_comp->speak->show(npc_comp->speak, engine);
}