##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## makefile
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	main.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	my_rpg

INCLUDE		=	-I include

CFLAGS		=	-Wall -Wextra
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -lmy				\
			-L $(LIB_DIR)mysfml -lmysfml

CC		=	gcc

all:		$(NAME)

$(NAME):	make_libs $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS)

make_libs:
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) -C $(LIB_DIR)mysfml

clean:
		$(RM) $(OBJ)
		$(MAKE) clean -C $(LIB_DIR)my
		$(MAKE) clean -C $(LIB_DIR)mysfml

fclean:		clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIB_DIR)my
		$(MAKE) fclean -C $(LIB_DIR)mysfml

re:		fclean all

debug:		CFLAGS += -g
debug:		re