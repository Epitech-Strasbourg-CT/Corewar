/*
** live.c for live in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Mar 21 21:20:58 2017 Arthur Knoepflin
** Last update Thu Mar 23 11:34:12 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

int	init_live(t_game *g)
{
  int	i;

  if ((g->live = malloc(sizeof(int) * (4 + 1))) == NULL)
    return (1);
  g->live[0] = -2;
  g->live[1] = -2;
  g->live[2] = -2;
  g->live[3] = -2;
  g->live[4] = -1;
  i = -1;
  while (++i < g->parse->nb_champ)
    g->live[g->parse->champ[i]->id - 1] = 0;
  return (0);
}

void	update_live(t_game *g)
{
  int	i;
  int	sum;

  i = -1;
  sum = 0;
  while (++i < 4)
    if (g->live[i] >= 0)
      sum += g->live[i];
  if (sum >= NBR_LIVE)
    g->cycle_to_die -= CYCLE_DELTA;
}

int	check_live(t_game *g, int *stop)
{
  int	i;

  if (g->cycle >= g->old_cycle_verrif + g->cycle_to_die)
    {
      g->old_cycle_verrif = g->cycle;
      i = -1;
      while (++i < g->parse->nb_champ)
	{
	  if (g->live[g->parse->champ[i]->id - 1] == 0)
	    {
	      printf("The player %d(%s) is dead\n", g->parse->champ[i]->id, g->parse->champ[i]->name);
	      /* KILL PLAYER */
	      g->live[g->parse->champ[i]->id - 1] = -2;
	    }
	  else
	    g->live[g->parse->champ[i]->id - 1] = 0;
	}
    }
}
