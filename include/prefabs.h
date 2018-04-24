/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Prefabs include
*/

/* File created the 04/04/2018 at 14:11:23 by julian.frabel@epitech.eu */

#ifndef __PREFABS__H_
	#define __PREFABS__H_

	#include "my_sfml.h"
	#include "fight.h"
	#include "parsing.h"

	#pragma region Player

	#define PLAYER_MOVEMENT_SPEED_MUL 3
	#define PLAYER_ANIMATION_SPEED .2
	#define PLAYER_NB_FRAME_ANIMATION 4
	#define PLAYER_DOWN_ANIM 0
	#define PLAYER_LEFT_ANIM 1
	#define PLAYER_RIGHT_ANIM 2
	#define PLAYER_UP_ANIM 3
	#define PLAYER_SPRITE_SHEET SPRITESHEET_PLAYER

	gameobject_t *create_prefab_player(sf_engine_t *engine);
	void destroy_prefab_player(gameobject_t *player);

	int player_movement(gameobject_t *player, int delta_time);

	#pragma endregion /* !Player */

	#pragma region NpcPrefab

	#define NPC_MOVEMENT_SPEED_MUL 3
	#define NPC_ANIMATION_SPEED .2
	#define NPC_NB_FRAME_ANIMATION 4
	#define NPC_SPRITE_SHEET SPRITESHEET_GUARD

	gameobject_t *create_prefab_npc(sf_engine_t *engine);
	void npc_interaction(gameobject_t *npc, sf_engine_t *engine);

	#pragma endregion

	#pragma region CustomComponent

	enum custom_component_s {
		INTERACTION,
		NPC,
		FARROW
	};

	#pragma region Interaction

	typedef struct interaction_s {
		void (*destroy)();
		gameobject_t *parent;
		void (*interaction)(gameobject_t *go, sf_engine_t *engine);
		sf_engine_t *engine;
	} sf_interaction_t;

	sf_interaction_t *create_interaction(gameobject_t *parent);
	void destroy_interaction(sf_interaction_t *interaction);
	void run_interactions(sf_engine_t *engine, gameobject_t *from);

	#pragma endregion

	#pragma region Npc

	typedef struct npc_component_s {
		void (*destroy)();
		gameobject_t *parent;
		char *text;
	} sf_npc_t;

	sf_npc_t *create_npc_comp(gameobject_t *parent);
	void destroy_npc_comp(sf_npc_t *comp);

	#pragma endregion

	#pragma region Fight

	gameobject_t *create_prefab_fbackground(sf_engine_t *engine,\
fight_t *fight);
	gameobject_t *create_prefab_fplayer(sf_engine_t *engine,\
fight_t *fight);
	gameobject_t *create_prefab_fenemy(sf_engine_t *engine,\
fight_enemy_t *enemy, int position, int enemy_count);
	gameobject_t *create_prefab_farrow(sf_engine_t *engine,\
sf_linked_list_t *list,\
int (*callback)(void *, sf_linked_list_t *), void *callback_val);
	gameobject_t *create_prefab_fattack_menu(sf_engine_t *engine,\
sf_linked_list_t *attacks);
	gameobject_t *create_prefab_ftext(sf_engine_t *engine,\
sf_vector_3d_t pos, char *content);

	#pragma endregion

	#pragma region Tiles

	gameobject_t *create_prefab_tile(sf_engine_t *engine, \
tile_info_t *info, char *tileset);

	#pragma endregion

#endif /* !__PREFABS__H_ */