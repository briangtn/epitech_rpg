/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Concatenates two strings but only the nb first char of src
*/

char *my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0' && j < nb; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
