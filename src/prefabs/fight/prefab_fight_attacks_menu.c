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

static int animation_update(sf_animation_2d_t *anim,\
UNUSED int elapsed_milliseconds)
{
	sf_transform_t *transform = get_component(anim->parent, TRANSFORM);

	if (anim == NULL || transform == NULL)
		return (84);
	sfSprite_setPosition(anim->sprite,\
(sfVector2f){transform->position.x, transform->position.y});
	return (0);
}

static int setup_components(sf_engine_t *engine, gameobject_t *go,\
UNUSED sf_linked_list_t *attacks, gameobject_t *arrow_go)
{
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_transform_t *transform = get_component(go, TRANSFORM);
	sf_attack_menu_t *menu = get_component(go, FATTACKMENU);

	if (anim == NULL || transform == NULL || menu == NULL)
		return (84);
	anim->set_sprite(anim, engine->get_sprite(engine,\
"assets/spritesheets/attack_menu.png"));
	anim->update = &animation_update;
	transform->position = (sf_vector_3d_t){100, WINDOW_SIZE_Y - 400, 0};
	sfSprite_setScale(anim->sprite, (sfVector2f){2, 2});
	menu->arrow = arrow_go;
	menu->engine = engine;
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
	if (add_custom_component(menu, (void *(*)(gameobject_t *))\
&create_fattack_menu_comp, FATTACKMENU) == NULL)
		return (84);
	return (0);
}

static gameobject_t *prepare_arrow(sf_engine_t *engine,\
gameobject_t *new_menu, fight_t *fight)
{
	gameobject_t *arrow_go = create_prefab_farrow(engine,\
fight->player->attacks, &menu_arrow_val, AMENU_SELECTOR);
	sf_fight_arrow_t *arrow = get_component(arrow_go, FARROW);
	sf_vector_3d_t pos = {100, WINDOW_SIZE_Y - 400, 0};
	sf_linked_list_t *copy = fight->player->attacks;

	if (arrow == NULL)
		return (NULL);
	for (int i = 0; copy; i++) {
		((attack_t *)copy->data)->go = create_prefab_ftext(engine,\
(sf_vector_3d_t){pos.x + 30, pos.y + i * 40, 0}, copy->data, fight);
		copy = copy->next;
	}
	arrow = get_component(arrow_go, FARROW);
	if (arrow == NULL)
		return (NULL);
	arrow->elem_size = 40;
	arrow->dir = VERTICAL;
	arrow->elem_offset = 20;
	arrow->callback_param = new_menu;
	return (arrow_go);
}

gameobject_t *create_prefab_fattack_menu(sf_engine_t *engine,\
fight_t *fight)
{
	gameobject_t *new_menu = create_gameobject("fight_attacks_menu");
	sf_linked_list_t *attacks = fight->player->attacks;
	gameobject_t *arrow_go = prepare_arrow(engine, new_menu, fight);
	sf_attack_menu_t *menu = NULL;

	if (new_menu == NULL || arrow_go == NULL)
		return (NULL);
	if (add_components(new_menu) == 84) {
		new_menu->destroy(new_menu);
		return (NULL);
	}
	if (setup_components(engine, new_menu, attacks, arrow_go) == 84) {
		new_menu->destroy(new_menu);
		return (NULL);
	}
	menu = get_component(new_menu, FATTACKMENU);
	if (menu == NULL)
		return (NULL);
	menu->fight = fight;
	return (new_menu);
}