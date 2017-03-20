##
## Makefile for CPool_Day10 in /home/cedric/delivery/CPool_Day10/lib/my
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Fri Oct 14 09:33:10 2016 Cédric Thomas
## Last update Sat Mar 18 17:04:30 2017 Nicolas Polomack
##

SRC	=	get_next_line.c

OBJ	=	$(SRC:.c=.o)

INCLUDE =	get_next_line.h

NAME	=	libgnl.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp get_next_line.h ../../include
	cp $(NAME) ..
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
