/*
** EPITECH PROJECT, 2017
** CPE_get_next_line_2017
** File description:
** Return the next line of a fd
*/

#ifndef __GET_NEXT_LINE_H_
#define __GET_NEXT_LINE_H_

char *get_next_line(int fd);

int my_limit_strlen(char *str, char end);
int my_strdupcat(char **dest, char *src);
int my_read(char **dest, int fd);
char *extract_result(char *buffer);

#endif /* !__GET_NEXT_LINE_H_ */

#ifndef READ_SIZE
#define READ_SIZE 10
#endif /* !READ_SIZE */