/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Speak component
*/

/* File created the 01/05/2018 at 13:32:58 by julian.frabel@epitech.eu */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_sfml.h"
#include "rpg.h"

static void set_text(sf_speak_t *speak, const char *text)
{
	if (speak == NULL || text == NULL)
		return;
	if (speak->text != NULL)
		free(speak->text);
	speak->text = strdup(text);
	if (speak->text != NULL)
		sfText_setString(speak->text_comp, speak->text);
}

static void set_font(sf_speak_t *speak, const char *font)
{
	if (speak == NULL || font == NULL)
		return;
	if (speak->font != NULL)
		sfFont_destroy(speak->font);
	speak->font = sfFont_createFromFile(font);
	if (speak->font == NULL)
		return;
	if (speak->text_comp != NULL)
		sfText_setFont(speak->text_comp, speak->font);
}

static void show(sf_speak_t *speak, UNUSED sf_engine_t *engine)
{
	dprintf(2, "Should display %s\n", (speak->text != NULL) ? \
speak->text : "NULL");
}

void destroy_speak_component(sf_speak_t *speak)
{
	if (speak == NULL)
		return;
	if (speak->text != NULL)
		free(speak->text);
	if (speak->font != NULL)
		sfFont_destroy(speak->font);
	if (speak->text_comp != NULL)
		sfText_destroy(speak->text_comp);
	free(speak);
}

sf_speak_t *create_speak_component(gameobject_t *parent)
{
	sf_speak_t *speak = malloc(sizeof(*speak));

	speak->destroy = &destroy_speak_component;
	speak->font = NULL;
	speak->parent = parent;
	speak->text = NULL;
	speak->text_comp = sfText_create();
	speak->set_font = &set_font;
	speak->set_text = &set_text;
	speak->show = &show;
	return (speak);
}