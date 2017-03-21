/*
** game.c for game in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 12:53:10 2017 Arthur Knoepflin
** Last update Tue Mar 21 21:24:06 2017 
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

static void	link_ids(t_nchamp *champs)
{
  int		i;

  i = -1;
  while (++i < 4 && (*champs)[i])
    (*champs)[i].regs[0] = (*champs)[i].id;
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
  link_ids(game->parse->champ);
  game->cycle = 0;
}

int		game(t_parse *parse)
{
  t_ins		*tmp;
  int		j;
  t_game	*game;

  if (!(game = init_game(parse)))
    return (1);
  j = 0;
  while (j < parse->champ[0]->size)
    {
      if ((tmp = get_instruc(game, j)) == NULL)
	{
	  j += 1;
	  my_putstr("NOT AN INSTRUCTION\n");
	}
      else
	{
	  printf("%s ", op_tab[tmp->cmd - 1].mnemonique);
	  int i;
	  i = -1;
	  while (++i < tmp->nb_arg)
	    {
	      printf("%s%d", (tmp->type[i] == 1) ? "r" :
		     (tmp->type[i] == 2) ? "%" : "", tmp->val[i]);
	      if (i == tmp->nb_arg - 1)
		printf("\n");
	      else
		printf(",");
	    }
	  j += tmp->tot_byte;
	  /* printf("tot_byte : %d nb_arg : %d\n", tmp->tot_byte, tmp->nb_arg); */
	}
    }
  /* dump(game); */
  return (0);
}
