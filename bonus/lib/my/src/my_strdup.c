/*
** EPITECH PROJECT, 2017
** CPool_Day08_2017
** File description:
** Allocates memory and cpy a str in it then return it
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
	char *cpy_str = malloc(sizeof(*cpy_str) * (my_strlen(src) + 1));

	my_strcpy(cpy_str, src);
	return (cpy_str);
}
