/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Interaction compoennet
*/

/* File created the 19/04/2018 at 14:15:45 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"

sf_interaction_t *create_interaction(gameobject_t *parent)
{
	sf_interaction_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->destroy = &destroy_interaction;
	new->parent = parent;
	new->engine = NULL;
	new->interaction = NULL;
	return (new);
}

void destroy_interaction(sf_interaction_t *interaction)
{
	free(interaction);
}