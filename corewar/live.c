/*
** live.c for live in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Mar 21 21:20:58 2017 Arthur Knoepflin
** Last update Tue Mar 28 21:14:00 2017 Arthur Knoepflin
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
    if (g->live[i] > 0)
      {
	sum += g->live[i];
      }
  if (sum >= NBR_LIVE + g->old_check)
    {
      g->cycle_to_die -= CYCLE_DELTA;
      g->old_check += 40;
    }
}

static void	print_dead(int id, char *name)
{
  my_putstr("The player ");
  my_put_nbr(id);
  my_putstr("(");
  my_putstr(name);
  my_putstr(") is dead\n");
}

int		nb_player_alive(t_game *g)
{
  char		tmp_live[4];
  int		i;
  int		ret;
  t_heads	*tmp;

  tmp = g->heads;
  my_memset(tmp_live, 0, 4);
  tmp_live[0] = 0;
  tmp_live[1] = 0;
  tmp_live[2] = 0;
  tmp_live[3] = 0;
  while (tmp)
    {
      if (tmp->id >= 1 && tmp->id <= 4)
	tmp_live[tmp->id - 1] = 1;
      tmp = tmp->next;
    }
  i = -1;
  ret = 0;
  while (++i < 4)
    if (tmp_live[i])
      ret += 1;
  return (ret);
}

int	check_live(t_game *g, int *stop)
{
  int	i;

  if (g->cycle >= g->old_cycle_verrif + g->cycle_to_die)
    {
      printf("CHECK_LIVE");
      g->cycle_to_die -= CYCLE_DELTA;
      g->old_cycle_verrif = g->cycle;
      i = -1;
      while (++i < g->parse->nb_champ)
	if (g->live[g->parse->champ[i]->id - 1] == 0)
	  {
	    print_dead(g->parse->champ[i]->id, g->parse->champ[i]->name);
	    while (g->read && g->read->id == g->parse->champ[i]->id)
	      g->read = g->read->next;
	    kill_player(g, g->parse->champ[i]->id);
	    g->live[g->parse->champ[i]->id - 1] = -2;
	  }
	else if (g->live[g->parse->champ[i]->id - 1] != -2)
	  g->live[g->parse->champ[i]->id - 1] = 0;
    }
  if (nb_player_alive(g) <= 1)
    *stop = 1;
}
