/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** Spawn a particle burst
*/

/* File created the 08/05/2018 at 16:08:26 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_graphics.h"

int spawn_burst(sf_particle_system_t *sys, float dt)
{
	static float elapsed = 0;
	sf_linked_list_t *particle_list = NULL;
	int rate = sys->settings->emission_rate;

	elapsed += dt;
	if (elapsed >= sys->settings->time_between_burst) {
		elapsed -= sys->settings->time_between_burst;
		particle_list = create_particles(sys, rate);
		return (sys->add_particles(sys, particle_list));
	}
	return (0);
}