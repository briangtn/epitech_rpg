/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Return 1 if string are the same else return 0 (only compare n 1st char)
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	if (s1 == 0 || s2 == 0)
		return (0);
	for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if ((s1[i] != '\0' || s2[i] != '\0') && i < n)
		return ((s1[i] != '\0') ? s1[i] : -s2[i]);
	return (0);
}
