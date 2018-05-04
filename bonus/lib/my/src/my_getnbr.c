/*
** EPITECH PROJECT, 2017
** libmy.h
** File description:
** return the first int in the given string
*/

static int is_digit(int c);
static int handle_n_digit(int total, int *sign, int c);
static int get_final_return(int total, int sign, int is_too_long);
static int is_same_sign(int nb1, int nb2);

int	my_getnbr(char const *str)
{
	int	total = 0;
	int	i = 0;
	int	sign = 1;
	int	should_return = 0;
	int	is_too_long = 0;

	if (str == 0)
		return (0);
	while (str[i] != '\0' && should_return == 0) {
		if (is_digit(str[i]) && is_too_long < 11) {
			total = total * 10 + (str[i] - 48);
			is_too_long++;
		}
		else {
			should_return = handle_n_digit(total, &sign, str[i]);
		}
		i++;
	}
	return (get_final_return(total * sign, sign, is_too_long));
}

int is_digit(int c)
{
	return ((c <= '9') && (c >= '0'));
}

int handle_n_digit(int total, int *sign, int c)
{
	if (total > 0)
		return (1);
	if (c == '-' || c == '+') {
		*sign *= (c == '-') ? -1 : 1;
		return (0);
	}
	else
		return (1);
}

int get_final_return(int total, int sign, int is_too_long)
{
	if (is_same_sign(total, sign) && is_too_long < 11)
		return (total);
	else
		return (0);
}

int is_same_sign(int nb1, int nb2)
{
	if ((nb1 < 0 && nb2 < 0) || (nb1 >= 0 && nb2 >= 0))
		return (1);
	else
		return (0);
}
