/*
** exec_head.c for exec_head in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Mar 22 22:22:03 2017 Arthur Knoepflin
** Last update Thu Mar 23 10:20:05 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"

void	exec_head(t_game *g,
		  t_heads *head,
		  int *stop,
		  void (*fnt[16])(t_game *, t_heads *, t_ins *))
{
  t_ins	*ins;

  if ((ins = get_instruc(g, head->pos)) == NULL)
    {
      head->pos += 1;
      return ;
    }
  if (ins->cmd == 1)
    fnt[ins->cmd - 1](g, head, ins);
  head->pos += ins->tot_byte;
  update_live(g);
  check_live(g, stop);
  free(ins);
}
