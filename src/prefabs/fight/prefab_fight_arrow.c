/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Prefab for red arrow selector
*/

#include "my.h"
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

static int farrow_animation_update(sf_animation_2d_t *anim,\
UNUSED int elapsed_milliseconds)
{
	sf_transform_t *transform = get_component(anim->parent, TRANSFORM);
	sf_fight_arrow_t *farrow = get_component(anim->parent, FARROW);
	sf_linked_list_t *enemies = farrow->fight->ennemies;
	sf_transform_t *enemy_tr = NULL;

	if (anim == NULL || transform == NULL)
		return (84);
	if (is_key_just_pressed(sfKeyLeft) && farrow->enemy_index > 0) {
		farrow->enemy_index--;
	} else if (is_key_just_pressed(sfKeyRight) &&\
get_elem_at_index(farrow->enemy_index + 1, enemies) != NULL) {
		farrow->enemy_index++;
	} else if (is_key_just_pressed(sfKeyReturn)) {
		//TODO
	}
	enemies = get_elem_at_index(farrow->enemy_index, enemies);
	enemy_tr = get_component(((fight_enemy_t *)(enemies->data))->go,\
TRANSFORM);
	if (enemy_tr == NULL)
		return (0);
	sfSprite_setPosition(anim->sprite,\
(sfVector2f){enemy_tr->position.x + FIGHT_ELEMENT_SIZE / 4,\
enemy_tr->position.y - 100});
	return (0);
}

static int setup_components(sf_engine_t *engine, gameobject_t *enemy,\
fight_t *fight)
{
	sf_animation_2d_t *anim = get_component(enemy, ANIMATION_2D);
	sf_transform_t *transform = get_component(enemy, TRANSFORM);
	sf_fight_arrow_t *arrow = get_component(enemy, FARROW);

	if (anim == NULL || transform == NULL || arrow == NULL)
		return (84);
	anim->update = farrow_animation_update;
	anim->set_sprite(anim, engine->get_sprite(engine,\
"assets/spritesheets/arrow.png"));
	register_animation(engine, anim, GAME);
	arrow->fight = fight;
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
	if (add_custom_component(arrow, (void *(*)(gameobject_t *))\
&create_farrow_comp, FARROW) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_farrow(sf_engine_t *engine, int enemy_count,\
int pos, fight_t *fight)
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
	if (setup_components(engine, new_arrow, fight) == 84) {
		new_arrow->destroy(new_arrow);
		my_puterror("[ERROR]arrow: Could not setup components!\n");
		return (NULL);
	}
	tr = get_component(new_arrow, TRANSFORM);
	if (tr == NULL)
		return (NULL);
	tr->position =\
(sf_vector_3d_t){get_enemy_posx(engine, enemy_count, pos) +\
FIGHT_ELEMENT_SIZE / 4, 250, 0};
	return (new_arrow);
}