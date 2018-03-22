/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** swap two int
*/

void	my_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
