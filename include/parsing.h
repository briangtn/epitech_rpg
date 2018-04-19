/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** header for parsing functions
*/

#ifndef __PARSING_H_
#define __PARSING_H_

#include <SFML/Graphics.h>

enum errors {
	WRONG_LAYER = -9,
	WRONG_TYPE = -8,
	WRONG_EVENT = -7,
	WRONG_POS = -6,
	WRONG_ID = -5,
	TOO_FEW_TILES = -4,
	TOO_FEW_SCENES = -3,
	UNKNOWN_PARAM = -2,
	EMPTY_FILE = -1
};

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
	int layer;
};

typedef struct scene_info scene_info_t;

struct scene_info {
	char *tileset;
	char *background;
	tile_info_t **tile;
};

typedef struct game_info game_info_t;

struct game_info {
	int nb_scene;
	sfVector2i tile_per_scene;
	scene_info_t **scene;
};

extern char *error_messages [];

#define NB_SCENE	"NB_SCENE : \"*\""
#define TILE_PER_SCENE	"TILE_PER_SCENE (COL * LINES) : \"*\" x \"*\""
#define SCENE		"SCENE *:"
#define TILESET		"TILESET : \"*\""
#define BACKGROUND	"BACKGROUND : \"*\""
#define TILE_INFO	"TILE_ID : \"*\" ; TILE_POS : \"*\" x \"*\" ; EVENT_ID : \"*\" ; TILE_TYPE : \"*\" ; LAYER : \"*\""

/*parsing.c*/

game_info_t *parse_config(void);
game_info_t *parse_game_info(game_info_t *game_info, int fd);
game_info_t *parse_scene_info(game_info_t *game_info, int fd);
scene_info_t *parse_tile_info(scene_info_t *scene, int fd, \
game_info_t *game_info);
tile_info_t *get_tile(tile_info_t *tile, char *buffer, game_info_t *game_info);

/*scene_parsing.c*/

int get_nb_scene(int fd);
scene_info_t *get_tileset(scene_info_t *scene_info, int fd, \
game_info_t *game_info);
scene_info_t *get_background(scene_info_t *scene_info, int fd, \
game_info_t *game_info);
sfVector2i get_nb_tile(int fd);
int check_tile(tile_info_t *tile);

/*tile_parsing.c*/

int get_tile_id(char *buffer);
sfVector2i get_tile_pos(char *buffer);
int get_event_id(char *buffer);
int get_tile_type(char *buffer);
int get_tile_layer(char *buffer);

/*struct_init.c*/

game_info_t *init_game_info(void);
scene_info_t **init_scene(int nb_scene);
tile_info_t **realloc_tile(tile_info_t **tile, int nb_arg);
scene_info_t *get_scene_info(scene_info_t *scene, int fd, \
game_info_t *game_info);
	
/*free_game_info.c*/

void free_game_info(game_info_t *game_info);
void free_scene(scene_info_t **scene);
void free_tile(tile_info_t **tile);

#endif