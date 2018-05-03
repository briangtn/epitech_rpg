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

static void set_info(sf_speak_t *speak, const char *text, const char *portrait)
{
	if (speak == NULL || text == NULL || portrait == NULL)
		return;
	if (speak->text != NULL)
		free(speak->text);
	if (speak->portrait != NULL)
		free(speak->portrait);
	speak->text = my_strdup(text);
	speak->portrait = my_strdup(portrait);
	if (speak->text != NULL) {
		sfText_setString(speak->text_comp, speak->text);
		sfText_setColor(speak->text_comp, sfBlack);
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
	sfVector2f pos_world_pos = sfRenderWindow_mapPixelToCoords(\
engine->window, (sfVector2i){350, 775}, sfRenderWindow_getView(engine->window));
	sfVector2f face_pos = {160, 800};
	gameobject_t *face = NULL;
	sfSprite *sp = NULL;

	goto_pause(engine, "speak");
	if (speak->font != NULL && speak->text != NULL && \
speak->text_comp != NULL) {
		engine->add_to_layer(engine, UI_TEXT, \
(void **)&(speak->text_comp));
		display_next_line(speak, engine);
		sfText_setPosition(speak->text_comp, pos_world_pos);
	}
	face = create_prefab_image(engine, speak->portrait, UI_IMAGE - 1);
	sp = ((sf_animation_2d_t *)get_component(face, ANIMATION_2D))->sprite;
	sfSprite_setOrigin(sp, (sfVector2f){sfSprite_getLocalBounds(sp).width \
/ 2, sfSprite_getLocalBounds(sp).height / 2});
	sfSprite_setPosition(sp, face_pos);
	calc_go_to_old_camera(engine, face);
}

void destroy_speak_component(sf_speak_t *speak)
{
	if (speak == NULL)
		return;
	if (speak->text != NULL)
		free(speak->text);
	if (speak->portrait != NULL)
		free(speak->portrait);
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
	speak->portrait = NULL;
	speak->line = -1;
	speak->text_comp = sfText_create();
	speak->set_font = &set_font;
	speak->set_info = &set_info;
	speak->show = &show;
	return (speak);
}