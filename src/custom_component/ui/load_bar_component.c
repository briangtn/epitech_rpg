/*
** EPITECH PROJECT, 2017
** My rph
** File description:
** Load bar component
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

static void destroy_loadbar_comp(sf_loadbar_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

sf_loadbar_t *create_loadbar_comp(gameobject_t *go)
{
	sf_loadbar_t *loadbar = malloc(sizeof(*loadbar));

	if (loadbar == NULL)
		return (NULL);
	loadbar->parent = go;
	loadbar->destroy = &destroy_loadbar_comp;
	loadbar->max_value = 100.0;
	loadbar->current_value = 100.0;
	loadbar->fore_color = sfGreen;
	loadbar->back_color = sfRed;
	return (loadbar);
}