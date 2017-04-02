/*
** live.c for live in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Mar 22 23:16:12 2017 Arthur Knoepflin
** Last update Fri Mar 31 21:13:04 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

void	live(t_game *g, t_heads *h, t_ins *ins)
{
  char	*msg;

  if (ins->val[0] >= 1 && ins->val[0] <= 4)
    {
      if ((msg = malloc(sizeof(char) * (24))) != NULL)
	{
	  msg[23] = '\0';
	  my_strcpy(msg, "Le joueur ");
	  msg[10] = h->id + '0';
	  my_strcpy(msg + 11, " est en vie\n");
	  my_put_list_live(&g->msg, msg);
	}
      g->live[ins->val[0] - 1] += 1;
    }
}
