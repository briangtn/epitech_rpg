/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Represent a tile gameobject
*/

/* File created the 24/04/2018 at 10:51:20 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "parsing.h"
#include "rpg.h"

static int setup_image(gameobject_t *obj, sf_engine_t *engine, \
tile_info_t *info, char *tileset)
{
	sf_animation_2d_t *anim = obj->add_component(obj, ANIMATION_2D);
	sf_transform_t *tr = obj->add_component(obj, TRANSFORM);
	sfVector2f pos = {(info->tile_pos.x - 1) * TILE_SIZE, \
(info->tile_pos.y - 1) * TILE_SIZE};
	sfIntRect view_rect = {0, 0, TILE_SIZE, TILE_SIZE};
	sfVector2u tileset_size = {0, 0};

	if (anim == NULL || tr == NULL)
		return (84);
	if (anim->set_sprite(anim, engine->get_sprite(engine, tileset)) == 84)
		return (84);
	tileset_size = sfTexture_getSize(sfSprite_getTexture(anim->sprite));
	tileset_size.x /= TILE_SIZE;
	tileset_size.y /= TILE_SIZE;
	view_rect.top = ((info->tile_id - 1) / tileset_size.x) * TILE_SIZE;
	view_rect.left = ((info->tile_id - 1) % tileset_size.x) * TILE_SIZE;
	tr->move(tr, (sfVector3f){pos.x, pos.y, 0});
	sfSprite_setPosition(anim->sprite, pos);
	sfSprite_setTextureRect(anim->sprite, view_rect);
	return (0);
}

static void set_trigger_func(sf_collider_2d_t *col, \
tile_info_t *info, sf_engine_t *engine)
{
	gameobject_t *go = col->parent;
	sf_tile_effect_t *effect = go->add_custom_component(go, \
(void *(*)(gameobject_t *))&create_tile_effect, TILE_EFFECT);

	switch (info->event->event_id) {
	case TELEPORT:
		col->triggered_func = &teleport;
		effect->engine = engine;
		effect->teleport_scene = info->event->teleport[0];
		effect->teleport_coords = (sfVector2i){info->event->teleport[1]\
, info->event->teleport[2]};
		dprintf(2, "Teleport scene: %i, coords: x=%i,y=%i\n", effect->teleport_scene, effect->teleport_coords.x, effect->teleport_coords.y);
		break;
	case DIALOG:
		break;
	case FIGHT:
		break;
	};
}

static int setup_type(gameobject_t *go, sf_engine_t *engine, tile_info_t *info)
{
	sf_rigidbody_2d_t *rb = NULL;
	sf_collider_2d_t *col = NULL;

	if (info->tile_type != COLLIDE && info->event->event_id == 0)
		return (0);
	rb = go->add_component(go, RIGIDBODY_2D);
	col = go->add_component(go, COLLIDER_2D);
	if (rb == NULL || col == NULL)
		return (84);
	if (info->event->event_id != 0) {
		col->trigger = 1;
		col->collides = 0;
		set_trigger_func(col, info, engine);
	}
	engine->add_physic_object(engine, go);
	return (0);
}

gameobject_t *create_prefab_tile(sf_engine_t *engine, tile_info_t *info, \
char *tileset)
{
	gameobject_t *go = NULL;
	sf_animation_2d_t *anim = NULL;

	if (engine == NULL || info == NULL || tileset == NULL)
		return (NULL);
	go = create_gameobject("tile");
	if (go == NULL)
		return (NULL);
	if (setup_image(go, engine, info, tileset) || \
setup_type(go, engine, info)) {
		go->destroy(go);
		return (NULL);
	}
	anim = get_component(go, ANIMATION_2D);
	if (info->tile_type != HIDE)
		engine->add_to_layer(engine, info->layer, \
(void **)&(anim->sprite));
	engine->add_gameobject(engine, go);
	return (go);
}