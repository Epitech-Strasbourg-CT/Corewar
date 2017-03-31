/*
** ld.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar/fnt
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 16:12:48 2017 Nicolas Polomack
** Last update Fri Mar 31 22:02:24 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "op.h"

void	ld(t_game *g, t_heads *h, t_ins *in)
{
  int	pos;

  if (in->type[0] == 2)
    h->reg[in->val[1] - 1] = in->val[0];
  else
    {
      pos = in->val[0] + ((in->type[0] == 3) ? h->pos : 0);
      pos %= MEM_SIZE;
      while (pos < 0)
	pos += MEM_SIZE;
      h->reg[in->val[1] - 1] = extract_val(g->arena + pos, REG_SIZE);
    }
}
