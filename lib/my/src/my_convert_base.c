/*
** EPITECH PROJECT, 2017
** CPool_Day08_2017
** File description:
** convert a nb in base_from to a nb in base_to
*/

#include <stdlib.h>
#include "my.h"

static char *return_nbr_base(int nbr, char const *base);
static char *compute_new_str_and_free_last(char *, char, int);

char *my_convert_base(char const *nb, char const *base_f, char const *base_to)
{
	int nb_decimal = my_getnbr_base(nb, base_f);

	return (return_nbr_base(nb_decimal, base_to));
}

char *return_nbr_base(int nbr, char const *base)
{
	int base_size = my_strlen(base);
	int is_neg = 0;
	char *last_chain = 0;
	char to_add;

	if (nbr < 0) {
		is_neg = 1;
		if (nbr / base_size != 0)
			last_chain = return_nbr_base(-(nbr / base_size), base);
	}
	else {
		if (nbr / base_size != 0)
			last_chain = return_nbr_base(nbr / base_size, base);
	}
	if (nbr == -2147483648)
		nbr = nbr + base_size;
	if (nbr < 0)
		nbr = nbr * -1;
	to_add = base[nbr % base_size];
	return (compute_new_str_and_free_last(last_chain, to_add, is_neg));
}

char *compute_new_str_and_free_last(char *last, char to_add, int is_neg)
{
	char *new_str;
	int i = 0;

	if (last != 0)
		new_str = malloc(my_strlen(last) + 2 + is_neg);
	else
		new_str = malloc(2 + is_neg);
	if (is_neg) {
		new_str[i] = '-';
		i++;
	}
	new_str[i] = to_add;
	i++;
	new_str[i] = '\0';
	if (last != 0) {
		my_strcat(new_str, last);
		free(last);
	}
	return (new_str);
}
