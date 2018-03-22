/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** functions for the flags
*/

#include "my.h"
#include <stdarg.h>

int option_flag_minus_i(int star, int already_disp, char *options, int nb)
{
	int disp = 0;

	if (str_contains('0', options)) {
		if (str_contains('+', options))
			disp += option_flag_plus(nb);
		else if (str_contains(' ', options))
			disp += option_flag_space(nb);
		disp += option_width(options, disp + already_disp, star, '0');
		return (disp);
	} else {
		disp += option_width(options, disp + already_disp + \
((str_contains('+', options) || str_contains(' ', options)) ? 1 : 0), \
star, ' ');
		if (str_contains('+', options))
			disp += option_flag_plus(nb);
		else if (str_contains(' ', options))
			disp += option_flag_space(nb);
		return (disp);
	}
	return (disp);
}

int option_flag_plus(int value)
{
	if (value > 0) {
		my_putchar('+');
		return (1);
	}
	return (0);
}

int option_flag_space(int value)
{
	if (value > 0) {
		my_putchar(' ');
		return (1);
	}
	return (0);
}

int option_flag_hash(char *options, char const * to_display)
{
	if (str_contains('#', options)) {
		my_putstr(to_display);
		return (my_strlen(to_display));
	}
	return (0);
}

int hash(char *options, int str_size)
{
	if (str_contains('#', options)) {
		return (str_size);
	}
	return (0);
}