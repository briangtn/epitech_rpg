##
## EPITECH PROJECT, 2017
## Make file libmy
## File description:
## libmy make file
##
SRC_DIR		=	$(realpath ./src)

SRC_FILES	=	my_convert_base.c \
			my_int_to_str.c \
			my_find_prime_sup.c \
			my_getnbr_base.c \
			my_getnbr.c \
			my_isneg.c \
			my_pow.c \
			my_printf.c \
			my_is_prime.c \
			my_putchar.c \
			my_putnbr_base.c \
			my_put_nbr.c \
			my_putstr.c \
			my_revstr.c \
			my_showmem.c \
			my_showstr.c \
			my_show_word_array.c \
			my_sort_int_array.c \
			my_sqrt.c \
			my_strcapitalize.c \
			my_strcat.c \
			my_strcmp.c \
			my_strcpy.c \
			my_strdup.c \
			my_str_isalpha.c \
			my_str_islower.c \
			my_str_isnum.c \
			my_str_isprintable.c \
			my_str_isupper.c \
			my_strlen.c \
			my_strlowcase.c \
			my_strncat.c \
			my_strncmp.c \
			my_strncpy.c \
			my_strstr.c \
			my_str_to_word_array.c \
			my_strupcase.c \
			my_swap.c \
			printf_funcs/chars.c \
			printf_funcs/display_funcs.c \
			printf_funcs/numbers.c \
			printf_funcs/unsigned_int.c \
			printf_funcs/flags.c \
			printf_funcs/precision.c \
			printf_funcs/run_options.c \
			printf_funcs/constants.c \
			printf_funcs/str_contains.c \
			get_next_line.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	libmy.a

INCLUDE		=	-I include

CFLAGS		=	-Wall -Wextra
CFLAGS		+=	$(INCLUDE)

CC		=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) -rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
