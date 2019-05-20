##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

RM		=	rm -f -r

NAME	=	libmy.a

CFLAGS	+=	-Wall -Wextra -I./../../include -g

SRC = 	addchar_to_str.c 	\
		my_itoa.c			\
		my_revstr.c			\
		my_str_to_tab.c		\
		my_getfile.c 		\
		my_strlen.c 		\
		my_strcmp.c 		\
		my_putstr.c 		\
		my_atoi.c			\
		my_csfml_lib.c

OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) *~

re:		fclean all
