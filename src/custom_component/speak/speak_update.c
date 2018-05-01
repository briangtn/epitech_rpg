/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Update the text
*/

/* File created the 01/05/2018 at 14:46:07 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml.h"
#include "my.h"
#include "rpg.h"

void display_next_line(sf_speak_t *new_speak, sf_engine_t *engine)
{
	static sf_speak_t *speak = NULL;
	char **tab = NULL;

	if (new_speak != NULL)
		speak = new_speak;
	if (speak == NULL)
		return;
	tab = my_parse_str_to_array(speak->text, "\n", "", "");
	if (tab == NULL)
		return;
	speak->line += 1;
	sfText_setString(speak->text_comp, tab[speak->line]);
	if (tab[speak->line] == NULL) {
		my_free_array((void **)tab);
		speak->line = -1;
		quit_pause(engine);
		return;
	}
	my_free_array((void **)tab);
}