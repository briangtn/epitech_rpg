/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Load bar background prefab
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static int setup_components(sf_engine_t *engine, gameobject_t *go, \
sfFloatRect rect, sfColor color)
{
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);

	if (anim == NULL)
		return (84);
	anim->set_sprite(anim, engine->get_sprite(engine, WHITE_SPRITE));
	sfSprite_setPosition(anim->sprite, (sfVector2f){rect.left, rect.top});
	sfSprite_setScale(anim->sprite, (sfVector2f){rect.width, rect.height});
	sfSprite_setColor(anim->sprite, color);
	register_animation(engine, anim, UI_IMAGE - 1);
	return (0);
}

static int add_components(gameobject_t *enemy)
{
	if (enemy->add_component(enemy, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]enemy: Could not add animation!\n");
		return (84);
	}
	return (0);
}

gameobject_t *create_prefab_loadbar_back(sf_engine_t *engine, \
sfFloatRect rect, sfColor color)
{
	gameobject_t *new_go = create_gameobject("loadbar_back");

	if (engine == NULL || new_go == NULL)
		return (NULL);
	if (add_components(new_go) == 84) {
		new_go->destroy(new_go);
	}
	if (setup_components(engine, new_go, rect, color) == 84) {
		new_go->destroy(new_go);
		return (NULL);
	}
	return (new_go);
}