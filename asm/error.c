/*
** error.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar  9 20:00:51 2017 Nicolas Polomack
** Last update Fri Mar 10 18:09:53 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include "my_printf.h"

void	error_header(int i, int j, int k)
{
  my_printf("ERROR:%d:%d: Two %s defined.\n", i, j,
            (k) ? "names" : "comments");
  exit(84);
}
