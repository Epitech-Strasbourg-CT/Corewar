/*
** arena_create.c for arena in /home/arthur/delivery/CPE/CPE_2016_corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 12:48:58 2017 Arthur Knoepflin
** Last update Mon Mar 20 15:00:57 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

char	*arena_create(void)
{
  char	*arena;

  if ((arena = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    return (NULL);
  my_memset(arena, 0, MEM_SIZE);
  return (arena);
}

int	init_arena(t_game *game)
{
  int	ret;
  int	ecart;

  ecart = get_ecart(game->parse);
  if (!nb_champ_with_addr(game->parse))
    ret = load_all_champ(game, ecart);
  else
    ret = load_champ_addr(game, ecart);
  return (ret);
}
