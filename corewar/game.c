/*
** game.c for game in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 12:53:10 2017 Arthur Knoepflin
** Last update Mon Mar 20 15:04:00 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

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
  game->cycle = 0;
}

int		game(t_parse *parse)
{
  t_game	*game;

  if (!(game = init_game(parse)))
    return (1);
  /* printf("nb_champ : %d\n", nb_champ_with_addr(parse)); */
  /* printf("%d\n", ecart); */
  /* load_champ(game, parse->champ[0]); */
  dump(game);
  return (0);
}
