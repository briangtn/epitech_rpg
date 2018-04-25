/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Fighting file
*/

#include "my_sfml.h"
#include "rpg.h"

static int when_enemy_selected(void *data, sf_linked_list_t *elem,\
sf_fight_arrow_t *arrow) {
	fight_t *fight = (fight_t *)data;
	fight_enemy_t *enemy = (fight_enemy_t *)elem->data;

	if (fight == NULL || enemy == NULL)
		return (84);
	my_printf("Player attacked %s using %s\n", enemy->name, fight->last_attack->name);
	//select_attack(arrow->engine)
	return (0);
}

void select_attack(sf_engine_t *engine, fight_t *fight)
{
	create_prefab_fattack_menu(engine, fight);
}

void select_enemy(sf_engine_t *engine, fight_t *fight)
{
	gameobject_t *go = create_prefab_farrow(engine,\
fight->ennemies, &when_enemy_selected, "assets/spritesheets/arrow.png");
	sf_fight_arrow_t *arrow = get_component(go, FARROW);

	if (arrow == NULL)
		return;
	arrow->callback_param = fight;
}