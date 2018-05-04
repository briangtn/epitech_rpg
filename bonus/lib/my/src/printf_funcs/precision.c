/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Truncate the str
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>

int *initialise_stars(int **tab, char *options, va_list list, char end_char)
{
	int i = 0;

	*tab = malloc(sizeof(int) * 2);
	(*tab)[0] = 0;
	(*tab)[1] = 0;
	for (i = 0; options[i] != '.' && options[i] != end_char; i++) {
		if (options[i] == '*')
			(*tab)[0] = va_arg(list, int);
	}
	if (options[i] == '.' && options[i + 1] == '*')
		(*tab)[1] = va_arg(list, int);
	return (*tab);
}

char *option_precision(char *str, int len)
{
	char *new_str = malloc(len + 1);

	my_strncpy(new_str, str, len);
	new_str[len] = '\0';
	return (new_str);
}

int option_width(char *options, int length, int star_value, char c)
{
	int i = 0;
	int to_display = 0;

	while (is_allowed_argument(options[i], ALLOWED_TYPES) == 0 \
&& options[i] != '.') {
		if (is_allowed_argument(options[i], ALLOWED_WIDTH))
			break;
		i++;
	}
	if (is_allowed_argument(options[i], ALLOWED_WIDTH)) {
		if (options[i] == '*')
			to_display = star_value;
		else
			to_display = my_getnbr(&options[i]);
	}
	to_display -= length;
	for (int i = 0; i < to_display; i++)
		my_putchar(c);
	return ((to_display > 0) ? to_display : 0);
}