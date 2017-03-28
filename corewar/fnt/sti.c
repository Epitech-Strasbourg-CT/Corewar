/*
** sti.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 17:02:39 2017 Nicolas Polomack
** Last update Tue Mar 28 17:54:15 2017 Arthur Knoepflin
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
    pos = in->val[1] + ((in->type[1] == 2) ? h->pos : 0);
  if (in->type[2] == 1)
    pos += h->reg[in->val[2] - 1];
  else if (in->type[2] == 2)
    pos += in->val[2];
  swap_endian(&val, sizeof(int));
  pos %= MEM_SIZE;
  while (pos < 0)
    pos += MEM_SIZE;
  my_strncpy((char *)g->arena + pos, (char *)&val, sizeof(int));
  h->carry = !val;
}
