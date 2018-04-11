/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** every function in relation with scene info
*/

#include "my.h"
#include "get_next_line.h"
#include "parsing.h"

int check_tile(tile_info_t *tile)
{
	if (tile->tile_id < 0)
		return (tile->tile_id * -1);
	if (tile->tile_pos.x < 0)
		return (tile->tile_pos.x * -1);
	if (tile->event_id < 0)
		return (tile->event_id * -1);
	if (tile->tile_type < 0)
		return (tile->tile_type * -1);
	if (tile->layer < 0)
		return (tile->tile_type * -1);
	return (0);
}

sfVector2i get_nb_tile(int fd)
{
	char *buffer = get_next_line(fd);
	sfVector2i nb_tile = {0, 0};
	int n = 0;

	if (buffer == NULL)
		return ((sfVector2i){EMPTY_FILE, 0});
	if (!(match(buffer, TILE_PER_SCENE))) {
		free (buffer);
		return ((sfVector2i){UNKNOWN_PARAM, 0});
	}
	for (int i = 0; buffer[i] != '\0'; i++) {
		n += (buffer[i] == '"') ? 1 : 0;
		if (buffer[i] == '"' && n == 1)
			nb_tile.x = my_getnbr(&buffer[i + 1]);
		else if (buffer[i] == '"' && n == 3)
			nb_tile.y = my_getnbr(&buffer[i + 1]);
	}
	free (buffer);
	if (nb_tile.x <= 0 || nb_tile.y <= 0)
		return ((sfVector2i){TOO_FEW_TILES, 0});
	return (nb_tile);
}

int get_nb_scene(int fd)
{
	char *buffer = get_next_line(fd);
	int nb_scene = 0;

	if (buffer == NULL)
		return (EMPTY_FILE);
	if (!(match(buffer, NB_SCENE))) {
		free(buffer);
		return (UNKNOWN_PARAM);
	}
	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"') {
			nb_scene = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	free(buffer);
	if (nb_scene <= 0)
		return (TOO_FEW_SCENES);
	return (nb_scene);
}