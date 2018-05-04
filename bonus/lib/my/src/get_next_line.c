/*
** EPITECH PROJECT, 2017
** get_next_line_2017
** File description:
** get_next_line functions
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_limit_strlen(char *str, char end)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len] != '\0' && str[len] != end)
		len++;
	return (len);
}

int my_strdupcat(char **dest, char *src)
{
	int dest_len = my_limit_strlen(*dest, '\0');
	int src_len = my_limit_strlen(src, '\0');
	char *new_str = malloc(sizeof(*new_str) * (dest_len + src_len + 1));
	int i = 0;
	int j = 0;

	if (new_str == NULL || dest == NULL || *dest == NULL || src == NULL) {
		if (new_str)
			free(new_str);
		return (84);
	}
	for (; i < dest_len; i++)
		new_str[i] = (*dest)[i];
	for (j = 0; j < src_len; j++)
		new_str[i + j] = src[j];
	new_str[i + j] = '\0';
	free(*dest);
	*dest = new_str;
	return (0);
}

int my_read(char **dest, int fd)
{
	int char_read = 0;
	int total_read = 0;
	char *buffer = malloc(sizeof(*buffer) * (READ_SIZE + 1));

	if (buffer == NULL || dest == NULL || *dest == NULL)
		return (-1);
	char_read = read(fd, buffer, READ_SIZE);
	while (char_read) {
		if (char_read == -1)
			return (-1);
		buffer[char_read] = '\0';
		total_read += char_read;
		my_strdupcat(dest, buffer);
		if (my_limit_strlen(buffer, '\n') < my_limit_strlen(buffer, 0))
			break;
		char_read = read(fd, buffer, READ_SIZE);
	}
	free(buffer);
	return (total_read);
}

char *extract_result(char *buffer)
{
	int line_size = my_limit_strlen(buffer, '\n');
	int buffer_size = my_limit_strlen(buffer, '\0');
	char *result = malloc(sizeof(*result) * (line_size + 1));
	int i = 0;
	int j = 0;

	if (buffer == NULL || result == NULL || buffer[0] == '\0') {
		if (result)
			free(result);
		return (NULL);
	}
	for (i = 0; i <= line_size; i++)
		result[i] = buffer[i];
	for (j = 0; j < buffer_size - line_size; j++)
		buffer[j] = buffer[i + j];
	buffer[j] = '\0';
	result[line_size] = '\0';
	return (result);
}

char *get_next_line(int fd)
{
	int char_read = 0;
	static char *line = NULL;
	char *result = NULL;

	if (line == NULL) {
		line = malloc(sizeof(*line) * 1);
		line[0] = '\0';
	}
	if (fd < 0 || line == NULL) {
		if (line)
			free(line);
		return (NULL);
	}
	char_read = my_read(&line, fd);
	result = extract_result(line);
	if (char_read == -1 || result == NULL) {
		free(line);
		line = NULL;
	}
	return (result);
}