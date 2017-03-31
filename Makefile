##
## Makefile for corewar in /home/nicolaspolomack/cpe/2/CPE_2016_corewar
## 
## Made by Nicolas Polomack
## Login   <nicolas.polomack@epitech.eu>
## 
## Started on  Mon Mar 20 00:00:28 2017 Nicolas Polomack
## Last update Fri Mar 31 20:46:00 2017 Arthur Knoepflin
##

MAKE		=	make -C asm --no-print-directory

MAKE_COR	=	make -C corewar --no-print-directory

NAME		=	asm/asm

all:	$(NAME)

$(NAME):
	@$(MAKE)

clean:
	@$(MAKE) clean

fclean:
	@$(MAKE) fclean

re:
	@$(MAKE) re
