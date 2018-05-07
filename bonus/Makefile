##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## makefile
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	main.c

SRC_SCENES_DIR	=	$(realpath src/scenes)

SRC_SCENES_FILES=	scene_editor.c

SRC_PREFABS_DIR	=	$(realpath src/prefabs)

SRC_PREFABS_FILES	=	prefab_grid.c		\
				prefab_map_tile.c	\
				prefab_tileset.c	\

SRC_COMPONENTS_DIR	=	$(realpath src/components)

SRC_COMPONENTS_FILES	=	grid_component.c	\
				map_tile_component.c	\
				tileset_component.c	\
				tileset_updater.c	\

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))\
			$(addprefix $(SRC_SCENES_DIR)/, $(SRC_SCENES_FILES))\
			$(addprefix $(SRC_PREFABS_DIR)/, $(SRC_PREFABS_FILES))\
			$(addprefix $(SRC_COMPONENTS_DIR)/, $(SRC_COMPONENTS_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	my_editor

INCLUDE		=	-I include -I lib/my/include -I lib/mysfml/include

CFLAGS		=	-Wall -Wextra -Wno-unknown-pragmas
CFLAGS		+=	$(INCLUDE)

LIB_DIR		=	lib/

LIB_FLAGS	=	-L $(LIB_DIR)my -lmy				\
			-L $(LIB_DIR)mysfml -lmysfml			\
			-lm						\
			-lc_graph_prog

CC		=	gcc

all:		$(NAME)

$(NAME):	make_libs $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS)

make_libs:
		$(MAKE) -C $(LIB_DIR)my
		$(MAKE) -C $(LIB_DIR)mysfml

make_libs_debug:
		$(MAKE) debug -C $(LIB_DIR)my
		$(MAKE) debug -C $(LIB_DIR)mysfml

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
debug:		fclean make_libs_debug $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS)
