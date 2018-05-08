/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Tile particles
*/

/* File created the 08/05/2018 at 15:03:23 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "prefabs.h"
#include "parser.h"
#include "rpg.h"

void set_tile_particles(UNUSED sf_collider_2d_t *col, sf_tile_effect_t *effect,\
tile_info_t *info)
{
	sf_engine_t *engine = effect->engine;
	sf_particle_system_t *sys = NULL;
	sfVector2i sys_pos = info->tile_pos;

	if (info->event->particles_id > 1)
		return;
	sys = create_particle_system(\
&(PARTICLE_IDS[info->event->particles_id - 1]), "particle");
	sys->is_playing = true;
	sys->settings->position.x = sys_pos.x * TILE_SIZE - TILE_SIZE / 2;
	sys->settings->position.y = sys_pos.y * TILE_SIZE - TILE_SIZE / 2;
	engine->add_particle_system(engine, sys);
}