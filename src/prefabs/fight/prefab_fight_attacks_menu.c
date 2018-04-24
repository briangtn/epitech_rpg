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

static int setup_components(sf_engine_t *engine, sf_linked_list_t *attacks,
gameobject_t *go)
{
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_transform_t *transform = get_component(go, TRANSFORM);

	if (anim == NULL || transform == NULL)
		return (84);
	anim->set_sprite(anim, engine->get_sprite(engine,\
"assets/spritesheets/attack_menu.png"));
	register_animation(engine, anim, GAME);
	return (0);
}

static int add_components(gameobject_t *menu)
{
	if (menu->add_component(menu, ANIMATION_2D) == NULL) {
		my_puterror("[ERROR]menu: Could not add animation!\n");
		return (84);
	}
	if (menu->add_component(menu, TRANSFORM) == NULL) {
		my_puterror("[ERROR]menu: Could not add tranform\n");
		return (84);
	}
	return (0);
}

gameobject_t *create_prefab_farrow(sf_engine_t *engine, fight_t *fight,\
int (*callback)(void *, sf_linked_list_t *), void *callback_val)
{
	gameobject_t *new_menu = create_gameobject("fight_attacks_menu");

	if (new_menu == NULL)
		return (NULL);
	if (add_components(new_menu) == 84) {
		new_menu->destroy(new_menu);
		my_puterror("[ERROR]menu: Could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_menu, fight) == 84) {
		new_menu->destroy(new_menu);
		my_puterror("[ERROR]menu: Could not setup components!\n");
		return (NULL);
	}
	return (new_menu);
}