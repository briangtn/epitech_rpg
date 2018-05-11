/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Scenes
*/

/**
** \file my_sfml_scenes.h
** \brief Header for the scenes
*/

#ifndef __MY_SFML_SCENES_H_
#define __MY_SFML_SCENES_H_

#include "my_sfml_audio.h"
#include "my_sfml_graphics.h"
#include "my_sfml_gameobject.h"
#include "my_sfml_physics.h"
#include <SFML/Graphics.h>

/* --------------------------------DEFINE-------------------------------- */

#define UPDATER int (*)(void *, int)

/* ------------------------------END-DEFINE------------------------------ */

/* Typedefs */
typedef struct updater updater_t;
typedef struct sf_camera_s sf_camera_t;
typedef struct scene sf_scene_t;

/* --------------------------------UPDATE-------------------------------- */

struct updater {
	void *object;
	int (*update)(void *object, int time_milliseconds);
};

/* ------------------------------END-UPDATE------------------------------ */

/* --------------------------------CAMERAS------------------------------- */

struct sf_camera_s {
	void *target;
	bool follow_target;
	sfVector2f position;
	sfVector2f view_size;
	sfIntRect scene_size;
	sfView *camera_view;
	sfRenderWindow *window;
	void (*destroy)(struct sf_camera_s *camera);
	void (*update)(struct sf_camera_s *camera, int delta_time);
};

sf_camera_t *create_new_camera(sfRenderWindow *window);
void destroy_camera(sf_camera_t *camera);
void display_camera_debug(sf_camera_t *camera);

/* ------------------------------END-CAMERAS----------------------------- */

/* --------------------------------SCENES-------------------------------- */

struct scene {
	char *name;
	int (*load)();
	int (*loop)();
	int (*unload)();
	sf_camera_t *camera;
	sf_graph_engine_t *graphical_engine;
	sf_audio_engine_t *audio_engine;
	sf_physics_engine_t *physic_engine;
	sf_linked_list_t *updaters;
	sf_linked_list_t *gameobjects;
};

sf_scene_t *create_scene(char *name);
void destroy_scene(sf_scene_t *scene);
int reset_scene(sf_scene_t *scene);

/* ------------------------------END-SCENES------------------------------ */

#endif /* __MY_SFML_SCENES_H_ */