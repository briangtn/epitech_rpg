/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Load a scene (from the parsing)
*/

/* File created the 24/04/2018 at 13:41:45 by julian.frabel@epitech.eu */

#include "rpg.h"

void create_npc(sf_engine_t *engine, npc_info_t *info)
{
	gameobject_t *new_npc = create_prefab_npc(engine);
	sf_animation_2d_t *anim = get_component(new_npc, ANIMATION_2D);
	sf_transform_t *tr = get_component(new_npc, TRANSFORM);
	sf_npc_t *npc = get_component(new_npc, NPC);
	sf_collider_2d_t *col = get_component(new_npc, COLLIDER_2D);
	npc_id_info_t info_npc = NPC_IDS[info->npc_id - 1];

	if (!new_npc || !anim || !tr || !npc || !col)
		return;
	anim->set_sprite(anim, engine->get_sprite(engine, info_npc.npc_visual));
	tr->position = (sf_vector_3d_t){info->npc_pos.x, info->npc_pos.y, 0};
	npc->speak->set_info(npc->speak, info->event->text, info_npc.npc_face);
	npc->speak->end_func = info_npc.end_func;
	anim->max_rect = info_npc.max_rect;
	anim->view_rect = info_npc.frame;
	col->hitbox = anim->view_rect;
	sfSprite_setPosition(anim->sprite, (sfVector2f){info->npc_pos.x, \
info->npc_pos.y});
	sfSprite_setTextureRect(anim->sprite, anim->view_rect);
}

void create_invisible_walls(sf_engine_t *engine, game_info_t *info)
{
	gameobject_t *wall = NULL;
	sf_transform_t *tr = NULL;
	sf_collider_2d_t *col = NULL;

	for (int i = 0; i < 4; i++) {
		wall = create_gameobject("invisible wall");
		if (wall == NULL)
			continue;
		tr = wall->add_component(wall, TRANSFORM);
		wall->add_component(wall, RIGIDBODY_2D);
		col = wall->add_component(wall, COLLIDER_2D);
		col->hitbox = (sfIntRect){0, 0, TILE_SIZE * info->\
tile_per_scene.x * (i % 2), TILE_SIZE * info->tile_per_scene.y * !(i % 2)};
		tr->position.x = TILE_SIZE * (info->tile_per_scene.x) * \
(i == 2);
		tr->position.y = TILE_SIZE * (info->tile_per_scene.y) * \
(i == 3);
		engine->add_gameobject(engine, wall);
		engine->add_physic_object(engine, wall);
	}
}

void load_parsing_to_game_scene(parser_to_game_t *ptg, sf_engine_t *engine)
{
	sf_camera_t *camera = engine->current_scene->camera;
	scene_info_t *scene = ptg->game_info->scene[ptg->active_scene - 1];
	sfVector2u size = {ptg->game_info->tile_per_scene.x * TILE_SIZE, \
ptg->game_info->tile_per_scene.y * TILE_SIZE};

	if (scene == NULL)
		return;
	camera->scene_size = (sfIntRect){0, 0, size.x, size.y};
	create_prefab_image(engine, scene->background, 0);
	for (int i = 0; scene->tile != NULL && scene->tile[i] != NULL; i++) {
		create_prefab_tile(engine, scene->tile[i], scene->tileset);
	}
	for (int i = 0; scene->npc != NULL && scene->npc[i] != NULL; i++) {
		if (scene->npc[i]->npc_id <= NB_NPC_ID)
			create_npc(engine, scene->npc[i]);
	}
	create_invisible_walls(engine, ptg->game_info);
}