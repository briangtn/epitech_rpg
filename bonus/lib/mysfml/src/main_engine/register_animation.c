/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Register an animation to the engine
*/

/* File created the 04/04/2018 at 15:42:42 by julian.frabel@epitech.eu */

#include "my_sfml.h"

void register_animation(sf_engine_t *engine, sf_animation_2d_t *anim, int layer)
{
	if (engine == NULL || anim == NULL) {
		my_putdebug("[ERROR]Could not register animation!\n");
		return;
	}
	engine->add_update(engine, (void *)anim, (UPDATER)anim->update);
	engine->add_to_layer(engine, layer, (void **)&anim->sprite);
}