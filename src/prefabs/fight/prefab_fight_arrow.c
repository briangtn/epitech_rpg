/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Prefab for red arrow selector
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"

static int fenemy_animation_update(sf_animation_2d_t *anim,\
UNUSED int elapsed_milliseconds)
{
	sf_transform_t *transform = get_component(anim->parent, TRANSFORM);

	if (anim == NULL || transform == NULL)
		return (84);
	sfSprite_setPosition(anim->sprite,\
(sfVector2f){transform->position.x, transform->position.y});
	return (0);
}

static int setup_components(sf_engine_t *engine, gameobject_t *enemy,\
fight_enemy_t *fenemy)
{
	sf_animation_2d_t *anim = get_component(enemy, ANIMATION_2D);
	sf_transform_t *transform = get_component(enemy, TRANSFORM);

	if (anim == NULL || transform == NULL)
		return (84);
	anim->update = fenemy_animation_update;
	anim->set_sprite(anim, engine->get_sprite(engine,\
fenemy->sprite_path));
	register_animation(engine, anim, GAME);
	return (0);
}

static int add_components(gameobject_t *arrow)
{
	if (arrow->add_component(arrow, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]arrow: Could not add animation!\n");
		return (84);
	}
	if (arrow->add_component(arrow, TRANSFORM) == NULL) {
		my_puterror("[ERROR]arrow: Could not add tranform\n");
		return (84);
	}
	return (0);
}

gameobject_t *create_prefab_farrow(sf_engine_t *engine, fight_enemy_t *enemy,\
int position)
{
	gameobject_t *new_arrow = create_gameobject("fight_arrow");
	sf_transform_t *tr = NULL;

	if (new_arrow == NULL)
		return (NULL);
	if (add_components(new_arrow) == 84) {
		new_arrow->destroy(new_arrow);
		my_puterror("[ERROR]arrow: Could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_arrow, enemy) == 84) {
		new_arrow->destroy(new_arrow);
		my_puterror("[ERROR]arrow: Could not setup components!\n");
		return (NULL);
	}
	tr = get_component(new_arrow, TRANSFORM);
	if (tr == NULL)
		return (NULL);
	tr->position.x = position;
	return (new_arrow);
}