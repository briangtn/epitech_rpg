##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## makefile
##

SRC_DIR		=	$(realpath src)

SRC_FILES	=	main.c						\
			global.c

SRC_SCENES_DIR	=	$(realpath src/scenes)

SRC_SCENES_FILES=	scene_game.c					\
			scene_game_player.c				\
			scene_game_load_scene.c				\
			scene_fight.c					\
			fight/fight.c					\
			fight/fight_messages.c				\
			fight/end_fight.c				\
			fight/fights_ids.c				\
			fight/fight_callback.c				\
			scene_menu.c					\
			scene_menu_buttons.c				\
			scene_pause.c					\
			scene_speak.c					\
			scene_end.c					\
			scene_intro.c					\
			scene_help.c

SRC_COMP_DIR	=	$(realpath src/custom_component)

SRC_COMP_FILES	=	interaction/component_interaction_core.c	\
			npc/component_npc.c				\
			fight/fight_arrow_component.c			\
			fight/fight_arrow_updaters.c			\
			fight/fight_attack_menu_component.c		\
			fight/enemy_component.c				\
			fight/player_component.c			\
			fight/logs.c					\
			interaction/interact.c				\
			ui/load_bar_component.c				\
			speak/component_speak_core.c			\
			speak/speak_update.c				\
			speak/end_speak_func.c				\
			tiles/tile_effect_component.c			\
			inventory/component_inventory.c			\
			inventory/component_inventory_toggle.c		\
			inventory/component_inventory_itemmanagement.c	\

SRC_PREFAB_DIR	=	$(realpath src/prefabs)

SRC_PREFAB_FILES=	player/prefab_player_core.c		\
			player/behaviour_player_movement.c	\
			player/behaviour_player_inventory.c	\
			fight/prefab_fight_background.c		\
			fight/prefab_fight_player.c		\
			fight/prefab_fight_enemy.c		\
			fight/prefab_fight_arrow.c		\
			fight/prefab_fight_attacks_menu.c	\
			fight/prefab_fight_mana_text.c		\
			fight/fight_text_prefab.c		\
			fight/prefab_logs.c			\
			fight/prefab_log_message.c		\
			npc/npc_interaction.c			\
			npc/prefab_npc_core.c			\
			tiles/prefab_tile_core.c		\
			tiles/tile_teleport.c			\
			tiles/tile_particles.c			\
			tiles/tile_fight.c			\
			ui/loadbar_prefab.c			\
			ui/loadbar_back_prefab.c		\

SRC_UTILS_DIR	=	$(realpath src/utils)

SRC_UTILS_FILES	=	fight_utils.c				\
			keyboard_utils.c			\
			fight_creator_utils.c			\
			linked_list_utils.c

SRC_PAUSE_DIR	=	$(realpath src/pause)

SRC_PAUSE_FILES	=	pause.c

SRC_PARSING_DIR	=	$(realpath src/parsing)

SRC_PARSING_FILES=	free_game_info.c			\
			parser_to_game.c			\
			parsing.c				\
			scene_parsing.c				\
			struct_init.c				\
			tile_parsing.c				\
			npc_loot_parsing.c			\
			check.c					\
			get_event.c

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
			$(addprefix $(SRC_SCENES_DIR)/, $(SRC_SCENES_FILES)) \
			$(addprefix $(SRC_PREFAB_DIR)/, $(SRC_PREFAB_FILES)) \
			$(addprefix $(SRC_UTILS_DIR)/, 	$(SRC_UTILS_FILES)) \
			$(addprefix $(SRC_COMP_DIR)/, $(SRC_COMP_FILES)) \
			$(addprefix $(SRC_PARSING_DIR)/, $(SRC_PARSING_FILES)) \
			$(addprefix $(SRC_PAUSE_DIR)/, $(SRC_PAUSE_FILES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	my_rpg

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