/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fighting backgound creation and destruction
*/

/* File created the 04/04/2018 at 14:10:22 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static int setup_components(sf_engine_t *engine, gameobject_t *background,\
fight_t *fight)
{
	sfVector2u window_sizes = sfRenderWindow_getSize(engine->window);
	sfFloatRect sprite_size;
	sf_animation_2d_t *anim = get_component(background, ANIMATION_2D);

	if (anim == NULL)
		return (84);
	anim->set_sprite(anim, engine->get_sprite(engine, \
fight->background_path));
	sprite_size = sfSprite_getGlobalBounds(anim->sprite);
	sfSprite_setScale(anim->sprite, \
(sfVector2f){window_sizes.x / sprite_size.width, \
window_sizes.y / sprite_size.height});
	engine->add_to_layer(engine, GAME - 1, (void **)&(anim->sprite));
	return (0);
}

static int add_components(gameobject_t *background)
{
	if (background->add_component(background, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]Background: Could not add animation!\n");
		return (84);
	}
	return (0);
}

gameobject_t *create_prefab_fbackground(sf_engine_t *engine, fight_t *fight)
{
	gameobject_t *new_background = create_gameobject("fight_background");

	if (new_background == NULL)
		return (NULL);
	if (add_components(new_background) == 84) {
		new_background->destroy(new_background);
		my_puterror("[ERROR]Background: could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_background, fight) == 84) {
		new_background->destroy(new_background);
		my_puterror("[ERROR]Background: could not setup components!\n");
		return (NULL);
	}
	return (new_background);
}