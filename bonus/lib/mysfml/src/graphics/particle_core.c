/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Core of a particle
*/

/* File created the 17/03/2018 at 10:42:28 by julian.frabel@epitech.eu */

#include <math.h>
#include <stdlib.h>
#include "my_sfml_graphics.h"

static sf_vector_3d_t get_velocity(sf_system_settings_t *param, float rotation)
{
	sf_vector_3d_t velocity = {0, 0, 0};
	float speed = get_randomf_vector_2d(param->starting_speed);

	velocity.x = speed * cos(rotation);
	velocity.y = -speed * sin(rotation);
	return (velocity);
}

sf_particle_t *create_particle(sf_particle_system_t *parent)
{
	sf_particle_t *particle = NULL;
	sf_system_settings_t *param = NULL;

	if (parent == NULL)
		return (NULL);
	param = parent->settings;
	particle = malloc(sizeof(*particle));
	if (particle == NULL)
		return (NULL);
	particle->parent = parent;
	particle->life_time = get_randomf_vector_2d(param->starting_life_time);
	particle->s_life_time = particle->life_time;
	particle->size = get_randomf_vector_2d(param->starting_size);
	particle->position = param->position;
	particle->old_pos = param->position;
	particle->rotation = get_randomf_vector_2d(param->starting_rotation);
	particle->rotation = particle->rotation * M_PI / 180.0;
	particle->velocity = get_velocity(param, particle->rotation);
	particle->color = param->color_over_life_time[0];
	return (particle);
}

sf_linked_list_t *create_particles(sf_particle_system_t *parent, int amount)
{
	sf_linked_list_t *list = NULL;
	sf_particle_t *particle = NULL;

	if (parent == NULL || amount <= 0) {
		my_putdebug("[ERROR](create_particles)Invalid arguments!\n");
		return (NULL);
	}
	for (int i = 0; i < amount; i++) {
		particle = create_particle(parent);
		if (particle == NULL) {
			my_putdebug("[INFO]Failed to get 1 particle!\n");
			continue;
		}
		list = sf_push(particle, my_int_to_str((long)particle), list);
	}
	return (list);
}

void destroy_particle(sf_particle_t *particle)
{
	if (particle == NULL)
		return;
	free(particle);
}