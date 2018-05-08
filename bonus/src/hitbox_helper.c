/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** Return line creating invisible hitboxs
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	if (ac != 5) {
		dprintf(2, "./hitbox_helper x1 y1 x2 y2\n");
		return (84);
	}
	x2 = atoi(av[3]);
	y2 = atoi(av[4]);
	for (x1 = atoi(av[1]); x1 <= x2; x1++) {
		for (y1 = atoi(av[2]); y1 <= y2; y1++) {
			printf("TILE_ID : \"1\" ; TILE_POS : \"%i\" x \"%i\" ; \
EVENT : \"0\" ; TILE_TYPE : \"2\" ; LAYER : \"1\"\n", x1, y1);
		}
	}
	return (0);
}
