/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** display a string
*/

#include "my.h"
#include <unistd.h>

int	my_putstr(char const *str)
{
	return (write(1, str, my_strlen(str)));
}

int	my_puterror(char const *error)
{
	return (write(2, error, my_strlen(error)));
}