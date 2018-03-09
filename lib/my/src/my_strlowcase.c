/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Put every letter of str in lower case
*/

char *my_strlowcase(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return (str);
}
