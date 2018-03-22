/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return 1 if str only contains alpha numbers
*/

int my_str_isalpha(char const *str)
{
	if (str[0] == '\0')
		return (1);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
			return (0);
	}
	return (1);
}
