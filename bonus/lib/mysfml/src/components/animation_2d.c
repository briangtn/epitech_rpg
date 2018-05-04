/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Animation_t functions
*/

#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"
#include <stdlib.h>

sf_animation_2d_t *create_animation_2d(gameobject_t *parent)
{
	sf_animation_2d_t *new_animation = malloc(sizeof(*new_animation));

	if (new_animation == NULL) {
		my_putdebug("Create animation_2d:\n    ");
		my_putdebug(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_animation->parent = parent;
	new_animation->speed = 1.0;
	new_animation->timer = 0.0;
	new_animation->destroy = &destroy_animation_2d;
	new_animation->update = &default_update_animation;
	new_animation->set_sprite = &set_sprite_animation_2d;
	new_animation->sprite = NULL;
	new_animation->play = 0;
	new_animation->max_rect = (sfIntRect){0, 0, 1, 1};
	new_animation->view_rect = (sfIntRect){0, 0, 1, 1};
	return (new_animation);
}

void destroy_animation_2d(sf_animation_2d_t *animation)
{
	if (animation == NULL) {
		my_putdebug("Destroy animation:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return;
	}
	if (animation->sprite != NULL) {
		sfSprite_destroy(animation->sprite);
		animation->sprite = NULL;
	}
	free(animation);
}

int set_sprite_animation_2d(sf_animation_2d_t *animation, sfSprite *sprite)
{
	if (animation == NULL || sprite == NULL) {
		my_putdebug("Set sprite animation:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	if (animation->sprite)
		sfSprite_destroy(animation->sprite);
	animation->sprite = sprite;
	return (0);
}

int default_update_animation(sf_animation_2d_t *anim, int elapsed_milliseconds)
{
	int passed_frames = 0;
	sf_transform_t *tr = NULL;

	if (anim == NULL || anim->play == 0)
		return (0);
	tr = get_component(anim->parent, TRANSFORM);
	anim->timer += (float)(elapsed_milliseconds / 1000.0);
	if (anim->timer >= anim->speed) {
		passed_frames = anim->timer / anim->speed;
		anim->timer -= passed_frames * anim->speed;
		anim->view_rect.left = (anim->view_rect.left + passed_frames * \
anim->view_rect.width) % anim->max_rect.width + anim->max_rect.left;
		anim->view_rect.top = (anim->view_rect.top + passed_frames * \
anim->view_rect.height) % anim->max_rect.height + anim->max_rect.top;
	}
	if (anim->sprite != NULL)
		sfSprite_setTextureRect(anim->sprite, anim->view_rect);
	if (anim->sprite != NULL && tr != NULL)
		sfSprite_setPosition(anim->sprite, \
(sfVector2f){tr->position.x, tr->position.y});
	return (0);
}