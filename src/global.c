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
	{1, SPRITESHEET_GUARD, FACE_SOLDIER},
	{2, SPRITESHEET_SIGN, FACE_SIGN},
	{3, SPRITESHEET_KING, FACE_KING},
	{0, NULL, NULL}
};

const items_t ITEM_LIST[ITEM_NULL + 1] = {
	{"Small potion", FACE_SIGN, .2f, true},
	{"Large potion", FACE_SIGN, .5f, true},
	{"Spell A", FACE_SIGN, .15f, false},
	{"Spell B", FACE_SIGN, .25f, false},
	{"Spell C", FACE_SIGN, .35f, false},
	{NULL, NULL, .0f, false}
};

const sf_system_settings_t PARTICLE_IDS[NB_PARTICLE_ID] = {
	{PARTICLE_DEFAULT, ADD, {45.0, 90.0}, {30, 60}, {.1, .1}, {1, 1}, \
{{255, 51, 51, 255}, {255, 51, 51, 0}}, OVERTIME, 20, 20, \
{0, 0, 0}, {0, 0, 0, 0}, {0, 0}},
	{PARTICLE_DEFAULT, ALPHA, {0, 360.0}, {20, 20}, {.01, .01}, {.8, .8}, \
{{42, 80, 88, 133}, {42, 80, 88, 0}}, BURST, 1000, 20, \
{200, 200, 0}, {0, 0, 0, 0}, {10, 20}},
};

int (*const FIGHTS_ID[NB_FIGHTS_ID])() = {
	&first_fight
};