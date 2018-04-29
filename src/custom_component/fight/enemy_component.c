/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** Rpg enemy component
*/

#include <stdlib.h>
#include "my_sfml.h"
#include "rpg.h"
#include "utils.h"

static void destroy_enemy_comp(sf_enemy_t *comp)
{
	if (comp == NULL)
		return;
	free(comp);
}

void destroy_enemy(sf_engine_t *engine, gameobject_t *go)
{
	sf_enemy_t *enemy = get_component(go, FENEMY);
	sf_loadbar_t *loadbar = NULL;

	if (enemy == NULL)
		return;
	loadbar = get_component(enemy->life_bar_go, LOADBAR);
	if (loadbar == NULL)
		return;
	engine->destroy_gameobject(engine, loadbar->back_go);
	engine->destroy_gameobject(engine, enemy->life_bar_go);
	engine->destroy_gameobject(engine, go);
}

int update_enemy(void *datas, UNUSED int delta_time)
{
	gameobject_t *go = (gameobject_t *)datas;
	sf_enemy_t *enemy = get_component(go, FENEMY);
	sf_loadbar_t *life_bar = NULL;

	if (enemy == NULL)
		return (84);
	life_bar = get_component(enemy->life_bar_go, LOADBAR);
	life_bar->current_value = enemy->datas->life;
	return (0);
}

sf_enemy_t *create_enemy_comp(gameobject_t *parent)
{
	sf_enemy_t *enemy = malloc(sizeof(*enemy));

	if (enemy == NULL)
		return (NULL);
	enemy->parent = parent;
	enemy->destroy = &destroy_enemy_comp;
	enemy->fight = NULL;
	enemy->datas = NULL;
	enemy->life_bar_go = NULL;
	return (enemy);
}