/*
** game.c for game in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 12:53:10 2017 Arthur Knoepflin
** Last update Thu Mar 16 21:10:10 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"

t_game		*init_game(t_parse *parse)
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->parse = parse;
  if ((game->arena = arena_create()) == NULL)
    return (NULL);
  game->cycle = 0;
}

int		game(t_parse *parse)
{
  t_game	*game;

  if (!(game = init_game(parse)))
    return (1);
  load_champ(game, parse->champ[0]);
  dump(game);
}
