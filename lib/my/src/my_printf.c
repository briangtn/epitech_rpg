/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** Do the same job as printf
*/

#include "my.h"
#include <stdarg.h>

ptr_function get_print_function(char type)
{
	for (int i = 0; PRINTF_ARGS[i].type != '\0'; i++) {
		if (PRINTF_ARGS[i].type == type) {
			return (PRINTF_ARGS[i].func);
		}
	}
	return (NULL);
}

int is_allowed_argument(char arg, const char *ARG_TAB)
{
	for (int i = 0; ARG_TAB[i] != '\0'; i++) {
		if (arg == ARG_TAB[i])
			return (1);
	}
	return (0);
}

ptr_function get_function(const char *arg, int *index)
{
	int i = *index + 1;
	int (*function)(va_list, char *options) = NULL;

	while (function == NULL) {
		if (is_allowed_argument(arg[i], ALLOWED_ARGS) == 0)
			return (NULL);
		function = get_print_function(arg[i]);
		i++;
	}
	if (function != NULL) {
		*index = i - 1;
	}
	return (function);
}

int run_function(va_list list, const char *format, int *index)
{
	int (*function)(va_list, char *options) = NULL;
	int base_index = *index;

	function = get_function(format, index);
	if (function != NULL) {
		return ((*function)(list, (char *)&format[base_index + 1]));
	} else {
		my_putchar('%');
		return (1);
	}
}

int my_printf(const char *format, ...)
{
	va_list list;
	int displayed = 0;

	va_start(list, format);
	for (int i = 0; format[i] != '\0'; i++) {
		if (format[i] == '%') {
			displayed += run_function(list, format, &i);
		} else {
			my_putchar(format[i]);
			displayed += 1;
		}
	}
	va_end(list);
	return (displayed);
}
