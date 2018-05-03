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

	if (new_npc == NULL || anim == NULL || tr == NULL || npc == NULL)
		return;
	if (info->npc_id > NB_NPC_ID) {
		engine->destroy_gameobject(engine, new_npc);
		return;
	}
	anim->set_sprite(anim, engine->get_sprite(engine, \
NPC_IDS[info->npc_id].npc_visual));
	tr->position = (sf_vector_3d_t){info->npc_pos.x, info->npc_pos.y, 0};
	npc->speak->set_info(npc->speak, info->event->text, \
NPC_IDS[info->npc_id].npc_face);
}

void load_parsing_to_game_scene(parser_to_game_t *ptg, sf_engine_t *engine)
{
	sf_camera_t *camera = engine->current_scene->camera;
	scene_info_t *scene = ptg->game_info->scene[ptg->active_scene];
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
		create_npc(engine, scene->npc[i]);
	}
}