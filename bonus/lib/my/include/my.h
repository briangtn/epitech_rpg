/*
** EPITECH PROJECT, 2017
** libmy.a
** File description:
** Header for the my lib
*/

#ifndef __MY__H_
#define __MY__H_

#include <stdlib.h>
#include <stdarg.h>

#define HEXA_BASE_MIN "0123456789abcdef"
#define HEXA_BASE_MAJ "0123456789ABCDEF"

#define UNUSED __attribute__((unused))

#define ABS(value) (value < 0) ? -value : value
#define IS_ALPHA_NUMERICAL(value) ((value >= 'A' && value <= 'Z') || \
(value >= 'a' && value <= 'z') || (value >= '0' && value <= '9')) ? 1 : 0
#define IS_NUM(value) ((value >= '0' && value <= '9') || \
value == '+' || value == '-') ? 1 : 0

void	my_free_array(void **array);
int	my_array_len(void **array);
int	my_str_contains(const char *str, char c);
int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char const *str);
int	my_puterror(char const *error);
int	my_strlen(char const *str);
int	my_getnbr(char const *str);
void	my_sort_int_array(int *tab, int size);
int	my_compute_power_rec(int nb, int power);
int	my_compute_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char const *src);
char	*my_strncpy(char *dest, char const *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char const *to_find);
char	*my_int_to_str(int nb);
int	my_strcmp(char const *s1, char const *s2);
int	my_strncmp(char const *s1, char const *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char const *str);
int	my_str_isnum(char const *str);
int	my_str_islower(char const *str);
int	my_str_isupper(char const *str);
int	my_str_isprintable(char const *str);
int	my_showstr(char const *str);
int	my_showmem(char const *str, int size);
int	my_putnbr_base(int nbr, char const *base);
int	my_getnbr_base(char const *str, char const *base);
char	*my_strcat(char *dest, char const *src);
char	*my_strncat(char *dest, char const *src, int nb);
char	*my_strdup(char const *src);
int	my_show_word_array(char * const *tab);
char	**my_str_to_word_array(char const *str);
char 	**my_parse_str_to_array(const char *str, const char *delim, \
const char *ignore_start, const char *ignore_end);
char	*my_convert_base(char const *nbr, char const *base_from, \
char const *base_to);
char	*get_next_line(int fd);
int	my_strdupcat(char **dest, char *src);
int	match(char const *s1, char const *s2);

int	my_printf(const char *format, ...);
int	display_uint_base(unsigned int nbr, char const *base, int dummy);
int	display_minus_nb_neg(int number);
int	display_int_base(int nbr, char const *base, int dummy);
int	display_long_base(long nbr, char const *base, int dummy);
int	display_str_show(char *str, int dummy);
int	my_putchar_cond(char c, int condition);
int	is_allowed_argument(char arg, const char *ARG_TAB);
int	str_contains(char c, char *str);

int my_printf_u(va_list list, char *options);
int my_printf_x(va_list list, char *options);
int my_printf_xmaj(va_list list, char *options);
int my_printf_o(va_list list, char *options);
int my_printf_b(va_list list, char *options);
int my_printf_i(va_list list, char *options);
int my_printf_d(va_list list, char *options);
int my_printf_p(va_list list, char *options);
int my_printf_c(va_list list, char *options);
int my_printf_s(va_list list, char *options);
int my_printf_smaj(va_list list, char *options);
int my_printf_percent(va_list list, char *options);

int *initialise_stars(int **tab, char *options, va_list list, char end_char);
int option_flag_minus_i(int star, int already_disp, char *options, int nb);
int option_minus_x(int *stars, unsigned int number, char *options);
int option_minus_xmaj(int *stars, unsigned int number, char *options);
int option_minus_o(int *stars, unsigned int number, char *options);
int option_minus_str(char *str, char *options, int star);
int option_minus_show_str(char *str, char *options, int star);
int option_flag_plus(int value);
int option_flag_space(int value);
int option_flag_hash(char *options, char const * to_display);
int hash(char *options, int str_len);
char *option_precision(char *str, int len);
int option_width(char *options, int length, int star_value, char c);

typedef struct printf_arg {
	char type;
	int (*func)(va_list, char *options);
} printf_arg_t;

typedef int (*ptr_function)(va_list, char *options);

const printf_arg_t PRINTF_ARGS[13];

const char ALLOWED_ARGS[30];

const char ALLOWED_FLAGS[6];

const char ALLOWED_WIDTH[11];

const char ALLOWED_PRECISION[12];

const char ALLOWED_TYPES[13];

#endif