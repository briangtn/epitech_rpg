/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return 1 if string are the same else return 0
*/

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return ((s1[i] != '\0') ? s1[i] : -s2[i]);
	return (0);
}
