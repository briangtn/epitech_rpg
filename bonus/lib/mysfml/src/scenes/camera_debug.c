/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Camera debug
*/

/* File created the 05/04/2018 at 13:52:23 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "my_sfml_scenes.h"

static void display_scene_bounds(sf_camera_t *camera, sfRectangleShape *shape)
{
	sfVector2f pos = (sfVector2f){camera->scene_size.left + 1, \
camera->scene_size.top + 1};
	sfVector2f size = (sfVector2f){camera->scene_size.width, \
camera->scene_size.height};

	sfRectangleShape_setOutlineColor(shape, sfBlue);
	sfRectangleShape_setPosition(shape, pos);
	sfRectangleShape_setSize(shape, size);
	sfRenderWindow_drawRectangleShape(camera->window, shape, NULL);
}

static void display_camera_bounds(sf_camera_t *camera, sfRectangleShape *shape)
{
	int min_x = camera->scene_size.left + camera->view_size.x / 2 + 1;
	int max_x = min_x + camera->scene_size.width - camera->view_size.x;
	int min_y = camera->scene_size.top + camera->view_size.y / 2 + 1;
	int max_y = min_y + camera->scene_size.height - camera->view_size.y;
	sfVector2f pos = (sfVector2f){min_x, min_y};
	sfVector2f size = (sfVector2f){max_x - min_x, max_y - min_y};

	sfRectangleShape_setOutlineColor(shape, sfWhite);
	sfRectangleShape_setPosition(shape, pos);
	sfRectangleShape_setSize(shape, size);
	sfRenderWindow_drawRectangleShape(camera->window, shape, NULL);
}

static void display_camera_center(sf_camera_t *camera, sfRectangleShape *shape)
{
	sfVector2f center = camera->position;

	sfRectangleShape_setOutlineColor(shape, sfYellow);
	center.x += 1;
	center.y += 1;
	sfRectangleShape_setPosition(shape, center);
	sfRectangleShape_setSize(shape, (sfVector2f){2, 2});
	sfRenderWindow_drawRectangleShape(camera->window, shape, NULL);
}

void display_camera_debug(sf_camera_t *camera)
{
	sfRectangleShape *shape = NULL;

	if (camera == NULL || camera->window == NULL || !DISPLAY_CAMERA_DEBUG)
		return;
	shape = sfRectangleShape_create();
	if (shape == NULL)
		return;
	sfRectangleShape_setOutlineColor(shape, sfWhite);
	sfRectangleShape_setFillColor(shape, (sfColor){0, 0, 0, 0});
	sfRectangleShape_setOutlineThickness(shape, 1);
	display_scene_bounds(camera, shape);
	display_camera_bounds(camera, shape);
	display_camera_center(camera, shape);
	sfRectangleShape_destroy(shape);
}