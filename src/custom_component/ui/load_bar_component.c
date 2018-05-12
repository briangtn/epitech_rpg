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

int loadbar_update(void *obj, UNUSED int delta_time)
{
	gameobject_t *go = (gameobject_t *)obj;
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_loadbar_t *loadbar = get_component(go, LOADBAR);
	sf_animation_2d_t *back_anim = get_component(loadbar->back_go,\
ANIMATION_2D);
	sfVector2f sizes = {0, 0};

	if (anim == NULL || loadbar == NULL)
		return (84);
	sfSprite_setColor(anim->sprite, loadbar->fore_color);
	sizes = (sfVector2f){loadbar->sizes.x, loadbar->sizes.y};
	sizes.x *= (loadbar->current_value / loadbar->max_value);
	if (sizes.x <= 0)
		sizes.x = 0;
	sfSprite_setScale(anim->sprite, sizes);
	if (back_anim)
		sfSprite_setColor(back_anim->sprite, loadbar->back_color);
	return (0);
}

static void destroy_loadbar_comp(sf_loadbar_t *comp)
{
	if (comp == NULL || comp->engine == NULL)
		return;
	comp->engine->destroy_gameobject(comp->engine, comp->back_go);
	free(comp);
}

int move_loadbar(gameobject_t *go, sfVector2f pos)
{
	sf_loadbar_t *loadbar = get_component(go, LOADBAR);
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_animation_2d_t *back_anim = NULL;
	sfVector2f position = {pos.x, pos.y};

	if (loadbar == NULL || anim == NULL)
		return (84);
	back_anim = get_component(loadbar->back_go, ANIMATION_2D);
	if (back_anim == NULL)
		return (84);
	sfSprite_setPosition(anim->sprite, position);
	sfSprite_setPosition(back_anim->sprite, position);
	return (0);
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
	loadbar->sizes = (sf_vector_2d_t){100, 10};
	loadbar->back_go = NULL;
	loadbar->engine = NULL;
	return (loadbar);
}