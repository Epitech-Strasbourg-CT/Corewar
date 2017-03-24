/*
** sti.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 17:02:39 2017 Nicolas Polomack
** Last update Fri Mar 24 19:20:01 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "my.h"

void	sti(t_game *g, t_heads *h, t_ins *in)
{
  int	val;
  int	pos;

  val = h->reg[in->val[0] - 1];
  if (in->type[1] == 1)
    pos = h->reg[in->val[1] - 1];
  else
    pos = in->val[1] + ((in->type[1] == 3) ? h->pos : 0);
  if (in->type[2] == 1)
    pos += h->reg[in->val[2] - 1];
  else
    pos += in->val[2] + ((in->type[2] == 3) ? h->pos : 0);
  swap_endian(&val, sizeof(int));
  my_strncpy(g->arena + pos, (char *)&val, sizeof(int));
  h->carry = !!val;
}
