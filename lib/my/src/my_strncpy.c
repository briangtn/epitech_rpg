/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Copy n characters from a string to another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	if (dest == NULL || src == NULL || n <= 0)
		return (dest);
	while (i < n) {
		if (i > my_strlen(src))
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
