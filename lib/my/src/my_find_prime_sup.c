/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return the next prime number and 0 if there are no prime greater
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
	if (nb <= 2)
		nb = 2;
	for (int i = 0; (nb + i) <= 2147483647; i++) {
		if (my_is_prime(nb + i))
			return (nb + i);
	}
	return (0);
}
