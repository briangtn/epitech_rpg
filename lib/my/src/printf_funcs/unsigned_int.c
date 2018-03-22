/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** Function for all unsigned int printing
*/

#include "my.h"
#include <stdarg.h>

int my_printf_u(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'u');
	unsigned int number = va_arg(list, unsigned int);
	int displayed = 0;

	if (str_contains('-', options) == 0) {
		displayed += option_flag_minus_i(stars[0], \
display_uint_base(number, "0123456789", 0), options, 1);
		displayed += display_uint_base(number, "0123456789", 1);
	} else {
		if (str_contains('+', options))
			displayed += option_flag_plus(1);
		else if (str_contains(' ', options))
			displayed += option_flag_space(1);
		displayed += display_uint_base(number, "0123456789", 1);
		displayed += option_width(options, displayed, stars[0], ' ');
	}
	free(stars);
	return (displayed);
}

int my_printf_x(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'x');
	unsigned int number = va_arg(list, unsigned int);
	int displayed = 0;

	if (str_contains('-', options) == 0) {
		displayed += option_minus_x(stars, number, options);
		displayed += display_uint_base(number, HEXA_BASE_MIN, 1);
	} else {
		if (str_contains('+', options))
			displayed += option_flag_plus(1);
		else if (str_contains(' ', options))
			displayed += option_flag_space(1);
		displayed += option_flag_hash(options, "0x");
		displayed += display_uint_base(number, HEXA_BASE_MIN, 1);
		displayed += option_width(options, displayed, stars[0], ' ');
	}
	free(stars);
	return (displayed);
}

int my_printf_xmaj(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'X');
	unsigned int number = va_arg(list, unsigned int);
	int displayed = 0;

	if (str_contains('-', options) == 0) {
		displayed += option_minus_xmaj(stars, number, options);
		displayed += display_uint_base(number, HEXA_BASE_MAJ, 1);
	} else {
		if (str_contains('+', options))
			displayed += option_flag_plus(1);
		else if (str_contains(' ', options))
			displayed += option_flag_space(1);
		displayed += option_flag_hash(options, "0x");
		displayed += display_uint_base(number, HEXA_BASE_MAJ, 1);
		displayed += option_width(options, displayed, stars[0], ' ');
	}
	free(stars);
	return (displayed);
}

int my_printf_o(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'o');
	unsigned int number = va_arg(list, unsigned int);
	int displayed = 0;

	if (str_contains('-', options) == 0) {
		displayed += option_minus_o(stars, number, options);
		displayed += display_uint_base(number, "01234567", 1);
	} else {
		if (str_contains('+', options))
			displayed += option_flag_plus(1);
		else if (str_contains(' ', options))
			displayed += option_flag_space(1);
		displayed += option_flag_hash(options, "0");
		displayed += display_uint_base(number, "01234567", 1);
		displayed += option_width(options, displayed, stars[0], ' ');
	}
	free(stars);
	return (displayed);
}

int my_printf_b(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'b');
	unsigned int number = va_arg(list, unsigned int);
	int displayed = 0;

	if (str_contains('-', options) == 0) {
		displayed += option_flag_minus_i(stars[0], \
display_uint_base(number, "01", 0), options, 1);
		displayed += display_uint_base(number, "01", 1);
	} else {
		if (str_contains('+', options))
			displayed += option_flag_plus(1);
		else if (str_contains(' ', options))
			displayed += option_flag_space(1);
		displayed += display_uint_base(number, "01", 1);
		displayed += option_width(options, displayed, stars[0], ' ');
	}
	free(stars);
	return (displayed);
}