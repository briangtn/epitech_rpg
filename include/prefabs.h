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
	#define PLAYER_SPRINT_MUL 2
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
		FARROW,
		FATTACKMENU,
		FENEMY,
		LOADBAR,
		FPLAYER,
		TILE_EFFECT,
		INVENTORY
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

	#pragma region Speak

	typedef struct speak_s {
		void (*destroy)();
		gameobject_t *parent;
		int line;
		char *text;
		sfText *text_comp;
		sfFont *font;
		char *portrait;
		void (*show)(struct speak_s *speak, sf_engine_t *engine);
		void (*set_font)(struct speak_s *speak, const char *font);
		void (*set_info)(struct speak_s *speak, const char *text, \
const char *portrait);
	} sf_speak_t;

	void display_next_line(sf_speak_t *speak, sf_engine_t *engine);
	sf_speak_t *create_speak_component(gameobject_t *parent);

	#pragma endregion

	#pragma region Npc

	typedef struct npc_component_s {
		void (*destroy)();
		gameobject_t *parent;
		struct speak_s *speak;
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
fight_enemy_t *enemy, int position, fight_t *fight);
	gameobject_t *create_prefab_farrow(sf_engine_t *engine,\
sf_linked_list_t *list,\
int (*callback)(void *, sf_linked_list_t *, sf_fight_arrow_t *), char *sprite);
	gameobject_t *create_prefab_fattack_menu(sf_engine_t *engine,\
fight_t *fight);
	gameobject_t *create_prefab_ftext(sf_engine_t *engine,\
sf_vector_3d_t pos, attack_t *attack, fight_t *fight);
	gameobject_t *create_prefab_loadbar(sf_engine_t *engine,\
sfFloatRect rect, float max);
	gameobject_t *create_prefab_loadbar_back(sf_engine_t *engine,\
sfFloatRect rect, sfColor color);
	gameobject_t *create_prefab_mana_text(sf_engine_t *engine,\
fight_player_t *player);

	#pragma endregion

	#pragma region Tiles

	typedef struct tile_effect {
		void (*destroy)();
		gameobject_t *parent;
		sf_engine_t *engine;
		int teleport_scene;
		sfVector2i teleport_coords;
		int fight_id;
	} sf_tile_effect_t;

	sf_tile_effect_t *create_tile_effect(gameobject_t *parent);
	void destroy_tile_effect(sf_tile_effect_t *effect);

	gameobject_t *create_prefab_tile(sf_engine_t *engine, \
tile_info_t *info, char *tileset);

	void set_teleport_tile(sf_collider_2d_t *col, sf_tile_effect_t *effect,\
tile_info_t *info);
	int teleport(gameobject_t *tile, gameobject_t *player);

	void set_tile_particles(sf_collider_2d_t *col, \
sf_tile_effect_t *effect, tile_info_t *info);

	void set_fight_tile(sf_collider_2d_t *col, sf_tile_effect_t *effect, \
tile_info_t *info);

	#pragma endregion

	#pragma region Inventory

	#define INV_SIZE (10)

	typedef enum e_items {
		ITEM_POTION_S,
		ITEM_POTION_L,
		ITEM_SPELL_A,
		ITEM_SPELL_B,
		ITEM_SPELL_C,
		ITEM_NULL
	} e_itemtype_t;

	typedef struct s_items {
		char *name;
		char *sprite_path;
		float value;
		bool self_use;
	} items_t;

	extern const items_t ITEM_LIST[ITEM_NULL + 1];

	typedef struct s_inventory_comp {
		void (*destroy)();
		gameobject_t *parent;
		sf_engine_t *engine;
		sfSprite *sprite;
		bool is_opened;
		float hp;
		float s_atk;
		gameobject_t *prgbar_atk;
		float s_def;
		gameobject_t *prgbar_def;
		float s_dex;
		gameobject_t *prgbar_dex;
		float s_int;
		gameobject_t *prgbar_int;
		items_t backpack[INV_SIZE];
		sfSprite *bp_sprite[INV_SIZE];
		void (*toggle)(struct s_inventory_comp *);
	} sf_inventory_t;

	sf_inventory_t *create_inventory(gameobject_t *parent);
	int player_inventory(gameobject_t *player, int delta_time);

	#pragma endregion
#endif /* !__PREFABS__H_ */