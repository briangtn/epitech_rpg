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
	int startx = 0;
	int starty = 0;
	int x2 = 0;
	int y2 = 0;

	if (ac != 5) {
		dprintf(2, "./hitbox_helper x1 y1 x2 y2\n");
		return (84);
	}
	x1 = atoi(av[1]);
	y1 = atoi(av[2]);
	x2 = atoi(av[3]);
	y2 = atoi(av[4]);
	for (startx = x1; startx <= x2; startx++)
		for (starty = y1; starty <= y2; starty++)
			printf((startx == x1 || startx == x2 || starty == y1 ||\
starty == y2) ? "TILE_ID : \"1\" ; TILE_POS : \"%i\" x \"%i\" ; \
EVENT : \"0\" ; TILE_TYPE : \"2\" ; LAYER : \"1\"\n" : "", startx, starty);
	return (0);
}
