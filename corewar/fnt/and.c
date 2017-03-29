/*
** and.c for and.c in /home/Maxime/delivery/CPE/CPE_2016_corewar/corewar/
**
** Made by Maxime Jenny
** Login   <maxime.jenny@epitech.eu>
**
** Started on  Thu Mar 23 17:47:29 2017 Maxime Jenny
** Last update Wed Mar 29 17:59:51 2017 Arthur Knoepflin
*/

#include "corewar.h"

static int	get_val(t_game *g, t_heads *h, int mode, int val)
{
  if (mode == 1)
    return (h->reg[val - 1]);
  if (mode == 2)
    return (val);
  if (mode == 3)
    return (extract_val(g->arena + val, sizeof(int)));
  return (0);
}

void	and(t_game *g, t_heads *h, t_ins *in)
{
  int	i;
  int	j;

  i = get_val(g, h, in->type[0], in->val[0]);
  j = get_val(g, h, in->type[1], in->val[1]);
  h->reg[in->val[2] - 1] = i & j;
  h->carry = !h->reg[in->val[2] - 1];
}
