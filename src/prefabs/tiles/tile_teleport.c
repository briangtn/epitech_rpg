/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Teleport trigger
*/

/* File created the 03/05/2018 at 16:01:42 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "prefabs.h"
#include "parser.h"
#include "rpg.h"

int discard_teleport(sf_engine_t *engine, gameobject_t *player)
{
	sf_speak_t *discard = create_speak_component(NULL);
	sf_transform_t *tr = get_component(player, TRANSFORM);
	sf_animation_2d_t *anim = get_component(player, ANIMATION_2D);
	sf_rigidbody_2d_t *rb = get_component(player, RIGIDBODY_2D);

	discard->set_info(discard, DISCARD_MESSAGE, FACE_HERO);
	discard->set_font(discard, FONT_SPEAK);
	discard->show(discard, engine);
	tr->position.y = 12;
	rb->acceleration.y = 0;
	rb->speed.y = 0;
	sfSprite_setPosition(anim->sprite, (sfVector2f){tr->position.x, \
tr->position.y});
	return (0);
}

int teleport(gameobject_t *tile, gameobject_t *player)
{
	sf_inventory_t *inv = get_component(player, INVENTORY);
	sf_tile_effect_t *effect = get_component(tile, TILE_EFFECT);
	parser_to_game_t *ptg = effect->engine->data;

	if (effect == NULL || ptg == NULL)
		return (84);
	if (inv->retrieve_item(inv, &(ITEM_LIST[ITEM_SWORD])) == -1) {
		return (discard_teleport(effect->engine, player));
	}
	ptg->player_start_pos = (sf_vector_3d_t){(effect->teleport_coords.x - 1\
) * TILE_SIZE, (effect->teleport_coords.y - 1) * TILE_SIZE, 0};
	ptg->active_scene = effect->teleport_scene;
	effect->engine->change_scene(effect->engine, "game", ptg);
	return (0);
}

void set_teleport_tile(sf_collider_2d_t *col, sf_tile_effect_t *effect, \
tile_info_t *info)
{
	col->triggered_func = &teleport;
	effect->teleport_scene = info->event->teleport[0];
	effect->teleport_coords = (sfVector2i){info->event->teleport[1]\
, info->event->teleport[2]};
}