/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** Function for all char printing
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_printf_c(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'c');
	char c = va_arg(list, int);
	int displayed = 0;

	if (str_contains('-', options)) {
		displayed += write(1, &c, 1);
		displayed += option_width(options, 1, stars[0], ' ');
	} else {
		displayed += option_width(options, 1, stars[0], ' ');
		displayed += write(1, &c, 1);
	}
	free(stars);
	return (displayed);
}

int my_printf_s(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 's');
	char *str = va_arg(list, char *);
	int displayed = 0;
	int i = 0;

	if (str_contains('.', options)) {
		for (; options[i] != '.'; i++);
		if (my_getnbr(&options[i + 1]) == 0)
			str = option_precision(str, stars[1]);
		else
			str = option_precision(str, my_getnbr(&options[i + 1]));
	}
	displayed += option_minus_str(str, options, stars[0]);
	if (str_contains('.', options))
		free(str);
	free(stars);
	return (displayed);
}

int my_printf_smaj(va_list list, char *options)
{
	int *stars = initialise_stars(&stars, options, list, 'S');
	char *str = va_arg(list, char *);
	int displayed = 0;
	int i = 0;

	if (str_contains('.', options)) {
		for (; options[i] != '.'; i++);
		if (my_getnbr(&options[i + 1]) == 0)
			str = option_precision(str, stars[1]);
		else
			str = option_precision(str, my_getnbr(&options[i + 1]));
	}
	displayed += option_minus_show_str(str, options, stars[0]);
	if (str_contains('.', options))
		free(str);
	free(stars);
	return (displayed);
}

int my_printf_percent(va_list list, char *options)
{
	(void)list;
	(void)options;
	my_putchar('%');
	return (1);
}