/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return nb at the power p in rec
*/

static int is_exception_p_rec(int, int);

int my_compute_power_rec(int nb, int p)
{
	int total = 0;

	if (p <= 0)
		return ((p == 0) ? 1 : 0);
	if (nb == 0)
		return (0);
	if (is_exception_p_rec(total, nb))
		return (0);
	total = nb * my_compute_power_rec(nb, p - 1);
	return (total);
}

int is_exception_p_rec(int current_total, int nb)
{
	if (nb > 0) {
		if (current_total > 2147483647 / nb)
			return (1);
	}
	else {
		if (current_total > -2147483647 / nb)
			return (1);
	}
	return (0);
}
