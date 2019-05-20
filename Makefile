##
## EPITECH PROJECT, 2018
## Makefile Marius
## File description:
## Makefile Marius
##

RM		=	rm -r -f

NAME	=	my_rpg

SRC		=	src/alloc/alloc.c						\
			src/audio/audio.c 						\
			src/combat/attack.c						\
			src/combat/combat_nature.c				\
			src/combat/combat_nature_2.c			\
			src/combat/combat_nature_3.c			\
			src/combat/combat_nature_4.c			\
			src/combat/combat_nature_5.c			\
			src/combat/set_combat.c					\
			src/destroy/destroy.c					\
			src/event/event_combat.c				\
			src/event/event.c 						\
			src/event/event_optional.c				\
			src/event/events_option.c				\
			src/event/event_combat_2.c 				\
			src/event/event_combat_3.c 				\
			src/event/event_2.c 					\
			src/event/move_sache.c 					\
			src/event/event_key_code.c 				\
			src/event/up_move_2.c 					\
			src/event/up_move_2_2.c 				\
			src/event/up_move_2_3.c 				\
			src/event/left_move_2.c 				\
			src/event/right_move_2.c 				\
			src/event/down_move_2.c 				\
			src/event/key_e_move.c 					\
			src/event/event_inventory.c				\
			src/game_play/game.c 					\
			src/game_play/game_2.c 					\
			src/game_play/game_3.c 					\
			src/game_play/game_4.c 					\
			src/game_play/game_5.c 					\
			src/game_play/game_6.c 					\
			src/game_play/fight_npc_func.c 			\
			src/game_play/fight_npc_func_2.c 		\
			src/game_play/fight_npc_func_3.c 		\
			src/game_play/inventory.c 				\
			src/game_play/bag.c						\
			src/game_play/bag_2.c					\
			src/help/help.c 						\
			src/init_variable/init_game_base.c		\
			src/init_variable/init_game_base_2.c	\
			src/init_variable/init_2.c 				\
			src/init_variable/init_inventory.c		\
			src/init_variable/init.c 				\
			src/init_variable/init_text.c			\
			src/init_variable/init_sac.c			\
			src/intro/intro.c 						\
			src/intro/menu_intro.c					\
			src/options/create_rand.c				\
			src/options/get_info.c					\
			src/options/rect.c						\
			src/options/print_text.c				\
			src/options/resize.c					\
			src/options/options.c 					\
			src/options/utils.c 					\
			src/options/poke.c	 					\
			src/loop.c 								\
			src/main.c


OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -I./include

LDFLAGS	=	-Llib/my -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

$(NAME):	$(OBJ)
			make -C ./lib/my
			gcc -o $(NAME) $(OBJ) $(LDFLAGS)
			rm -rf *.o
			rm -rf */*.o
			rm -rf */*/*.o
			$(RM) ./lib/my/*.a

debug:		CFLAGS += -g
debug:		re

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			make -C ./lib/my fclean
			$(RM) $(NAME)
			$(RM) *~
			$(RM) ./lib/my/*.a

re:			fclean all
