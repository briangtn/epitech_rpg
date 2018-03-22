/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Add a particle system to the manager
*/

/* File created the 17/03/2018 at 12:15:06 by julian.frabel@epitech.eu */

#include "my_sfml_graphics.h"

int particle_manager_add_system(sf_particle_manager_t *manager, \
sf_particle_system_t *sys)
{
	if (manager == NULL || sys == NULL)
		return (84);
	manager->child_systems = sf_push(sys, my_int_to_str((long)sys), \
manager->child_systems);
	return (0);
}