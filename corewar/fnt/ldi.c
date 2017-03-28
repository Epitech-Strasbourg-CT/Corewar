/*
** ld.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar/fnt
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 16:12:48 2017 Nicolas Polomack
** Last update Tue Mar 28 18:04:03 2017 Arthur Knoepflin
*/

#include "corewar.h"

void	ldi(t_game *g, t_heads *h, t_ins *in)
{
  int	pos;

  pos = 0;
  if (in->type[0] == 1)
    pos = h->reg[in->val[0] - 1];
  else if (in->type[0] == 2)
    pos = h->pos + in->val[0];
  else if (in->type[0] == 3)
    pos = in->val[0];
  pos += in->val[1];
  pos %= MEM_SIZE;
  while (pos < 0)
    pos += MEM_SIZE;
  h->reg[in->val[2] - 1] = extract_val(g->arena + (pos % MEM_SIZE), sizeof(int));
  h->carry = !h->reg[in->val[2] - 1];
}
