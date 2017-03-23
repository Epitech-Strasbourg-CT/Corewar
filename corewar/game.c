/*
** game.c for game in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 12:53:10 2017 Arthur Knoepflin
** Last update Thu Mar 23 16:15:38 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

static void	init_cycle(t_game *g)
{
  g->cycle_to_die = CYCLE_TO_DIE;
  g->old_cycle_verrif = 0;
  g->cycle = 0;
}

t_game		*init_game(t_parse *parse)
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->parse = parse;
  if ((game->arena = arena_create()) == NULL)
    return (NULL);
  if (is_overlap_lock(parse) && (my_puterror("Overlap detected\n")))
    return (NULL);
  if (init_arena(game))
    return (NULL);
  if (init_live(game))
    return (NULL);
  init_cycle(game);
  init_head(game);
  game->cycle = 0;
  return (game);
}

int		game(t_parse *parse)
{
  void		(*fnt[16])(t_game *, t_heads *, t_ins *);
  int		stop;
  t_heads	*head;
  t_game	*game;

  if (!(game = init_game(parse)))
    return (1);
  get_fnt_tab(fnt);
  stop = 0;
  while (!stop)
    {
      head = game->heads;
      while (!stop && head)
  	{
  	  exec_head(game, head, &stop, fnt);
  	  head->pos %= MEM_SIZE;
  	  head = head->next;
  	}
      game->cycle += 1;
    }
  return (0);
}
