/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** Graphical interface continuation
*/

/* File created the 20/02/2018 at 12:08:45 by julian.frabel@epitech.eu */

#include "my_sfml_core.h"
#include "my_sfml_engine.h"
#include <SFML/Graphics.h>

int remove_from_layers_main_engine(sf_engine_t *engine, void **data)
{
	if (engine == NULL || data == NULL) {
		my_putdebug("Render main engine:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	if (engine->current_scene == NULL)
		return (84);
	return (engine->current_scene->graphical_engine->remove_from_layers(\
engine->current_scene->graphical_engine, data));
}

int add_particle_system_main_engine(sf_engine_t *engine, \
sf_particle_system_t *p_sys)
{
	if (engine == NULL || p_sys == NULL) {
		my_putdebug("Add particle system main engine:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return (84);
	}
	if (engine->current_scene == NULL)
		return (84);
	return (engine->current_scene->graphical_engine->particle_manager->\
add_system(engine->current_scene->graphical_engine->particle_manager, p_sys));
}