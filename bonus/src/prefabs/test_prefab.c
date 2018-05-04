/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** editor
*/

#include "my.h"
#include "my_sfml.h"
#include "config.h"

static int setup_test_components(sf_engine_t *engine, gameobject_t *gameobject)
{
	sf_animation_2d_t *animation = get_component(gameobject, ANIMATION_2D);

	if (animation == NULL)
		return (84);
	animation->set_sprite(animation, \
	engine->get_sprite(engine, "../assets/grid.png"));
	engine->add_to_layer(engine, GAME, (void**)&animation->sprite);
	return (0);
}

static int create_grid_components(gameobject_t *gameobject)
{
	if (gameobject->add_component(gameobject, TRANSFORM) == NULL)
		return (84);
	if (gameobject->add_component(gameobject, ANIMATION_2D) == NULL)
		return (84);
	if (add_custom_component(gameobject, (void*(*)(gameobject_t*))&create_grid_comp, GRID) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_test_prefab(sf_engine_t *engine)
{
	gameobject_t *gameobject = create_gameobject("grid");

	if (gameobject == NULL)
		return (NULL);
	if (create_grid_components(gameobject) == 84) {
		gameobject->destroy(gameobject);
		return (NULL);
	}
	if (setup_test_components(engine, gameobject) == 84) {
		gameobject->destroy(gameobject);
		return (NULL);
	}
	engine->add_update(engine, get_component(gameobject, TEST), (void*)&update_test_comp);
	return (gameobject);
}