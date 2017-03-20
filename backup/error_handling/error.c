/*
** error.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar  9 20:00:51 2017 Nicolas Polomack
** Last update Tue Mar 14 15:25:15 2017 
*/

#include <stdlib.h>
#include "my_printf.h"
#include "asm.h"

void	error_header(int i, int j, int k)
{
  my_printf("ERROR:%d:%d: Two %s defined.\n", i, j,
            (k) ? "names" : "comments");
  exit(84);
}

int	error_double_label(t_label **my_label, char *name)
{
  my_printf("ERROR: two labels (or more) have the name value: '%s'\n", name);
  my_free_label(my_label);
  exit(84);
}
