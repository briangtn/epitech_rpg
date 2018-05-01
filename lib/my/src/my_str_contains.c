/*
** EPITECH PROJECT, 2017
** my
** File description:
** Does str contain a given char
*/

/* File created the 19/03/2018 at 10:46:55 by julian.frabel@epitech.eu */

#include <stdlib.h>

int my_str_contains(const char *str, char c)
{
	if (str == NULL)
		return (0);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			return (i + 1);
	}
	return (0);
}