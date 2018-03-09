/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return nb at the power p in rec
*/

int my_pow(int nb, int p)
{
	if (p <= 0)
		return ((p == 0) ? 1 : 0);
	if (nb == 0)
		return (0);
	return (nb * my_pow(nb, p - 1));
}
