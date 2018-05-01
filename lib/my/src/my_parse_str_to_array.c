/*
** EPITECH PROJECT, 2017
** my
** File description:
** Parse an str to an array
*/

/* File created the 19/03/2018 at 10:41:05 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

static int get_final_tab_size(const char *str, const char *cut, \
const char *start, const char *end)
{
	bool word = false;
	int sequence = 0;
	int size = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '\\' && str[i + 1] != '\0')
			i += 2;
		if (!sequence && !word && !my_str_contains(cut, str[i]) && \
!my_str_contains(start, str[i]) && !my_str_contains(end, str[i])) {
			word = true;
			size += 1;
		} else if (!sequence && word && my_str_contains(cut, str[i]))
			word = false;
		if (!sequence && my_str_contains(start, str[i])) {
			sequence = my_str_contains(start, str[i]);
			size += (!word) ? 1 : 0;
			word = true;
		} else if (sequence && str[i] == end[sequence - 1])
			sequence = 0;
	}
	return (size);
}

static int get_arg_size(const char *str, int start_index, \
const char *cut, const char **ignore)
{
	bool word = false;
	int sequence = 0;
	int i = 0;

	for (i = start_index; str[i]; i++) {
		if (str[i] == '\\' && str[i + 1] != '\0')
			i += 2;
		if (!sequence && !word && !my_str_contains(cut, str[i]) && \
!my_str_contains(ignore[0], str[i]) && !my_str_contains(ignore[1], str[i])) {
			word = true;
		} else if (!sequence && word && my_str_contains(cut, str[i]))
			break;
		if (!sequence && my_str_contains(ignore[0], str[i])) {
			sequence = my_str_contains(ignore[0], str[i]);
			word = true;
		} else if (sequence && str[i] == ignore[1][sequence - 1])
			sequence = 0;
	}
	return (i - start_index);
}

static char *parse_arg(const char *str, const char **ignore, \
int size, int start_index)
{
	int j = 0;
	char *result = NULL;
	char delim = -1;

	if (size == 0)
		return (NULL);
	result = malloc(sizeof(*result) * (size + 1));
	for (int i = start_index; result && i - start_index < size; i++) {
		if (str[i] == '\\')
			i++;
		else if ((delim == -1 && my_str_contains(ignore[0], str[i])) ||\
(my_str_contains(ignore[1], str[i]) == delim)) {
			delim = my_str_contains(ignore[0], str[i]);
			delim = (!delim) ? -1 : delim;
			continue;
		}
		result[j++] = str[i];
		result[j] = '\0';
	}
	return (result);
}

static int fill_tab(char **tab, const char *str, const char *cut, \
const char **ignore)
{
	int word_size = 0;
	int word = 0;

	for (int i = 0; str[i]; i += (str[i] == '\0') ? 0 : 1) {
		if (!my_str_contains(cut, str[i])) {
			word_size = get_arg_size(str, i, cut, ignore);
			tab[word] = parse_arg(str, ignore, word_size, i);
			word++;
			i += word_size;
		}
	}
	return (0);
}

char **my_parse_str_to_array(const char *str, const char *delim, \
const char *ignore_start, const char *ignore_end)
{
	char **tab = NULL;
	const char *ignore[2] = {ignore_start, ignore_end};
	int nb_args = 0;

	if (str == NULL || delim == NULL || ignore_start == NULL || \
ignore_end == NULL || my_strlen(ignore_start) != my_strlen(ignore_end))
		return (NULL);
	nb_args = get_final_tab_size(str, delim, ignore_start, ignore_end);
	tab = malloc(sizeof(*tab) * (nb_args + 1));
	if (tab == NULL)
		return (NULL);
	tab[nb_args] = NULL;
	if (fill_tab(tab, str, delim, ignore)) {
		free(tab);
		return (NULL);
	}
	return (tab);
}