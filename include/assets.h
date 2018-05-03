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
	#define SPRITESHEET_PLAYER "assets/spritesheets/player.png"
	#define SPRITESHEET_GUARD "assets/spritesheets/guard.png"
	#define SPRITE_BORDER "assets/spritesheets/border.png"
	#define SPRITE_SPEAK_BORDER "assets/spritesheets/speak_border.png"
	#define SPRITE_SPEAK_BG "assets/spritesheets/speak_background.png"
	#pragma endregion

	#pragma region Tilesets
	#define TILESET_OUTSIDE_B "assets/tilesets/outside_b.png"
	#define TILESET_OUTSIDE_C "assets/tilesets/outside_c.png"
	#pragma endregion

	#pragma region Buttons
	#define BUTTON_GAME "assets/buttons/button_game.png"
	#define BUTTON_FIGHT "assets/buttons/button_fight.png"
	#define BUTTON_QUIT "assets/buttons/button_quit.png"
	#define BUTTON_RESUME "assets/buttons/button_resume.png"
	#pragma endregion

	#pragma region Face
	#define FACE_SOLDIER "assets/faces/guard.png"
	#pragma endregion

	#pragma region Font
	#define FONT_SPEAK "assets/crazy_krabs.otf"
	#pragma endregion

	typedef struct npc_id_info {
		int npc_id;
		char *npc_visual;
		char *npc_face;
	} npc_id_info_t;

	#define NB_NPC_ID 1

	extern const npc_id_info_t NPC_IDS[];

#endif /* !__ASSETS__H_ */