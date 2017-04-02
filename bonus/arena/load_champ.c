/*
** load_champ.c for load_champ in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 21:02:16 2017 Arthur Knoepflin
** Last update Fri Mar 31 23:09:29 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

int	nb_champ_with_addr(t_parse *parse)
{
  int	ret;
  int	i;

  i = -1;
  ret = 0;
  while (++i < parse->nb_champ)
    if (parse->champ[i]->load_addr != -1)
      ret += 1;
  return (ret);
}

int	load_champ(t_game *game, t_nchamp *champ, int addr)
{
  int	index;
  int	i;

  if (champ->load_addr == -1 && addr == -1)
    return (1);
  if (champ->load_addr != -1)
    index = champ->load_addr;
  else
    index = addr;
  i = -1;
  while (++i < champ->size)
    {
      if (game->arena[index] != 0 && (my_puterror("Overlap detected\n")))
	return (1);
      game->arena[index] = (unsigned char) champ->code[i];
      index += 1;
    }
  return (0);
}

int	load_all_champ(t_game *game, int ecart)
{
  int	i;
  int	*pos;

  if ((pos = get_tab_pos(game->parse, ecart)) == NULL)
    return (1);
  i = -1;
  while (++i < game->parse->nb_champ)
    if (load_champ(game, game->parse->champ[i], pos[i]))
      return (1);
  return (0);
}

int	load_champ_addr(t_game *game, int ecart)
{
  int	i;
  int	*pos;

  if ((pos = get_tab_pos(game->parse, ecart)) == NULL)
    return (1);
  i = -1;
  while (++i < game->parse->nb_champ)
    if (game->parse->champ[i]->load_addr == -1)
      {
	if (load_champ(game, game->parse->champ[i], pos[i]))
	  return (1);
      }
    else
      {
	if (load_champ(game, game->parse->champ[i], -1))
	  return (1);
      }
  return (0);
}
