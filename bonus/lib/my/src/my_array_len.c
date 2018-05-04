/*
** EPITECH PROJECT, 2017
** my
** File description:
** Return a null terminated array size
*/

/* File created the 20/03/2018 at 14:28:36 by julian.frabel@epitech.eu */

#include <stdlib.h>

int my_array_len(void **array)
{
	int len = 0;

	if (array == NULL)
		return (0);
	for (len = 0; array[len] != NULL; len++);
	return (len);
}