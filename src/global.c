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

const npc_id_info_t NPC_IDS[NB_NPC_ID + 1] = {
	{1, SPRITESHEET_GUARD, FACE_SOLDIER},
	{2, SPRITESHEET_SIGN, FACE_SIGN},
	{0, NULL, NULL}
};

const sf_system_settings_t PARTICLE_IDS[NB_PARTICLE_ID] = {
	{PARTICLE_DEFAULT, ADD, {45.0, 90.0}, {30, 60}, {.1, .1}, {1, 1}, \
{{255, 51, 51, 255}, {255, 51, 51, 0}}, OVERTIME, 20, 20, \
{0, 0, 0}, {0, 0, 0, 0}, {0, 0}},
	{PARTICLE_DEFAULT, ALPHA, {0, 360.0}, {20, 20}, {.01, .01}, {.8, .8}, \
{{42, 80, 88, 133}, {42, 80, 88, 0}}, BURST, 1000, 20, \
{200, 200, 0}, {0, 0, 0, 0}, {10, 30}},
};