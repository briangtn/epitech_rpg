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
UNUSED sf_linked_list_t *attacks)
{
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_transform_t *transform = get_component(go, TRANSFORM);

	if (anim == NULL || transform == NULL)
		return (84);
	anim->set_sprite(anim, engine->get_sprite(engine,\
"assets/spritesheets/attack_menu.png"));
	anim->update = &animation_update;
	transform->position = (sf_vector_3d_t){100, WINDOW_SIZE_Y - 400, 0};
	sfSprite_setScale(anim->sprite, (sfVector2f){2, 2});
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
&create_farrow_comp, FARROW) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_fattack_menu(sf_engine_t *engine,\
sf_linked_list_t *attacks)
{
	gameobject_t *new_menu = create_gameobject("fight_attacks_menu");
	sf_linked_list_t *copy = attacks;
	sf_vector_3d_t pos = {100, WINDOW_SIZE_Y - 400, 0};
	gameobject_t *arrow_go =\
create_prefab_farrow(engine, attacks, NULL, "assets/spritesheets/arrow_mattack.png");
	sf_fight_arrow_t *arrow = NULL;
	int i = 0;

	if (new_menu == NULL || arrow_go == NULL)
		return (NULL);
	while (copy) {
		((attack_t *)copy->data)->go = create_prefab_ftext(engine,\
(sf_vector_3d_t){pos.x + 30, pos.y + i * 40, 0}, copy->id);
		i++;
		copy = copy->next;
	}
	arrow = get_component(arrow_go, FARROW);
	if (arrow) {
		arrow->elem_size = 40;
		arrow->dir = VERTICAL;
		arrow->elem_offset = 20;
	}
	if (add_components(new_menu) == 84) {
		new_menu->destroy(new_menu);
		my_puterror("[ERROR]menu: Could not add components!\n");
		return (NULL);
	}
	if (setup_components(engine, new_menu, attacks) == 84) {
		new_menu->destroy(new_menu);
		my_puterror("[ERROR]menu: Could not setup components!\n");
		return (NULL);
	}
	return (new_menu);
}