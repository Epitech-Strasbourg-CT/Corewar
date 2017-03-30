/*
** st.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/corewar
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Thu Mar 23 17:02:39 2017 Nicolas Polomack
** Last update Wed Mar 29 18:01:20 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "my.h"
#include "op.h"

void	st(t_game *g, t_heads *h, t_ins *in)
{
  int	val;
  int	pos;

  val = 0;
  pos = in->val[0] + ((in->type[0] == 3) ? h->pos : 0);
  pos %= MEM_SIZE;
  while (pos < 0)
    pos += MEM_SIZE;
  if (in->type[1] == 1)
    val = h->reg[in->val[1] - 1];
  else if (in->type[1] == 3)
    val = extract_val(g->arena + (h->pos + in->val[1]) % MEM_SIZE,
		      sizeof(int));
  my_strncpy((char *)g->arena + pos, (char *)&val, REG_SIZE);
}
