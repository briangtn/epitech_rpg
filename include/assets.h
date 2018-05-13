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

	#pragma region Sounds
	#define MUSIC_MENU "assets/sounds/menu.ogg"
	#define MUSIC_FIGHT "assets/sounds/fight.ogg"
	#define MUSIC_INTRO "assets/sounds/intro.ogg"
	#define MUSIC_GAME "assets/sounds/game.ogg"
	#pragma endregion

	#pragma region Spritesheets
	#define SS_SIGN "assets/spritesheets/sign.png"
	#define SPRITESHEET_PLAYER "assets/spritesheets/player.png"
	#define SS_GUARD "assets/spritesheets/guard.png"
	#define SS_KING "assets/spritesheets/king.png"
	#define SS_BOSS "assets/spritesheets/evilking.png"
	#define SPRITE_BORDER "assets/spritesheets/border.png"
	#define SPRITE_SPEAK_BORDER "assets/spritesheets/speak_border.png"
	#define SPRITE_SPEAK_BG "assets/spritesheets/speak_background.png"
	#define SPRITE_FIGHTBOX "assets/spritesheets/attack_menu.png"
	#pragma endregion

	#pragma region Background
	#define BACKGROUND_WORLDMAP "assets/backgrounds/worldmap.png"
	#define BACKGROUND_FIGHT_PATH "assets/backgrounds/fight_path.png"
	#define BACKGROUND_CASTLE_FIGHT "assets/backgrounds/castle_fight.png"
	#define BACKGROUND_FIGHT_CAPITAL "assets/backgrounds/fight_capital.png"
	#define BACKGROUND_END "assets/backgrounds/end.png"
	#define BACKGROUND_INTRO "assets/backgrounds/intro.png"
	#define BACKGROUND_HELP "assets/backgrounds/how_to_play.png"
	#pragma endregion

	#pragma region Particles
	#define PARTICLE_DEFAULT "assets/particles/particle_default.png"
	#pragma endregion

	#pragma region Enemys
	#define ENEMY_SLIME "assets/enemys/slime.png"
	#define ENEMY_ROGUE "assets/enemys/rogue.png"
	#define ENEMY_BOSS "assets/enemys/evilking.png"
	#define ENEMY_FANATIC "assets/enemys/fanatic.png"
	#define ENEMY_PLAYER "assets/enemys/player.png"
	#pragma endregion

	#pragma region Buttons
	#define BUTTON_GAME "assets/buttons/button_game.png"
	#define BUTTON_HELP "assets/buttons/button_help.png"
	#define BUTTON_QUIT "assets/buttons/button_quit.png"
	#define BUTTON_RESUME "assets/buttons/button_resume.png"
	#define BUTTON_MENU "assets/buttons/button_menu.png"
	#define PANEL_INVENTORY "assets/buttons/inventory.png"
	#define ITEMTEX_POTION_S "assets/items/potion_small.png"
	#define ITEMTEX_POTION_L "assets/items/potion_large.png"
	#define ITEMTEX_SPELL_A "assets/items/spell_a.png"
	#define ITEMTEX_SPELL_B "assets/items/spell_b.png"
	#define ITEMTEX_SPELL_C "assets/items/spell_c.png"
	#define ITEMTEX_SWORD "assets/items/sword.png"
	#define ITEMTEX_POTION_STR "assets/items/potion_str.png"
	#define ITEMTEX_POTION_DEX "assets/items/potion_dex.png"
	#define ITEMTEX_POTION_EXP "assets/items/potion_exp.png"
	#pragma endregion

	#pragma region Face
	#define FACE_SIGN "assets/faces/sign.png"
	#define FACE_SOLDIER "assets/faces/guard.png"
	#define FACE_KING "assets/faces/king.png"
	#define FACE_EVILKING "assets/faces/evilking.png"
	#define FACE_HERO "assets/faces/player.png"
	#pragma endregion

	#pragma region Font
	#define FONT_SPEAK "assets/fonts/proggyclean.ttf"
	#define FONT_FIGHT FONT_SPEAK
	#pragma endregion

	#define LEVEL_UP_MESSAGE "Yay! I feel stronger\n(level up)"
	#define DEATH_MESSAGE "Fortunately I managed to escape!"
	#define DISCARD_MESSAGE "I should help the guard at my door!"
	#define POTION_DIALOG "I found some potions!\nI can use them by \
clicking on it!\n(+1 potion of dexterity)\n(+1 potion of strenght)\n\
(+1 potion of experience)"

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
		float damage;
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
		char *background;
	} fight_info_t;

	#define NB_NPC_ID 6
	#define NB_PARTICLE_ID 4
	#define NB_ATTACKS_ID 5
	#define NB_ENEMY_ID 4
	#define NB_FIGHTS_ID 7

	extern const npc_id_info_t NPC_IDS[NB_NPC_ID + 1];
	extern const sf_system_settings_t PARTICLE_IDS[NB_PARTICLE_ID];
	extern const attack_info_t ATTACKS_IDS[NB_ATTACKS_ID];
	extern const monster_info_t MONSTERS_IDS[NB_ENEMY_ID];
	extern const fight_info_t FIGHTS_ID[NB_FIGHTS_ID];

	fight_t *first_fight(sf_engine_t *engine, fight_player_t *player);
	fight_t *boss_fight(sf_engine_t *engine, fight_player_t *player);

	int give_sword(sf_engine_t *engine, UNUSED gameobject_t *parent);
	int king_end_game(sf_engine_t *engine, UNUSED gameobject_t *parent);
	int evil_king_fight(sf_engine_t *engine, UNUSED gameobject_t *parent);
	int give_potions(sf_engine_t *engine, gameobject_t *parent);

	int end_callback_fight(fight_t *fight, void *datas,\
bool win, sf_engine_t *engine);

#endif /* !__ASSETS__H_ */
