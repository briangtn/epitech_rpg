/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return the square root of an whole number
*/

int my_compute_square_root(int nb)
{
	if (nb <= 0)
		return (0);
	for (int i = 0; (i * i) <= nb; i++) {
		if ((i * i) == nb)
			return (i);
	}
	return (0);
}
