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
{1, SS_GUARD, FACE_SOLDIER, NULL, {0, 0, 32, 32}, {0, 0, 32, 32}},
{2, SS_SIGN, FACE_SIGN, NULL, {0, 0, 32, 32}, {0, 0, 32, 32}},
{3, SS_KING, FACE_KING, &king_end_game, {0, 0, 32, 32}, {0, 0, 32, 32}},
{4, SS_BOSS, FACE_EVILKING, &evil_king_fight, {0, 0, 64, 64}, {0, 0, 128, 64}},
{0, NULL, NULL, NULL, {0, 0, 0, 0}, {0, 0, 0, 0}}
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

int (*const FIGHTS_ID[NB_FIGHTS_ID])() = {
	&first_fight,
	&boss_fight
};