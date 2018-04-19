/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Handle the player movement and setup of the animation
*/

/* File created the 19/04/2018 at 11:38:45 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "my.h"
#include "prefabs.h"
#include "rpg.h"

static void update_animation(gameobject_t *player, sfVector2f axis)
{
	sf_animation_2d_t *anim = get_component(player, ANIMATION_2D);

	if (anim == NULL)
		return;
	if (axis.x || axis.y)
		anim->play = true;
	else
		anim->play = false;
	if (axis.x > 0.0)
		anim->max_rect.top = PLAYER_RIGHT_ANIM * TILE_SIZE;
	if (axis.x < 0.0)
		anim->max_rect.top = PLAYER_LEFT_ANIM * TILE_SIZE;
	if (axis.y > 0.0)
		anim->max_rect.top = PLAYER_DOWN_ANIM * TILE_SIZE;
	if (axis.y < 0.0)
		anim->max_rect.top = PLAYER_UP_ANIM * TILE_SIZE;
	anim->view_rect.top = anim->max_rect.top;
	if (anim->play == false)
		anim->view_rect.left = (PLAYER_NB_FRAME_ANIMATION - 1) * 32;
	sfSprite_setTextureRect(anim->sprite, anim->view_rect);
}

int player_movement(gameobject_t *player, UNUSED int delta_time)
{
	sf_rigidbody_2d_t *rb = get_component(player, RIGIDBODY_2D);
	sfVector2f axis = (sfVector2f){0, 0};

	if (player == NULL || rb == NULL) {
		my_puterror("Error in player movement, component not found\n");
		return (84);
	}
	axis.x = sfKeyboard_isKeyPressed(72) - sfKeyboard_isKeyPressed(71);
		rb->speed.x = 32 * axis.x * PLAYER_MOVEMENT_SPEED_MUL;
	axis.y = sfKeyboard_isKeyPressed(74) - sfKeyboard_isKeyPressed(73);
		rb->speed.y = 32 * axis.y * PLAYER_MOVEMENT_SPEED_MUL;
	update_animation(player, axis);
	return (0);
}