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

static int setup_components(sf_engine_t *engine, gameobject_t *enemy,\
sf_linked_list_t *list)
{
	sf_animation_2d_t *anim = get_component(enemy, ANIMATION_2D);
	sf_transform_t *transform = get_component(enemy, TRANSFORM);
	sf_fight_arrow_t *arrow = get_component(enemy, FARROW);

	if (anim == NULL || transform == NULL || arrow == NULL)
		return (84);
	anim->update = arrow->display_update;
	anim->set_sprite(anim, engine->get_sprite(engine,\
"assets/spritesheets/arrow.png"));
	register_animation(engine, anim, GAME);
	arrow->list = list;
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

gameobject_t *create_prefab_farrow(sf_engine_t *engine, sf_linked_list_t *list,\
int (*callback)(void *, sf_linked_list_t *), void *callback_val)
{
	gameobject_t *new_arrow = create_gameobject("fight_arrow");
	sf_fight_arrow_t *farrow = NULL;

	if (new_arrow == NULL)
		return (NULL);
	if (add_components(new_arrow) == 84) {
		new_arrow->destroy(new_arrow);
		my_puterror("[ERROR]arrow: Could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_arrow, list) == 84) {
		new_arrow->destroy(new_arrow);
		my_puterror("[ERROR]arrow: Could not setup components!\n");
		return (NULL);
	}
	farrow = get_component(new_arrow, FARROW);
	if (farrow == NULL)
		return (NULL);
	farrow->callback = callback;
	farrow->callback_param = callback_val;
	engine->add_update(engine, farrow, (UPDATER)farrow->update);
	return (new_arrow);
}