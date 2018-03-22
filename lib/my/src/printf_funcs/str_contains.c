/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** str_contains function
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>

int str_contains(char c, char *str)
{
	int occurences = 0;

	for (int i = 0; str[i] != '\0' && \
is_allowed_argument(str[i], ALLOWED_TYPES) != 1; i++) {
		if (str[i] == c)
			occurences++;
	}
	return (occurences);
}