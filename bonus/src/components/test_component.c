/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** editor
*/

#include "my.h"
#include "my_sfml.h"
#include "config.h"

int update_grid_comp(sf_grid_t *component, UNUSED int delta_time)
{
	sf_animation_2d_t *animation = get_component(component->parent, ANIMATION_2D);
	
	if (animation == NULL)
		return (84);
	sfSprite_setColor(animation->sprite, component->color);
	return (0);
}

static void free_grid_tile(sf_grid_t *component)
{
	for (int i = 0; component->grid[i] != NULL; i++)
		for (int j = 0; component->grid[i][j] != NULL)
			component->grid[i][j]->engine->destroy_gameobject(component->grid[i][j]);
}

static void free_grid_comp(sf_grid_t *component)
{
	if (component != NULL) {
		if (component->grid != NULL)
			free_grid_tile(component);
		free(component);
	}
}

sf_grid_t *create_grid_comp(gameobject_t *gameobject)
{
	sf_grid_t *component = malloc(sizeof(sf_grid_t));

	if (component == NULL)
		return (NULL);
	component->destroy = &free_grid_comp;
	component->parent = gameobject;
	component->grid = create_grid_tile();
	if (component->grid == NULL) {
		component->destroy(component);
		return (NULL);
	}
	return (component);
}