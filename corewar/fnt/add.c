/*
** add.h for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 18:11:31 2017 Nicolas Polomack
** Last update Thu Mar 23 18:16:50 2017 Nicolas Polomack
*/

#include "corewar.h"
#include "my.h"

void	add(t_game *g, t_heads *h, t_ins *in)
{
  my_putchar(h->reg[in->val[0]]);
  my_putchar(10);
}

