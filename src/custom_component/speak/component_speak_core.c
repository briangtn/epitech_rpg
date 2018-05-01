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
	sfVector2f pos = {350, 735};

	if (speak == NULL || text == NULL)
		return;
	if (speak->text != NULL)
		free(speak->text);
	speak->text = strdup(text);
	if (speak->text != NULL) {
		sfText_setString(speak->text_comp, speak->text);
		sfText_setPosition(speak->text_comp, pos);
	}
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

static void show(sf_speak_t *speak, sf_engine_t *engine)
{
	goto_pause(engine, "speak");
	if (speak->font != NULL && speak->text != NULL && \
speak->text_comp != NULL) {
		engine->add_to_layer(engine, UI_TEXT, &(speak->text_comp));
		display_next_line(speak, engine);
	}
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
	speak->line = -1;
	speak->text_comp = sfText_create();
	speak->set_font = &set_font;
	speak->set_text = &set_text;
	speak->show = &show;
	return (speak);
}