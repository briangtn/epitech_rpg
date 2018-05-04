/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Return a char * containing a int
*/

#include "my.h"

static int nb_size(int nb);

int	nb_size(int nb)
{
	int i = 1;

	if (nb < 0) {
		i++;
		nb = (nb + 1) * -1;
	}
	while (nb / 10 != 0) {
		i++;
		nb /= 10;
	}
	return (i);
}

char	*my_int_to_str(int nb)
{
	int pos = 0;
	int div = my_compute_power_rec(10, nb_size(nb) - (nb < 0) - 1);
	char *nb_str = malloc(sizeof(*nb_str) * (nb_size(nb) + 1));

	if (nb < 0) {
		nb_str[pos] = '-';
		pos++;
	}
	while (div != 0) {
		nb_str[pos] = ((ABS(nb / div)) + '0');
		pos++;
		nb = nb % div;
		div /= 10;
	}
	nb_str[pos] = '\0';
	return (nb_str);
}