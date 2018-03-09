/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return 1 if str only contains lower alpha char
*/

int my_str_islower(char const *str)
{
	if (str[0] == '\0')
		return (1);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < 97 || str[i] > 122)
			return (0);
	}
	return (1);
}
