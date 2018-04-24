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
	STANDARD = 1,
	COLLIDE,
	HIDE
};

typedef struct npc_info npc_info_t;

struct npc_info {
	int npc_id;
	sfVector2i npc_pos;
	int event_id;
};

typedef struct loot_info loot_info_t;

struct loot_info {
	int loot_id;
	sfVector2i loot_pos;
	int event_id;
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
	npc_info_t **npc;
	loot_info_t **loot;
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
#define NPC_INFO	"NPC_ID : \"*\" ; NPC_POS : \"*\" x \"*\" ; EVENT_ID : \
\"*\""
#define LOOT_INFO	"LOOT_ID : \"*\" ; LOOT_POS : \"*\" x \"*\" ; EVENT_ID \
: \"*\""
#define TILE_INFO	"TILE_ID : \"*\" ; TILE_POS : \"*\" x \"*\" ; EVENT_ID \
: \"*\" ; TILE_TYPE : \"*\" ; LAYER : \"*\""

/*parsing.c*/

game_info_t *parse_config(const char *file);
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

/*npc_loot_parsing.c*/

scene_info_t *parse_npc_info(scene_info_t *scene, int fd, \
game_info_t *game_info);
npc_info_t *get_npc(npc_info_t *npc, char *buffer, game_info_t *game_info);
scene_info_t *parse_loot_info(scene_info_t *scene, int fd, \
game_info_t *game_info);
loot_info_t *get_loot(loot_info_t *loot, char *buffer, game_info_t *game_info);
loot_info_t **realloc_loot(loot_info_t **loot, int nb_arg);

/*tile_parsing.c*/

int get_id(char *buffer);
sfVector2i get_pos(char *buffer);
int get_event_id(char *buffer);
int get_tile_type(char *buffer);
int get_tile_layer(char *buffer);

/*struct_init.c*/

game_info_t *init_game_info(void);
scene_info_t **init_scene(int nb_scene);
tile_info_t **realloc_tile(tile_info_t **tile, int nb_arg);
npc_info_t **realloc_npc(npc_info_t **npc, int nb_arg);
scene_info_t *get_scene_info(scene_info_t *scene, int fd, \
game_info_t *game_info);

/*check.c*/

int check_tile(tile_info_t *tile);
int check_npc(npc_info_t *npc);
int check_loot(loot_info_t *loot);

/*free_game_info.c*/

void free_game_info(game_info_t *game_info);
void free_scene(scene_info_t **scene);
void free_tile(tile_info_t **tile);

#endif
