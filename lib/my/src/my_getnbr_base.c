/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Convert and return a base 10 number from a base base number
*/

#include "my.h"

static int is_not_valid_char(char const *str, int i, char const *base);
static int contains(char const *str, int index, char const *base);
static int get_index(char const *str, int index, char const *base);

int my_getnbr_base(char const *str, char const *base)
{
	int base_size = my_strlen(base);
	int result = 0;
	int sign = 1;

	for (int i = 0; str[i] != '\0'; i++) {
		if (is_not_valid_char(str, i, base))
			return (0);
		if (str[i] == '-')
			sign *= -1;
		result = result * base_size + get_index(str, i, base);
	}
	return (result * sign);
}

int is_not_valid_char(char const *str, int i, char const *base)
{
	if (str[i] != '+' && str[i] != '-' && contains(str, i, base) != 1)
		return (1);
	return (0);
}

int contains(char const *str, int index, char const *base)
{
	for (int i = 0; base[i] != '\0'; i++) {
		if (base[i] == str[index])
			return (1);
	}
	return (0);
}

int get_index(char const *str, int index, char const *base)
{
	for (int i = 0; base[i] != '\0'; i++) {
		if (base[i] == str[index])
			return (i);
	}
	return (0);
}
