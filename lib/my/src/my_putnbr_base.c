/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Convert and display a number in a base
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
	int base_size = my_strlen(base);

	if (nbr < 0) {
		my_putchar('-');
		if (nbr / base_size != 0)
			my_putnbr_base(-(nbr / base_size), base);
	}
	else {
		if (nbr / base_size != 0)
			my_putnbr_base(nbr / base_size, base);
	}
	if (nbr == -2147483648)
		nbr = nbr + base_size;
	if (nbr < 0)
		nbr = nbr * -1;
	my_putchar(base[nbr % base_size]);
	return (0);
}
