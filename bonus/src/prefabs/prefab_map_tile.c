/*
** EPITECH PROJECT, 2017
** RPG map editor
** File description:
** Map tile prefab
*/

#include "my_sfml.h"
#include "components.h"

static int setup_components(sf_engine_t *engine, gameobject_t *go, int x, int y)
{
	sf_animation_2d_t *anim = get_component(go, ANIMATION_2D);
	sf_map_tile_t *tile = get_component(go, MAP_TILE);

	if (anim == NULL || tile == NULL)
		return (84);
	anim->sprite = get_sprite(engine, "assets/grid.png");
	register_animation(engine, anim, GAME);
	tile->engine = engine;
	tile->x = x;
	tile->y = y;
	tile->sprite_none = get_sprite(engine, "assets/grid.png");
	tile->sprite_tileset = get_sprite(engine, \
"assets/tilesets/outside_b.png");
	return (0);
}

static int add_components(gameobject_t *go)
{
	if (go->add_component(go, ANIMATION_2D) == NULL)
		return (84);
	if (go->add_custom_component(go,\
	(void *(*)(gameobject_t *))&create_map_tile_comp, MAP_TILE) == NULL)
		return (84);
	return (0);
}

gameobject_t *create_prefab_map_tile(sf_engine_t *engine, int x, int y)
{
	gameobject_t *go = create_gameobject("map_tile");

	if (go == NULL)
		return (NULL);
	if (add_components(go) == 84 ||\
	setup_components(engine, go, x, y) == 84)
		return (NULL);
	engine->add_update(engine, go, (UPDATER)&map_tile_update);
	return (go);
}