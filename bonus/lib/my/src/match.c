/*
** EPITECH PROJECT, 2017
** CPool_match-nmatch_2017
** File description:
** find out if two strings match
*/

#include "my.h"

static void flag_star(char const *s2, int pos_in_s2, int *last_star);
static int find_next_char(char const *str, char c, int to_add);
static int get_pos(char const *s1, char const *s2, int last_star, int pos_s1);

int match(char const *s1, char const *s2)
{
	int last_star_pos = -1;
	int pos_in_s1 = 0;
	int pos_in_s2 = 0;

	while (pos_in_s2 <= my_strlen(s2) && pos_in_s1 <= my_strlen(s1)) {
		flag_star(s2, pos_in_s2, &last_star_pos);
		if (s1[pos_in_s1] != s2[pos_in_s2]) {
			pos_in_s1 = get_pos(s1, s2, last_star_pos, pos_in_s1);
			pos_in_s2 = last_star_pos + 1;
		}
		if (pos_in_s1 == -1)
			return (0);
		if (s1[pos_in_s1] == '\0' && s2[pos_in_s2] == '\0')
			return (1);
		pos_in_s1++;
		pos_in_s2++;
	}
	return (0);
}

int get_pos(char const *s1, char const *s2, int last_star, int pos_s1)
{
	if (last_star != -1)
		return (find_next_char(&s1[pos_s1], s2[last_star + 1], pos_s1));
	else
		return (-1);

}

void flag_star(char const *s2, int pos_in_s2, int *last_star)
{
	for (int i = 0; s2[pos_in_s2 + i] == '*'; i++)
		*last_star = pos_in_s2 + i;
}

int find_next_char(char const *str, char c, int to_add)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			return (i + to_add);
	}
	if (str[i] == c)
		return (i + to_add);
	return (-1);
}