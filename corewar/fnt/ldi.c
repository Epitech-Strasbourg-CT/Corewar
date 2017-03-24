/*
** ld.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar/fnt
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 16:12:48 2017 Nicolas Polomack
** Last update Fri Mar 24 13:39:26 2017 Arthur Knoepflin
*/

#include "corewar.h"

void	ldi(t_game *g, t_heads *h, t_ins *in)
{
  int	pos;

  if (in->type[0] == 1)
    pos = h->reg[in->val[0] - 1];
  else
    pos = in->val[0] + ((in->type[0] == 3) ? h->pos : 0);
  pos = extract_val(g->arena + pos, IND_SIZE);
  if (in->type[1] == 1)
    pos += h->reg[in->val[1] - 1];
  else
    pos += in->val[1];
  printf("%d\n", extract_val(g->arena + pos, REG_SIZE));
  h->reg[in->val[2] - 1] = extract_val(g->arena + pos, REG_SIZE);
}
