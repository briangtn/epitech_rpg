/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Update all particles systems
*/

/* File created the 17/03/2018 at 12:18:32 by julian.frabel@epitech.eu */

#include "my_sfml_graphics.h"

int particle_manager_update(sf_particle_manager_t *manager, int delta_time)
{
	sf_particle_system_t *sys = NULL;
	sf_linked_list_t *curr = NULL;

	if (manager == NULL)
		return (84);
	for (curr = manager->child_systems; curr != NULL; curr = curr->next) {
		sys = (sf_particle_system_t *)curr->data;
		sys->update(sys, delta_time / 1000.0);
	}
	return (0);
}