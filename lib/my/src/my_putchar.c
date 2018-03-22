/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Put a character on the screen
*/

#include <unistd.h>

int	my_putchar(char c)
{
	return (write(1, &c, 1));
}

int	my_putchar_cond(char c, int condition)
{
	if (condition)
		return (write(1, &c, 1));
	return (0);
}