/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Hide and show loadbars
*/

/* File created the 12/05/2018 at 13:48:36 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

void hide_load_bar(gameobject_t *loadbar, sf_engine_t *engine)
{
	sf_animation_2d_t *anim = get_component(loadbar, ANIMATION_2D);
	sf_loadbar_t *lb = get_component(loadbar, LOADBAR);

	if (anim != NULL)
		engine->remove_from_layers(engine, (void **)&(anim->sprite));
	if (lb != NULL)
		anim = get_component(lb->back_go, ANIMATION_2D);
	if (anim != NULL)
		engine->remove_from_layers(engine, (void **)&(anim->sprite));
}

void show_load_bar(gameobject_t *loadbar, sf_engine_t *engine)
{
	sf_animation_2d_t *anim = get_component(loadbar, ANIMATION_2D);
	sf_loadbar_t *lb = get_component(loadbar, LOADBAR);

	if (anim != NULL)
		engine->add_to_layer(engine, UI_IMAGE, \
(void **)&(anim->sprite));
	if (lb != NULL)
		anim = get_component(lb->back_go, ANIMATION_2D);
	if (anim != NULL)
		engine->add_to_layer(engine, UI_IMAGE - 1, \
(void **)&(anim->sprite));
}