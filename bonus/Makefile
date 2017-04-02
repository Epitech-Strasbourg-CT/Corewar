##
## Makefile for Makefile in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
## 
## Made by Arthur Knoepflin
## Login   <arthur@epitech.net>
## 
## Started on  Thu Mar  9 18:45:29 2017 Arthur Knoepflin
## Last update Sun Apr  2 03:17:22 2017 Nicolas Polomack
##

MAKE1	=	make --no-print-directory -sC lib/mycsfml

SRC	=	arena/arena_create.c		\
		arena/average_champ.c		\
		arena/is_overlap.c		\
		arena/load_champ.c		\
		dump.c				\
		list_live.c			\
		fnt_tab.c			\
		fnt/live.c			\
		fnt/st.c			\
		fnt/ld.c			\
		fnt/sti.c			\
		fnt/ldi.c			\
		fnt/and.c			\
		fnt/or.c			\
		fnt/xor.c			\
		fnt/add.c			\
		fnt/sub.c			\
		fnt/aff.c			\
		fnt/zjmp.c			\
		fnt/fork.c			\
		game.c				\
		draw.c				\
		get_name.c			\
		head/exec_head.c		\
		head/head.c			\
		head/init_head.c		\
		head/kill_player.c		\
		instruct/error_desc.c		\
		instruct/get_arg.c		\
		instruct/get_desc.c		\
		instruct/get_instruct.c		\
		live.c				\
		main.c				\
		op.c				\
		endian.c			\
		parse/parse.c			\
		parse/parse_champ.c		\
		parse/parse_error.c		\
		parse/parse_error_2.c		\
		parse/parse_get_list_id.c	\
		parse/parse_file_champ.c	\
		parse/parse_file_header.c	\
		parse/read_file.c		\
		print_dead.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS	+=	-Iinclude -Wall -Wextra -pedantic -Werror -O3

all:		$(NAME)

$(NAME):	.SILENT

.SILENT:	$(OBJ)
		@echo -e "\n\033[32;1mCompile libmy\033[0m"
		@make -sC lib/my --no-print-directory
		@echo -e "\n\033[32;1mCompile libmycsfml\033[0m"
		@$(MAKE1)
		@echo -e "\n\033[32;1mCompile Corewar\033[0m"
		@gcc -o $(NAME) $(OBJ) -lmy -Llib -lmycsfml -O3 -Llib/mycsfml -lm -lc_graph_prog
		@echo -e "\n\n\033[34;1m---====== Ready for Battle ======---\033[0m\n"

clean:
		@make -sC lib/my clean
		@$(MAKE1) clean
		@rm -rf $(OBJ)

fclean:		clean
		@make -sC lib/my fclean
		@$(MAKE1) fclean
		@rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

%.o:		%.c
		@echo -e "\033[32;1mCompile\033[0m $< \033[33;1m=>\033[0m $@"
		gcc -c $(CFLAGS) -o $@ $<
