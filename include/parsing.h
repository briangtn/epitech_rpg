/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** header for parsing functions
*/

#ifndef __PARSING_H_
#define __PARSING_H_

#include <SFML/Graphics.h>

enum tile_interactions {
	STANDARD,
	COLLIDE,
	HIDE
};

typedef struct tile_info tile_info_t;

struct tile_info {
	int tile_id;
	sfVector2i tile_pos;
	int event_id;
	int tile_type;
};

typedef struct scene_info scene_info_t;

struct scene_info {
	int nb_tile;
	tile_info_t **tile;
};

typedef struct game_info game_info_t;

struct gameinfo {
	int nb_scene;
	scene_info_t **scene;
};

game_info_t *parse_config(void);

#endif