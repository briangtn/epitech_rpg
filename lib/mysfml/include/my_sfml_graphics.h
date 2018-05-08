/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Functions related to graphics
*/

/**
** \file my_sfml_graphics.h
** \brief Header for a graphic engine
*/

#ifndef __MY_SFML_GRAPHICS_H_
#define __MY_SFML_GRAPHICS_H_

#include "my_sfml_core.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

/* --------------------------------DEFINE-------------------------------- */
/* ------------------------------END-DEFINE------------------------------ */

/* ----------------------------GRAPHIC-ENGINE---------------------------- */

struct my_sfml_graphical_engine {
	sf_linked_list_t *layers_list;
	sf_linked_list_t *textures_list;
	struct my_sfml_particle_manager *particle_manager;
	void (*destroy)();
	int (*render)();
	int (*add_to_layer)();
	int (*remove_from_layers)();
	int (*load_texture)();
	int (*set_type)();
	sfTexture *(*get_texture)();
};

typedef struct my_sfml_graphical_engine sf_graph_engine_t;

sf_graph_engine_t *create_graphical_engine(void);
void destroy_graphical_engine(sf_graph_engine_t *graph_engine);
void unload_all_textures(sf_graph_engine_t *engine);

int load_texture_in_memory(sf_graph_engine_t *engine, char const *path);
sfTexture *get_texture_from_engine(sf_graph_engine_t *engine, char const *id);

int render_frame(sf_graph_engine_t *graph_engine, sfRenderWindow *window);
int add_to_layer(sf_graph_engine_t *engine, int layer, void **sprite);
int remove_from_layers(sf_graph_engine_t *engine, void **object);

/* ------------------------------END-ENGINE------------------------------ */

/* --------------------------------LAYERS-------------------------------- */

enum layer_enum {
	BACKGROUND = -1,
	GAME = 0,
	FOREGROUND = 1,
	UI_IMAGE = 2147483646,
	UI_TEXT = 2147483647
};

enum layer_render_type {
	RTYPE_SPRITE,
	RTYPE_TEXT
};

typedef enum layer_enum layer_enum_t;
typedef enum layer_render_type layer_render_type_t;

struct my_sfml_layer {
	int priority;
	layer_render_type_t type;
	sf_linked_list_t *sprite_list;
};

typedef struct my_sfml_layer sf_layer_t;

sf_layer_t *create_layer(int priority);
void destroy_layer(sf_layer_t *layer);
void sort_layers(sf_linked_list_t **layer_list);
void render_layer(sf_layer_t *layer, sfRenderWindow *window);
int compare_layer(void *layer_one, void *layer_two);
int layer_equals(sf_layer_t *layer, int *layer_nb);

int set_layer_render_type(sf_graph_engine_t *engine, int priority, \
layer_render_type_t new_type);

/* ------------------------------END-LAYERS------------------------------ */

/* ------------------------------PARTICULES------------------------------ */

typedef sfColor sf_color_t;
typedef struct my_sfml_particle_manager sf_particle_manager_t;
typedef struct my_sfml_system_settings sf_system_settings_t;
typedef struct my_sfml_particle_system sf_particle_system_t;
typedef struct my_sfml_particle sf_particle_t;

typedef enum blend_mode {
	NONE,
	MULTIPLY,
	ADD,
	ALPHA
} blend_mode_t;

typedef enum emission_type {
	BURST,
	OVERTIME,
	SINGLE
} emission_type_t;

struct my_sfml_particle_manager {
	sf_linked_list_t *child_systems;
	void (*destroy)(sf_particle_manager_t *manager);
	int (*add_system)(sf_particle_manager_t *manager, \
sf_particle_system_t *system);
	int (*update)(sf_particle_manager_t *manager, int delta_time);
	int (*render)(sfRenderWindow *window, sf_particle_manager_t *manager);
};

struct my_sfml_system_settings {
	char *texture_name;
	blend_mode_t blend_mode;
	sf_vector_2d_t starting_rotation;
	sf_vector_2d_t starting_speed;
	sf_vector_2d_t starting_size;
	sf_vector_2d_t starting_life_time;
	sf_color_t color_over_life_time[2];
	emission_type_t emission_type;
	int emission_rate;
	int max_particle;
	sf_vector_3d_t position;
	sfIntRect bounding_box;
	sf_vector_2d_t time_between_burst;
};

struct my_sfml_particle_system {
	char *system_name;
	sf_linked_list_t *child_particles;
	int nb_alive;
	sfTexture *texture;
	sfSprite *sprite;
	bool is_playing;
	sf_system_settings_t *settings;
	int (*add_particle)(sf_particle_system_t *sys, sf_particle_t *particle);
	int (*add_particles)(sf_particle_system_t *sys, sf_linked_list_t *list);
	int (*render)(sfRenderWindow *window, sf_particle_system_t *sys);
	int (*update)(sf_particle_system_t *sys, float delta_time);
};

struct my_sfml_particle {
	sf_particle_system_t *parent;
	float life_time;
	float s_life_time;
	float size;
	sf_vector_3d_t position;
	sf_vector_3d_t old_pos;
	sf_vector_3d_t velocity;
	float rotation;
	sf_color_t color;
};

/* FUNCTIONS */

/* manager */
sf_particle_manager_t *create_manager(void);

void destroy_manager(sf_particle_manager_t *manager);

int particle_manager_update(sf_particle_manager_t *manager, int delta_time);
int particle_manager_render(sfRenderWindow *window, \
sf_particle_manager_t *manager);
int particle_manager_add_system(sf_particle_manager_t *manager, \
sf_particle_system_t *sys);

/* systems */
sf_particle_system_t *create_particle_system(const \
sf_system_settings_t *settings, const char *name);

void destroy_particle_system(sf_particle_system_t *sys);

int particle_system_add_particle(sf_particle_system_t *sys, \
sf_particle_t *particle);
int particle_system_add_particle_list(sf_particle_system_t *sys, \
sf_linked_list_t *particles);

int particle_system_update(sf_particle_system_t *sys, float delta_time);
int particle_system_render(sfRenderWindow *window, sf_particle_system_t *sys);

int spawn_burst(sf_particle_system_t *sys, float dt);

/* particles */
sf_particle_t *create_particle(sf_particle_system_t *parent);
sf_linked_list_t *create_particles(sf_particle_system_t *parent, int amount);

void destroy_particle(sf_particle_t *particle);

/* ----------------------------END-PARTICULES---------------------------- */

#endif /* __MY_SFML_GRAPHICS_H_ */