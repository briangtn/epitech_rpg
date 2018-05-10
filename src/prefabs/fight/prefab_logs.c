/*
** EPITECH PROJECT, 2017
** My rpg
** File description:
** prefab log
*/

#include "my_sfml.h"
#include "fight.h"
#include "rpg.h"

static int setup_components(gameobject_t *go, sf_engine_t *engine,\
sf_vector_3d_t pos)
{
	sf_transform_t *tr = get_component(go, TRANSFORM);
	sf_logs_t *logs = get_component(go, LOGS);

	if (tr == NULL || logs == NULL)
		return (84);
	tr->position = pos;
	logs->engine = engine;
	init_log_messages(logs, 4);
	return (0);
}

static int add_components(gameobject_t *go)
{
	if (add_component(go, TRANSFORM) == NULL)
		return (84);
	if (add_custom_component(go, (void *(*)(gameobject_t *))\
&create_enemy_comp, LOGS) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_log(sf_engine_t *engine, sf_vector_3d_t pos)
{
	gameobject_t *go = create_gameobject("logs");

	if (go == NULL)
		return (NULL);
	if (add_components(go) == 84 || setup_components(go, engine, pos) == 84)
		return (NULL);
	engine->add_update(engine, go, (UPDATER)&update_logs_component);
	return (go);
}