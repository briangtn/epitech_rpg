/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** reproduce the behaviour of strstr func
*/

static int found_str(char const *str, char const *to_find, int test_at);

char *my_strstr(char *str, char const *to_find)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (found_str(str, to_find, i))
			return (&str[i]);
	}
	return (0);
}

int found_str(char const *str, char const *to_find, int test_at)
{
	for (int i = 0; to_find[i] != '\0'; i++) {
		if (str[test_at + i] != to_find[i])
			return (0);
	}
	return (1);
}
