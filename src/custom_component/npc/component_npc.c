/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** npc component use when interacting with an npc
*/

/* File created the 19/04/2018 at 14:27:58 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

sf_npc_t *create_npc_comp(gameobject_t *parent)
{
	sf_npc_t *new_npc = malloc(sizeof(*new_npc));

	if (new_npc == NULL)
		return (NULL);
	new_npc->parent = parent;
	new_npc->destroy = &destroy_npc_comp;
	new_npc->speak = create_speak_component(parent);
	return (new_npc);
}

void destroy_npc_comp(sf_npc_t *comp)
{
	if (comp == NULL)
		return;
	if (comp->speak != NULL)
		comp->speak->destroy(comp->speak);
	free(comp);
}