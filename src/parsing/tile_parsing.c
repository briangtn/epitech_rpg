/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** every function in relation with tile info
*/

#include "my.h"
#include "get_next_line.h"
#include "parsing.h"

int get_tile_layer(char *buffer)
{
	int n = 0;
	int tile_layer = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 11) {
			tile_layer = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	if (tile_layer <= 0)
		return (WRONG_LAYER);
	return (tile_layer);
}

int get_tile_type(char *buffer)
{
	int n = 0;
	int tile_type = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 9) {
			tile_type = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	if (tile_type <= 0)
		return (WRONG_TYPE);
	return (tile_type);
}

int get_event_id(char *buffer)
{
	int n = 0;
	int event_id = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 7) {
			event_id = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	if (event_id <= 0)
		return (WRONG_EVENT);
	return (event_id);
}

sfVector2i get_pos(char *buffer)
{
	int n = 0;
	sfVector2i tile_pos = {0, 0};

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 3) {
			tile_pos.x = my_getnbr(&buffer[i + 1]);
		} else if (buffer[i] == '"' && n == 5) {
			tile_pos.y = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	if (tile_pos.x <= 0 || tile_pos.y <= 0)
		return ((sfVector2i){WRONG_POS, 0});
	return (tile_pos);
}

int get_id(char *buffer)
{
	int n = 0;
	int tile_id = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '"')
			n++;
		if (buffer[i] == '"' && n == 1) {
			tile_id = my_getnbr(&buffer[i + 1]);
			break;
		}
	}
	if (tile_id <= 0)
		return (WRONG_ID);
	return (tile_id);
}