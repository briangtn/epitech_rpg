/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Player creation and destruction
*/

/* File created the 04/04/2018 at 14:10:22 by julian.frabel@epitech.eu */

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static void setup_animation(sf_engine_t *engine, sf_animation_2d_t *anim)
{
	anim->max_rect = (sfIntRect){0, 0, PLAYER_NB_FRAME_ANIMATION * \
TILE_SIZE, TILE_SIZE};
	anim->play = 1;
	anim->set_sprite(anim, engine->get_sprite(engine, PLAYER_SPRITE_SHEET));
	anim->speed = PLAYER_ANIMATION_SPEED;
	anim->view_rect = (sfIntRect){0, 0, TILE_SIZE, TILE_SIZE};
}

static int setup_components(sf_engine_t *engine, gameobject_t *player)
{
	sf_animation_2d_t *anim = get_component(player, ANIMATION_2D);

	setup_animation(engine, anim);
	register_animation(engine, anim, GAME);
	engine->add_gameobject(engine, player);
	return (0);
}

static int add_components(gameobject_t *player)
{
	if (player->add_component(player, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]Player: Could not add animation!\n");
		return (84);
	}
	return (0);
}

gameobject_t *create_prefab_player(sf_engine_t *engine)
{
	gameobject_t *new_player = create_gameobject("player");

	if (new_player == NULL)
		return (NULL);
	if (add_components(new_player) == 84) {
		new_player->destroy(new_player);
		my_puterror("[ERROR]Player: could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_player) == 84) {
		new_player->destroy(new_player);
		my_puterror("[ERROR]Player: could not setup components!\n");
		return (NULL);
	}
	return (new_player);
}