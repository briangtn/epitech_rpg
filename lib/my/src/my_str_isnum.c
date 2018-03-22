/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return 1 if str only contains numbers
*/

int my_str_isnum(char const *str)
{
	if (str[0] == '\0')
		return (1);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
