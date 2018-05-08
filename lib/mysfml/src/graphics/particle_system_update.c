/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** update a particle system
*/

/* File created the 17/03/2018 at 14:27:15 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_graphics.h"

static int update_particle(sf_particle_t *particle, float delta_time)
{
	sf_system_settings_t *set = particle->parent->settings;

	if (particle == NULL)
		return (84);
	(particle->life_time) -= delta_time;
	if (particle->life_time <= 0)
		return (1);
	particle->color.a = my_lerp(set->color_over_life_time[1].a, \
set->color_over_life_time[0].a, particle->life_time / particle->s_life_time);
	particle->color.r = my_lerp(set->color_over_life_time[1].r, \
set->color_over_life_time[0].r, particle->life_time / particle->s_life_time);
	particle->color.g = my_lerp(set->color_over_life_time[1].g, \
set->color_over_life_time[0].g, particle->life_time / particle->s_life_time);
	particle->color.b = my_lerp(set->color_over_life_time[1].b, \
set->color_over_life_time[0].b, particle->life_time / particle->s_life_time);
	particle->old_pos = particle->position;
	(particle->position.x) += (particle->velocity.x * delta_time);
	(particle->position.y) += (particle->velocity.y * delta_time);
	(particle->position.z) += (particle->velocity.z * delta_time);
	return (0);
}

static int spawn_overtime(sf_particle_system_t *sys, float dt)
{
	static float amount = 0;
	sf_linked_list_t *particle_list = NULL;
	int max_particle = sys->settings->max_particle;
	float life = (sys->settings->starting_life_time.x + \
sys->settings->starting_life_time.y) / 2.0;
	int particle_per_seconds = max_particle / life;

	amount += (particle_per_seconds * dt);
	if (amount < 1.0)
		return (0);
	particle_list = create_particles(sys, (int)amount);
	amount -= ((int)amount);
	return (sys->add_particles(sys, particle_list));
}

static int spawn_required_particles(sf_particle_system_t *sys, float dt)
{
	sf_linked_list_t *particle_list = NULL;
	int rate = sys->settings->emission_rate;

	if (!sys->is_playing)
		return (0);
	switch (sys->settings->emission_type) {
	case BURST: return (spawn_burst(sys, dt));
	case OVERTIME: return (spawn_overtime(sys, dt));
	case SINGLE: particle_list = create_particles(sys, rate);
		sys->is_playing = false;
		return (sys->add_particles(sys, particle_list));
	default: return (84);
	}
}

static void remove_particle(sf_linked_list_t *last, \
sf_linked_list_t *to_remove, sf_linked_list_t **start)
{
	sf_linked_list_t *next = to_remove->next;

	destroy_particle((sf_particle_t *)to_remove->data);
	if (last) {
		last->next = next;
		free(to_remove->id);
		free(to_remove);
	} else {
		*start = next;
		free(to_remove->id);
		free(to_remove);
	}
}

int particle_system_update(sf_particle_system_t *sys, float delta_time)
{
	sf_linked_list_t *last = NULL;
	sf_linked_list_t *tmp = NULL;
	sf_linked_list_t *curr = NULL;

	if (sys == NULL)
		return (84);
	spawn_required_particles(sys, delta_time);
	for (curr = sys->child_particles; curr != NULL;) {
		if (update_particle((sf_particle_t *)curr->data, delta_time)) {
			(sys->nb_alive) -= 1;
			tmp = curr;
			curr = curr->next;
			remove_particle(last, tmp, &(sys->child_particles));
		} else {
			last = curr;
			curr = curr->next;
		}
	}
	return (0);
}