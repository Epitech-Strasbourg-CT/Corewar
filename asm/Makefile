##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Wed Mar  1 17:33:47 2017 Nicolas Polomack
##

SRC	=	main.c		\
		file.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

LIB_F	=	./lib/

LIB	=	-lmy -lmyprintf -lgnl

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE)

all:		$(NAME)

$(NAME):	$(OBJ)
		@echo -n "Compilation GNL... "
		@make -sC lib/GNL
		@echo "OK"
		@echo -n "Compilation libmy... "
		@make -sC lib/my
		@echo "OK"
		@echo -n "Compilation my_printf... "
		@make -sC lib/my_printf
		@echo "OK"
		gcc -o $(NAME) $(OBJ) -L$(LIB_F) $(LIB)

clean:
		@make -sC lib/GNL fclean
		@make -sC lib/my fclean
		@make -sC lib/my_printf fclean
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
