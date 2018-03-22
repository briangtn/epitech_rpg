/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Copy a str into another
*/

char *my_strcpy(char *dest, char const *src)
{
	int iterator = 0;

	if (dest == 0 || src == 0)
		return (dest);
	while (src[iterator] != '\0') {
		dest[iterator] = src[iterator];
		iterator++;
	}
	dest[iterator] = '\0';
	return (dest);
}
