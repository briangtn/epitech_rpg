/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Add particles to particle system
*/

/* File created the 17/03/2018 at 13:40:38 by julian.frabel@epitech.eu */

#include "my_sfml_graphics.h"

int particle_system_add_particle(sf_particle_system_t *sys, sf_particle_t *part)
{
	if (sys == NULL || part == NULL)
		return (84);
	sys->child_particles = sf_push(part, \
my_int_to_str((long)part), sys->child_particles);
	(sys->nb_alive) += 1;
	return (0);
}

int particle_system_add_particle_list(sf_particle_system_t *sys, \
sf_linked_list_t *particles)
{
	sf_linked_list_t *curr = NULL;

	if (sys == NULL || particles == NULL)
		return (84);
	if (sys->child_particles == NULL) {
		sys->child_particles = particles;
		return (0);
	}
	for (curr = sys->child_particles; curr->next; curr = curr->next);
	curr->next = particles;
	(sys->nb_alive) += my_sf_list_size(particles);
	return (0);
}