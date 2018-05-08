/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** Assets defines
*/

/* File created the 04/04/2018 at 14:40:54 by julian.frabel@epitech.eu */

#ifndef __ASSETS__H_
	#define __ASSETS__H_

	#pragma region Spritesheets
	#define SPRITESHEET_SIGN "assets/spritesheets/sign.png"
	#define SPRITESHEET_PLAYER "assets/spritesheets/player.png"
	#define SPRITESHEET_GUARD "assets/spritesheets/guard.png"
	#define SPRITESHEET_KING "assets/spritesheets/king.png"
	#define SPRITE_BORDER "assets/spritesheets/border.png"
	#define SPRITE_SPEAK_BORDER "assets/spritesheets/speak_border.png"
	#define SPRITE_SPEAK_BG "assets/spritesheets/speak_background.png"
	#pragma endregion

	#define BACKGROUND_WORLDMAP "assets/backgrounds/worldmap.png"
	#define BACKGROUND_FIGHT_PATH "assets/backgrounds/fight_path.png"
	#define BACKGROUND_END "assets/backgrounds/end.png"

	#pragma region Particles
	#define PARTICLE_DEFAULT "assets/particles/particle_default.png"
	#pragma endregion

	#pragma region Enemys
	#define ENEMY_ROGUE "assets/enemys/rogue.png"
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
	#pragma endregion

	#pragma region Font
	#define FONT_SPEAK "assets/crazy_krabs.otf"
	#pragma endregion

	typedef struct npc_id_info {
		int npc_id;
		char *npc_visual;
		char *npc_face;
	} npc_id_info_t;

	#define NB_NPC_ID 3
	#define NB_PARTICLE_ID 2
	#define NB_FIGHTS_ID 1

	extern const npc_id_info_t NPC_IDS[NB_NPC_ID + 1];
	extern const sf_system_settings_t PARTICLE_IDS[NB_PARTICLE_ID];
	extern int (*const FIGHTS_ID[NB_FIGHTS_ID])();

	int first_fight(sf_engine_t *engine);

#endif /* !__ASSETS__H_ */