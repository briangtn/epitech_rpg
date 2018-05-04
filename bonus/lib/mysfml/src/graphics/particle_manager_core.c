/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Manage all particle system in a scene
*/

/* File created the 17/03/2018 at 12:05:22 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_graphics.h"

sf_particle_manager_t *create_manager(void)
{
	sf_particle_manager_t *manager = malloc(sizeof(*manager));

	if (manager == NULL) {
		my_putdebug("[ERROR]Could not create manager!\n");
		return (NULL);
	}
	manager->child_systems = NULL;
	manager->destroy = &destroy_manager;
	manager->add_system = &particle_manager_add_system;
	manager->update = &particle_manager_update;
	manager->render = &particle_manager_render;
	return (manager);
}

void destroy_manager(sf_particle_manager_t *manager)
{
	sf_linked_list_t *tmp = NULL;
	sf_linked_list_t *curr = NULL;

	if (manager == NULL)
		return;
	for (curr = manager->child_systems; curr != NULL;) {
		destroy_particle_system((sf_particle_system_t *)curr->data);
		tmp = curr;
		curr = curr->next;
		sf_remove_node(tmp, &(manager->child_systems));
	}
	free(manager);
}