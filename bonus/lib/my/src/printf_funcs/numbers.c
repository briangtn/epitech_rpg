/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** Function for all number printing except unsigned int
*/

#include "my.h"
#include <stdarg.h>

int display_minus_nb_neg(int number)
{
	if (number < 0)
		return (my_putchar('-'));
	return (0);
}

int my_printf_di(int number, char *options, int *stars)
{
	int displayed = 0;

	if (str_contains('-', options) == 0) {
		if (str_contains('0', options))
			displayed += display_minus_nb_neg(number);
		displayed += option_flag_minus_i(stars[0], \
display_int_base(number, "0123456789", 0) + (number < 0), options, number);
		if (str_contains('0', options) == 0)
			displayed += display_minus_nb_neg(number);
		displayed += display_int_base(number, "0123456789", 1);
	} else {
		if (str_contains('+', options))
			displayed += option_flag_plus(number);
		else if (str_contains(' ', options))
			displayed += option_flag_space(number);
		displayed += display_minus_nb_neg(number);
		displayed += display_int_base(number, "0123456789", 1);
		displayed += option_width(options, displayed, stars[0], ' ');
	}
	return (displayed);
}

int my_printf_i(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'i');
	int number = va_arg(list, int);
	int displayed = 0;

	displayed += my_printf_di(number, options, stars);
	free(stars);
	return (displayed);
}

int my_printf_d(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'd');
	int number = va_arg(list, int);
	int displayed = 0;

	displayed += my_printf_di(number, options, stars);
	free(stars);
	return (displayed);
}

int my_printf_p(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'p');
	void *ptr = va_arg(list, void *);
	int displayed = 2;

	if (str_contains('-', options) == 0) {
		displayed += option_flag_minus_i(stars[0], \
display_long_base((long)ptr, HEXA_BASE_MIN, 0) + displayed, options, 1);
		my_putstr("0x");
		displayed += display_long_base((long)ptr, HEXA_BASE_MIN, 1);
	} else {
		if (str_contains('+', options))
			displayed += option_flag_plus(1);
		else if (str_contains(' ', options))
			displayed += option_flag_space(1);
		my_putstr("0x");
		displayed += display_long_base((long)ptr, HEXA_BASE_MIN, 1);
		displayed += option_width(options, displayed, stars[0], ' ');
	}
	free(stars);
	return (displayed);
}