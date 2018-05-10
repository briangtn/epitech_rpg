/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Assets defines
*/

/* File created the 04/04/2018 at 14:40:54 by julian.frabel@epitech.eu */

#ifndef __ASSETS__H_
	#define __ASSETS__H_

	#include "fight.h"

	#pragma region Spritesheets
	#define SS_SIGN "assets/spritesheets/sign.png"
	#define SPRITESHEET_PLAYER "assets/spritesheets/player.png"
	#define SS_GUARD "assets/spritesheets/guard.png"
	#define SS_KING "assets/spritesheets/king.png"
	#define SS_BOSS "assets/spritesheets/evilking.png"
	#define SPRITE_BORDER "assets/spritesheets/border.png"
	#define SPRITE_SPEAK_BORDER "assets/spritesheets/speak_border.png"
	#define SPRITE_SPEAK_BG "assets/spritesheets/speak_background.png"
	#pragma endregion

	#pragma region Background
	#define BACKGROUND_WORLDMAP "assets/backgrounds/worldmap.png"
	#define BACKGROUND_FIGHT_PATH "assets/backgrounds/fight_path.png"
	#define BACKGROUND_CASTLE_FIGHT "assets/backgrounds/castle_fight.png"
	#define BACKGROUND_END "assets/backgrounds/end.png"
	#define BACKGROUND_INTRO "assets/backgrounds/intro.png"
	#pragma endregion

	#pragma region Particles
	#define PARTICLE_DEFAULT "assets/particles/particle_default.png"
	#pragma endregion

	#pragma region Enemys
	#define ENEMY_ROGUE "assets/enemys/rogue.png"
	#define ENEMY_BOSS "assets/enemys/evilking.png"
	#define ENEMY_FANATIC "assets/enemys/fanatic.png"
	#pragma endregion

	#pragma region Buttons
	#define BUTTON_GAME "assets/buttons/button_game.png"
	#define BUTTON_FIGHT "assets/buttons/button_fight.png"
	#define BUTTON_QUIT "assets/buttons/button_quit.png"
	#define BUTTON_RESUME "assets/buttons/button_resume.png"
	#define BUTTON_MENU "assets/buttons/button_menu.png"
	#pragma endregion

	#pragma region Face
	#define FACE_SIGN "assets/faces/sign.png"
	#define FACE_SOLDIER "assets/faces/guard.png"
	#define FACE_KING "assets/faces/king.png"
	#define FACE_EVILKING "assets/faces/evilking.png"
	#pragma endregion

	#pragma region Font
	#define FONT_SPEAK "assets/fonts/proggyclean.ttf"
	#pragma endregion

	typedef struct npc_id_info {
		int npc_id;
		char *npc_visual;
		char *npc_face;
		int (*end_func)(sf_engine_t *engine, gameobject_t *parent);
		sfIntRect frame;
		sfIntRect max_rect;
	} npc_id_info_t;

	typedef struct attack_info {
		char *name;
		int damage;
		int cost;
	} attack_info_t;

	typedef struct monster_info {
		int life;
		char *sprite;
		char *name;
		int nb_attacks;
		int *attacks;
	} monster_info_t;

	typedef struct fight_info {
		int nb_monsters;
		int *monsters;
	} fight_info_t;

	#define NB_NPC_ID 4
	#define NB_PARTICLE_ID 4
	#define NB_ATTACKS_ID 3
	#define NB_ENEMY_ID 3
	#define NB_FIGHTS_ID 2

	extern const npc_id_info_t NPC_IDS[NB_NPC_ID + 1];
	extern const sf_system_settings_t PARTICLE_IDS[NB_PARTICLE_ID];
	extern const attack_info_t ATTACKS_IDS[NB_ATTACKS_ID];
	extern const monster_info_t MONSTERS_IDS[NB_ENEMY_ID];
	extern const fight_info_t FIGHTS_ID[NB_FIGHTS_ID];

	fight_t *first_fight(sf_engine_t *engine, fight_player_t *player);
	fight_t *boss_fight(sf_engine_t *engine, fight_player_t *player);

	int king_end_game(sf_engine_t *engine, UNUSED gameobject_t *parent);
	int evil_king_fight(sf_engine_t *engine, UNUSED gameobject_t *parent);

#endif /* !__ASSETS__H_ */