/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Reverse the string given in param
*/

#include "my.h"

char *my_revstr(char *str)
{
	char temp_str[my_strlen(str) + 1];

	for (int i = 0; i <= my_strlen(str); i++)
		temp_str[i] = str[i];
	for (int i = 0; i < my_strlen(temp_str); i++)
		str[i] = temp_str[my_strlen(temp_str) - 1 - i];
	return (str);
}
