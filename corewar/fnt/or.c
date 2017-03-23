/*
** or.c for or in /home/Maxime/delivery/CPE/CPE_2016_corewar/corewar/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Thu Mar 23 17:55:09 2017 Maxime Jenny
** Last update Thu Mar 23 17:58:10 2017 Maxime Jenny
*/

#include "corewar.h"

void	or(t_game *g, t_heads *h, t_ins *in)
{
  int	i;
  int	j;

  i = in->val[0] + (in->type[0] == 2) ? (0) : (h->pos);
  if (in->type[0] == 1)
    {
      i = h->reg[in->val[0]];
    }
  j = in->val[1] + (in->type[1] == 2) ? (0) : (h->pos);
  if (in->type[1] == 1)
    {
      j = h->reg[in->val[1]];
    }
  h->reg[in->val[2]] = i | j;
  (h->carry == 1) ? (h->carry = 0) : (h->carry = 1);
}
