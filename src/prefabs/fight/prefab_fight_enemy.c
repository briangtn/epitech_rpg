/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Fighting backgound creation and destruction
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
	scale_elem_to_size(anim->sprite);
	register_animation(engine, anim, GAME);
	return (0);
}

static int add_components(gameobject_t *enemy)
{
	if (enemy->add_component(enemy, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]enemy: Could not add animation!\n");
		return (84);
	}
	if (enemy->add_component(enemy, TRANSFORM) == NULL) {
		my_puterror("[ERROR]enemy: Could not add tranform\n");
		return (84);
	}
	return (0);
}

gameobject_t *create_prefab_fenemy(sf_engine_t *engine, fight_enemy_t *enemy,\
int pos, int enemy_count)
{
	gameobject_t *new_enemy = create_gameobject("fight_enemy");
	sf_transform_t *tr = NULL;

	if (engine == NULL || new_enemy == NULL)
		return (NULL);
	if (add_components(new_enemy) == 84) {
		new_enemy->destroy(new_enemy);
		my_puterror("[ERROR]enemy: Could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_enemy, enemy) == 84) {
		new_enemy->destroy(new_enemy);
		my_puterror("[ERROR]enemy: Could not setup components!\n");
		return (NULL);
	}
	tr = get_component(new_enemy, TRANSFORM);
	if (tr == NULL)
		return (NULL);
	tr->position =\
(sf_vector_3d_t){get_enemy_posx(engine, enemy_count, pos), 300, 0};
	return (new_enemy);
}