/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return 1 if nb is prime and 0 if not
*/

int my_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	for (int i = 2; i < nb; i++) {
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
