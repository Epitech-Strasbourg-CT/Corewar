/*
** fork.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 18:25:52 2017 Nicolas Polomack
** Last update Thu Mar 23 23:35:43 2017 Arthur Knoepflin
*/

#include "corewar.h"

void		lfork(t_game *g, t_heads *h, t_ins *in)
{
  int		i;
  t_heads	head;

  i = -1;
  head.id = h->id;
  head.pos = h->pos + in->val[0];
  while (++i < 16)
    head.reg[i] = h->reg[i];
  head.ctn_cycle = 0;
  head.carry = 0;
  new_head(head, &h);
}
