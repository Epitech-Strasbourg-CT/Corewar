/*
** ld.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar/fnt
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 16:12:48 2017 Nicolas Polomack
** Last update Thu Mar 23 17:11:34 2017 Nicolas Polomack
*/

#include "corewar.h"

void	ld(t_game *g, t_heads *h, t_ins *in)
{
  int	pos;

  pos = in->val[0] + ((in->type[0] == 2) ? h->pos : 0);
  h->reg[in->val[1]] = extract_val(g->arena + pos, 4);
}
