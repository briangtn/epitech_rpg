/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Run the options specified
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>

int option_minus_str(char *str, char *options, int star)
{
	int displayed = 0;

	if (str_contains('-', options)) {
		displayed += write(1, str, my_strlen(str));
		displayed += option_width(options, my_strlen(str), star, ' ');
	} else {
		displayed += option_width(options, my_strlen(str), star, ' ');
		displayed += write(1, str, my_strlen(str));
	}
	return (displayed);
}

int option_minus_show_str(char *str, char *options, int star)
{
	int displayed = 0;

	if (str_contains('-', options)) {
		displayed += display_str_show(str, 1);
		displayed += option_width(options, \
display_str_show(str, 0), star, ' ');
	} else {
		displayed += option_width(options, \
display_str_show(str, 0), star, ' ');
		displayed += display_str_show(str, 1);
	}
	return (displayed);
}

int option_minus_x(int *stars, unsigned int number, char *options)
{
	int displayed = 0;

	if (str_contains('0', options))
		displayed += option_flag_hash(options, "0x");
	displayed += option_flag_minus_i(stars[0], \
display_uint_base(number, HEXA_BASE_MIN, 0) + hash(options, 2), options, 1);
	if (str_contains('0', options) == 0)
		displayed += option_flag_hash(options, "0x");
	return (displayed);
}

int option_minus_xmaj(int *stars, unsigned int number, char *options)
{
	int displayed = 0;

	if (str_contains('0', options))
		displayed += option_flag_hash(options, "0x");
	displayed += option_flag_minus_i(stars[0], \
display_uint_base(number, HEXA_BASE_MAJ, 0) + hash(options, 2), options, 1);
	if (str_contains('0', options) == 0)
		displayed += option_flag_hash(options, "0x");
	return (displayed);
}

int option_minus_o(int *stars, unsigned int number, char *options)
{
	int displayed = 0;

	if (str_contains('0', options))
		displayed += option_flag_hash(options, "0");
	displayed += option_flag_minus_i(stars[0], \
display_uint_base(number, "01234567", 0) + hash(options, 1), options, 1);
	if (str_contains('0', options) == 0)
		displayed += option_flag_hash(options, "0");
	return (displayed);
}