/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Render the current particle system
*/

/* File created the 17/03/2018 at 13:04:53 by julian.frabel@epitech.eu */

#include "my_sfml_graphics.h"

static sfBlendMode get_blend_mode(blend_mode_t mode)
{
	switch (mode) {
	case NONE: return (sfBlendNone);
	case MULTIPLY: return (sfBlendMultiply);
	case ADD: return (sfBlendAdd);
	case ALPHA: return (sfBlendAlpha);
	default: return (sfBlendNone);
	}
}

static void render_particle(sfRenderWindow *window, sf_particle_t *particle)
{
	sfSprite *spr = NULL;
	sfRenderStates state;
	sf_system_settings_t *settings = NULL;

	if (particle == NULL)
		return;
	settings = particle->parent->settings;
	spr = particle->parent->sprite;
	sfSprite_setColor(spr, particle->color);
	sfSprite_setRotation(spr, particle->rotation);
	sfSprite_setPosition(spr, \
(sfVector2f){particle->position.x, particle->position.y});
	sfSprite_setScale(spr, (sfVector2f){particle->size, particle->size});
	state.blendMode = get_blend_mode(settings->blend_mode);
	state.transform = sfTransform_Identity;
	state.texture = particle->parent->texture;
	state.shader = NULL;
	sfRenderWindow_drawSprite(window, spr, &state);
}

int particle_system_render(sfRenderWindow *window, sf_particle_system_t *sys)
{
	sf_linked_list_t *curr = NULL;

	if (sys == NULL || window == NULL)
		return (84);
	for (curr = sys->child_particles; curr != NULL; curr = curr->next) {
		render_particle(window, curr->data);
	}
	return (0);
}