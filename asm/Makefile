##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Sat Apr  1 02:13:25 2017 Nicolas Polomack
##

SRC	=	main.c				\
		op.c				\
		error_handling/error.c		\
		header/header.c			\
		instruct/parse.c		\
		instruct/misc.c			\
		instruct/write_instruct.c	\
		instruct/list_instruct.c	\
		label/label.c			\
		label/size.c			\
		label/list_label.c		\
		misc/file.c			\
		misc/str.c			\
		misc/print.c			\
		misc/tab.c			\
		misc/epurstr.c			\
		misc/bitshift.c			\
		misc/my_int_to_char.c		\
		misc/endian.c			\
		write/standard.c		\
		write/mod.c			\
		write/write.c


OBJ	=	$(SRC:.c=.o)

NAME	=	asm

LIB_F	=	./lib/

LIB	=	-lmy -lmyprintf -lgnl

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -Wall -Wextra

GREEN	=	\033[32;1m

YELLOW	=	\033[33;1m

BLUE	=	\033[34;1m

RES	=	\033[0m

all:		$(NAME)

$(NAME):	.SILENT

.SILENT:	$(OBJ)
		@echo
		@echo -en "$(GREEN)Compile$(RES) GNL...\t\t"
		@make -sC lib/GNL
		@echo -e "$(GREEN)OK$(RES)"
		@echo -en "$(GREEN)Compile$(RES) libmy...\t"
		@make -sC lib/my
		@echo -e "$(GREEN)OK$(RES)"
		@echo -en "$(GREEN)Compile$(RES) my_printf...\t"
		@make -sC lib/my_printf
		@echo -e "$(GREEN)OK$(RES)"
		@echo -en "$(GREEN)Linking$(RES) ASM compiler...\t"
		@gcc -o $(NAME) $(OBJ) -L$(LIB_F) $(LIB)
		@echo -e "$(GREEN)OK$(RES)"
		@echo
		@echo -e "$(BLUE)---====== READY TO BATTLE ======---$(RES)"
		@echo

clean:
		@make -sC lib/GNL clean
		@make -sC lib/my clean
		@make -sC lib/my_printf clean
		@rm -f $(OBJ)

fclean:		clean
		@make -sC lib/GNL fclean
		@make -sC lib/my fclean
		@make -sC lib/my_printf fclean
		@rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re

%.o:	%.c
	@echo -en "$(GREEN)Compile$(RES) $@"
	@gcc -c $(CFLAGS) -o $@ $<
	@echo -e " $(YELLOW)=>$(RES) $<"
