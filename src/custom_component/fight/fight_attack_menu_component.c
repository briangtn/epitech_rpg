/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fight arrow component
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

static void destroy_menu_comp(sf_fight_arrow_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

void destroy_fattack_menu(sf_attack_menu_t *comp)
{
	sf_fight_arrow_t *arrow_comp = NULL;
	sf_linked_list_t *attacks = NULL;
	sf_engine_t *engine = NULL;

	if (comp == NULL || comp->arrow == NULL)
		return;
	engine = comp->engine;
	arrow_comp = get_component(comp->arrow, FARROW);
	if (engine == NULL || arrow_comp == NULL)
		return;
	attacks = arrow_comp->list;
	while (attacks) {
		engine->destroy_gameobject(engine,\
((arrow_elem_base_t *)attacks->data)->go);
		((arrow_elem_base_t *)attacks->data)->go = NULL;
		attacks = attacks->next;
	}
	engine->destroy_gameobject(engine, comp->arrow);
	engine->destroy_gameobject(engine, comp->parent);
}

int menu_arrow_val(void *data, UNUSED sf_linked_list_t *elem,\
UNUSED sf_fight_arrow_t *arrow)
{
	gameobject_t *go = (gameobject_t *)data;
	sf_attack_menu_t *menu = NULL;

	if (go == NULL)
		return (84);
	menu = get_component(go, FATTACKMENU);
	if (menu == NULL)
		return (84);
	if (menu->fight->player->mana < ((attack_t *)elem->data)->mana_cost)
		return (0);
	menu->fight->last_attack = (attack_t *)elem->data;
	select_enemy(menu->engine, menu->fight);
	destroy_fattack_menu(menu);
 	return (0);
}

sf_attack_menu_t *create_fattack_menu_comp(gameobject_t *parent)
{
	sf_attack_menu_t *menu = malloc(sizeof(*menu));

	if (menu == NULL)
		return (NULL);
	menu->parent = parent;
	menu->destroy = &destroy_menu_comp;
	menu->fight = NULL;
	menu->arrow = NULL;
	return (menu);
}