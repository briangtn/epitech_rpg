/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** constants
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>

const printf_arg_t PRINTF_ARGS[] = {
	{'%', &(my_printf_percent)},
	{'i', &(my_printf_i)},
	{'d', &(my_printf_d)},
	{'p', &(my_printf_p)},
	{'u', &(my_printf_u)},
	{'x', &(my_printf_x)},
	{'X', &(my_printf_xmaj)},
	{'o', &(my_printf_o)},
	{'b', &(my_printf_b)},
	{'c', &(my_printf_c)},
	{'s', &(my_printf_s)},
	{'S', &(my_printf_smaj)},
	{'\0', NULL}
};

const char ALLOWED_ARGS[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '$',
	'-', '+', ' ', '#',
	'*',
	'.',
	'%', 'd', 'i', 'u', 'x', 'X', 'o', 's', 'c', 'p', 'b', 'S',
	'\0'
};

const char ALLOWED_FLAGS[] = {
	'-', '+', ' ', '0', '#', '\0'
};

const char ALLOWED_WIDTH[] = {
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '\0'
};

const char ALLOWED_PRECISION[] = {
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '.', '\0'
};

const char ALLOWED_TYPES[] = {
	'%', 'd', 'i', 'p', 'u', 'x', 'X', 'o', 'b', 'c', 's', 'S', '\0'
};