/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Camera core functions
*/

/* File created the 05/04/2018 at 11:04:16 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_scenes.h"

static int my_clamp(float *value, int min, int max)
{
	int tmp = 0;

	if (min > max) {
		tmp = min;
		min = max;
		max = tmp;
	}
	if (*value < min) {
		*value = min;
		return (min);
	} else if (*value > max) {
		*value = max;
		return (max);
	}
	return (*value);
}

static void update_camera(sf_camera_t *camera, UNUSED int delta_time)
{
	sf_transform_t *tr = NULL;
	int min_x = 0;
	int max_x = 0;
	int min_y = 0;
	int max_y = 0;

	if (!camera || !camera->window || !camera->camera_view)
		return;
	tr = get_component((gameobject_t *)camera->target, TRANSFORM);
	if (camera->follow_target && tr != NULL) {
		camera->position = (sfVector2f){tr->position.x, tr->position.y};
		min_x = camera->scene_size.left + camera->view_size.x / 2;
		max_x = min_x + camera->scene_size.width - camera->view_size.x;
		min_y = camera->scene_size.top + camera->view_size.y / 2;
		max_y = min_y + camera->scene_size.height - camera->view_size.y;
		my_clamp(&(camera->position.x), min_x, max_x);
		my_clamp(&(camera->position.y), min_y, max_y);
	}
	sfView_setCenter(camera->camera_view, camera->position);
	sfView_setSize(camera->camera_view, camera->view_size);
	sfRenderWindow_setView(camera->window, camera->camera_view);
}

sf_camera_t *create_new_camera(sfRenderWindow *window)
{
	sf_camera_t *new_camera = malloc(sizeof(*new_camera));
	sfVector2u w_size = sfRenderWindow_getSize(window);

	if (new_camera == NULL) {
		my_putdebug("[ERROR]Camera create malloc failed!\n");
		return (NULL);
	}
	new_camera->camera_view = sfView_create();
	new_camera->window = window;
	new_camera->target = NULL;
	new_camera->follow_target = false;
	new_camera->position = (sfVector2f){w_size.x / 2, w_size.y / 2};
	new_camera->view_size = (sfVector2f){w_size.x, w_size.y};
	new_camera->scene_size = (sfIntRect){0, 0, w_size.x, w_size.y};
	new_camera->destroy = &destroy_camera;
	new_camera->update = &update_camera;
	sfView_setCenter(new_camera->camera_view, new_camera->position);
	sfView_setSize(new_camera->camera_view, new_camera->view_size);
	return (new_camera);
}

void destroy_camera(sf_camera_t *camera)
{
	if (camera == NULL)
		return;
	if (camera->camera_view != NULL)
		sfView_destroy(camera->camera_view);
	free(camera);
}