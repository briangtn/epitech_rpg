/*
** EPITECH PROJECT, 2017
** my
** File description:
** Free a null terminated array
*/

/* File created the 20/03/2018 at 14:31:19 by julian.frabel@epitech.eu */

#include <stdlib.h>

void my_free_array(void **array)
{
	if (array == NULL)
		return;
	for (int i = 0; array[i] != NULL; i++) {
		free(array[i]);
	}
	free(array);
}