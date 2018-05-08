/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Particle system core functions
*/

/* File created the 17/03/2018 at 11:34:29 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_graphics.h"

static int fill_settings(sf_particle_system_t *sys, \
const sf_system_settings_t *set)
{
	sys->settings = malloc(sizeof(*(sys->settings)));
	if (sys->settings == NULL)
		return (84);
	if ((sys->settings->texture_name = my_strdup(set->texture_name)) == 0) {
		free(sys->settings);
		return (84);
	}
	sys->settings->blend_mode = set->blend_mode;
	sys->settings->starting_rotation = set->starting_rotation;
	sys->settings->starting_speed = set->starting_speed;
	sys->settings->starting_life_time = set->starting_life_time;
	sys->settings->starting_size = set->starting_size;
	sys->settings->color_over_life_time[0] = set->color_over_life_time[0];
	sys->settings->color_over_life_time[1] = set->color_over_life_time[1];
	sys->settings->emission_type = set->emission_type;
	sys->settings->emission_rate = set->emission_rate;
	sys->settings->max_particle = set->max_particle;
	sys->settings->position = set->position;
	sys->settings->bounding_box = set->bounding_box;
	sys->settings->time_between_burst = set->time_between_burst;
	return (0);
}

static int setup_system(sf_particle_system_t *sys, const char *name)
{
	sys->texture = NULL;
	sys->sprite = NULL;
	sys->child_particles = NULL;
	sys->is_playing = false;
	sys->nb_alive = 0;
	sys->system_name = my_strdup(name);
	if (sys->system_name == NULL)
		return (84);
	sys->texture = sfTexture_createFromFile(sys->settings->texture_name, 0);
	sys->sprite = sfSprite_create();
	if (sys->texture == NULL || sys->sprite == NULL)
		return (84);
	sfSprite_setTexture(sys->sprite, sys->texture, sfTrue);
	sfSprite_setOrigin(sys->sprite, (sfVector2f){sfSprite_getGlobalBounds(\
sys->sprite).width / 2, sfSprite_getGlobalBounds(sys->sprite).height / 2});
	sys->add_particle = &particle_system_add_particle;
	sys->add_particles = &particle_system_add_particle_list;
	sys->render = &particle_system_render;
	sys->update = &particle_system_update;
	return (0);
}

sf_particle_system_t *create_particle_system(const \
sf_system_settings_t *settings, const char *name)
{
	sf_particle_system_t *sys = NULL;

	if (settings == NULL)
		return (NULL);
	sys = malloc(sizeof(*sys));
	if (sys == NULL)
		return (NULL);
	if (fill_settings(sys, settings)) {
		free(sys);
		return (NULL);
	}
	if (setup_system(sys, name)) {
		destroy_particle_system(sys);
		return (NULL);
	}
	return (sys);
}

static void destroy_child_particles(sf_particle_system_t *sys)
{
	sf_linked_list_t *last = NULL;
	sf_linked_list_t *curr = NULL;

	for (curr = sys->child_particles; curr;) {
		last = curr;
		curr = curr->next;
		destroy_particle((sf_particle_t *)last->data);
		sf_remove_node(last, &(sys->child_particles));
	}
}

void destroy_particle_system(sf_particle_system_t *sys)
{
	if (sys == NULL)
		return;
	if (sys->system_name != NULL)
		free(sys->system_name);
	if (sys->texture != NULL)
		sfTexture_destroy(sys->texture);
	if (sys->sprite != NULL)
		sfSprite_destroy(sys->sprite);
	if (sys->settings != NULL) {
		if (sys->settings->texture_name != NULL)
			free(sys->settings->texture_name);
		free(sys->settings);
	}
	destroy_child_particles(sys);
	free(sys);
}