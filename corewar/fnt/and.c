/*
** and.c for and.c in /home/Maxime/delivery/CPE/CPE_2016_corewar/corewar/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Thu Mar 23 17:47:29 2017 Maxime Jenny
** Last update Fri Mar 24 13:27:45 2017 Nicolas Polomack
*/

#include "corewar.h"

void	and(t_game *g, t_heads *h, t_ins *in)
{
  int	i;
  int	j;

  i = in->val[0] + (in->type[0] == 2) ? (0) : (h->pos);
  if (in->type[0] == 1)
    i = h->reg[in->val[0] - 1];
  j = in->val[1] + (in->type[1] == 2) ? (0) : (h->pos);
  if (in->type[1] == 1)
    j = h->reg[in->val[1] - 1];
  h->reg[in->val[2] - 1] = i & j;
  h->carry = h->carry ? 0 : 1;
}
