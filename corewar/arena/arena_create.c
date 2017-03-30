/*
** arena_create.c for arena in /home/arthur/delivery/CPE/CPE_2016_corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 12:48:58 2017 Arthur Knoepflin
** Last update Wed Mar 29 17:58:22 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

unsigned char	*arena_create(void)
{
  unsigned char	*arena;

  if ((arena = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    return (NULL);
  my_memset(arena, 0, MEM_SIZE);
  return (arena);
}

static int	affect_addr(t_game *g, int ecart)
{
  int		i;
  int		*tab_pos;

  if ((tab_pos = get_tab_pos(g->parse, ecart)) == NULL)
    return (1);
  i = -1;
  while (++i < g->parse->nb_champ)
    if (g->parse->champ[i]->load_addr == -1)
      g->parse->champ[i]->load_addr = tab_pos[i];
  free(tab_pos);
  return (0);
}

int	init_arena(t_game *game)
{
  int	ret;
  int	ecart;

  ecart = get_ecart(game->parse);
  if (affect_addr(game, ecart))
    return (1);
  if (!nb_champ_with_addr(game->parse))
    ret = load_all_champ(game, ecart);
  else
    ret = load_champ_addr(game, ecart);
  return (ret);
}
