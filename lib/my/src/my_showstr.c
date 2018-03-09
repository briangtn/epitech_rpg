/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** print a str and return 0 if non printable char print it in hex
*/

#include "my.h"

int my_showstr(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < 32 || str[i] > 126) {
			my_putchar('\\');
			my_putchar('0');
			my_putnbr_base(str[i], "0123456789abcdef");
		}
		else {
			my_putchar(str[i]);
		}
	}
	return (0);
}
