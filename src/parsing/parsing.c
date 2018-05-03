/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** config parser for rpg
*/

#include "my.h"
#include "get_next_line.h"
#include "parsing.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *error_messages[] = {
	"No error\n",
	"Error: empty config file\n",
	"Error: unknown parameter\n",
	"Error: there must be at least one scene\n",
	"Error: there must be at least one tile per column and line\n",
	"Error: wrong ID\n",
	"Error: wrong position\n",
	"Error: wrong event ID\n",
	"Error: wrong tile type\n",
	"Error: wrong tile layer\n",
	"Error: bad format\n"
};

tile_info_t *get_tile(tile_info_t *tile, char *buffer, game_info_t *game_info)
{
	int error = 0;

	if (!(match(buffer, TILE_INFO))) {
		free(buffer);
		my_puterror(error_messages[10]);
		return (NULL);
	}
	tile->tile_id = get_id(buffer);
	tile->tile_pos = get_pos(buffer);
	tile->event = get_event(buffer);
	tile->tile_type = get_tile_type(buffer, tile->event);
	tile->layer = get_tile_layer(buffer, tile->event);
	if ((error = check_tile(tile)) != 0) {
		my_puterror(error_messages[error]);
		free_game_info(game_info);
		free(buffer);
		return (NULL);
	}
	return (tile);
}

scene_info_t *parse_tile_info(scene_info_t *scene, int fd, \
game_info_t *game_info)
{
	char *buffer = NULL;
	int i = 0;

	scene->tile = NULL;
	buffer = get_next_line(fd);
	while (buffer != NULL && buffer[0] != '\0') {
		scene->tile = realloc_tile(scene->tile, i + 1);
		if (scene->tile == NULL) {
			free_game_info(game_info);
			return (NULL);
		}
		scene->tile[i] = get_tile(scene->tile[i], buffer, game_info);
		if (scene->tile[i] == NULL)
			return (NULL);
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (buffer != NULL)
		free(buffer);
	return (scene);
}

game_info_t *parse_scene_info(game_info_t *game_info, int fd)
{
	char *buffer = NULL;

	buffer = get_next_line(fd);
	free(buffer);
	for (int i = 0; game_info->scene[i] != NULL; i++) {
		buffer = get_next_line(fd);
		if (!(match(buffer, SCENE))) {
			free(buffer);
			free_game_info(game_info);
			my_puterror(error_messages[10]);
			return (NULL);
		}
		game_info->scene[i] = get_scene_info(game_info->scene[i], fd, \
game_info);
		free(buffer);
		if (game_info->scene[i] == NULL)
			return (NULL);
	}
	return (game_info);
}

game_info_t *parse_game_info(game_info_t *game_info, int fd)
{
	game_info->nb_scene = get_nb_scene(fd);
	if (game_info->nb_scene < 0) {
		my_puterror(error_messages[game_info->nb_scene * -1]);
		free_game_info(game_info);
		return (NULL);
	}
	game_info->tile_per_scene = get_nb_tile(fd);
	if (game_info->tile_per_scene.x < 0) {
		my_puterror(error_messages[game_info->tile_per_scene.x * -1]);
		free_game_info(game_info);
		return (NULL);
	}
	game_info->scene = init_scene(game_info->nb_scene);
	if (game_info->scene == NULL) {
		free_game_info(game_info);
		return (NULL);
	}
	game_info = parse_scene_info(game_info, fd);
	return (game_info);
}

game_info_t *parse_config(const char *file)
{
	int fd = open(file, O_RDONLY);
	game_info_t *game_info = NULL;

	if (fd == -1)
		return (NULL);
	game_info = init_game_info();
	if (game_info == NULL)
		return (NULL);
	game_info = parse_game_info(game_info, fd);
	close(fd);
	if (game_info == NULL)
		return (NULL);
	return (game_info);
}