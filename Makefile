##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC	=	./c/main.c			\
		./c/events.c			\
		./c/value.c			\
		./c/create_close_destroy.c	\
		./c/start_end.c			\

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I./include -l csfml-window -l csfml-graphics -l csfml-audio -l csfml-system

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
