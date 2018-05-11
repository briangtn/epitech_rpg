/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Globals
*/

/* File created the 03/05/2018 at 15:15:13 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml.h"
#include "assets.h"
#include "prefabs.h"

const npc_id_info_t NPC_IDS[NB_NPC_ID + 1] = {
{1, SS_GUARD, FACE_SOLDIER, NULL, {0, 0, 32, 32}, {0, 0, 32, 32}},
{2, SS_SIGN, FACE_SIGN, NULL, {0, 0, 32, 32}, {0, 0, 32, 32}},
{3, SS_KING, FACE_KING, &king_end_game, {0, 0, 32, 32}, {0, 0, 32, 32}},
{4, SS_BOSS, FACE_EVILKING, &evil_king_fight, {0, 0, 64, 64}, {0, 0, 128, 64}},
{0, NULL, NULL, NULL, {0, 0, 0, 0}, {0, 0, 0, 0}}
};

const items_t ITEM_LIST[ITEM_NULL + 1] = {
	{"Small potion", ITEMTEX_POTION_S, .2f, true},
	{"Large potion", ITEMTEX_POTION_L, .5f, true},
	{"Spell A", ITEMTEX_SPELL_A, .15f, false},
	{"Spell B", ITEMTEX_SPELL_B, .25f, false},
	{"Spell C", ITEMTEX_SPELL_C, .35f, false},
	{"Sword", ITEMTEX_SWORD, 0.0f, false},
	{NULL, NULL, .0f, false}
};

const sf_system_settings_t PARTICLE_IDS[NB_PARTICLE_ID] = {
	{PARTICLE_DEFAULT, ADD, {45.0, 90.0}, {30, 60}, {.1, .1}, {1, 1}, \
{{255, 51, 51, 255}, {255, 51, 51, 0}}, OVERTIME, 20, 20, \
{0, 0, 0}, {0, 0, 0, 0}, {0, 0}},
	{PARTICLE_DEFAULT, ALPHA, {0, 360.0}, {20, 20}, {.01, .01}, {.8, .8}, \
{{42, 80, 88, 133}, {42, 80, 88, 0}}, BURST, 1000, 20, \
{200, 200, 0}, {0, 0, 0, 0}, {3, 6}},
	{PARTICLE_DEFAULT, ALPHA, {45.0, 90.0}, {30, 60}, {.1, .1}, {1, 1}, \
{{50, 50, 50, 255}, {50, 50, 50, 0}}, OVERTIME, 20, 20, \
{0, 0, 0}, {-10, -10, 20, 0}, {0, 0}},
	{PARTICLE_DEFAULT, ADD, {30.0, 80.0}, {30, 60}, {.3, .3}, {1.5, 2.5}, \
{{255, 51, 51, 255}, {255, 51, 51, 0}}, OVERTIME, 20, 40, \
{0, 0, 0}, {0, 0, 0, 0}, {0, 0}},
};

/* {Attack name, Damages, Energy cost} */
const attack_info_t ATTACKS_IDS[NB_ATTACKS_ID] = {
	{"Sword attack", 1, 1},
	{"Spear attack", 2, 1},
	{"Heavy sword attack", 5, 2},
};

/* {Life, Sprite path, Name, Nb attacks, {attacks}} */
const monster_info_t MONSTERS_IDS[NB_ENEMY_ID] = {
	{5, ENEMY_ROGUE, "Rogue", 1, (int [1]){0}},
	{10, ENEMY_FANATIC, "Fanatic", 1, (int [1]){1}},
	{20, ENEMY_BOSS, "Evil King", 2, (int [2]){0, 2}},
};

/* {Nb monsters, {monster id}} */
const fight_info_t FIGHTS_ID[NB_FIGHTS_ID] = {
	{2, (int [2]){0, 0}, BACKGROUND_FIGHT_PATH},
	{1, (int [1]){2}, BACKGROUND_CASTLE_FIGHT}
};