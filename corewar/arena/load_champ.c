/*
** load_champ.c for load_champ in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 21:02:16 2017 Arthur Knoepflin
** Last update Thu Mar 16 21:08:14 2017 Arthur Knoepflin
*/

#include "corewar.h"

void	load_champ(t_game *game, t_nchamp *champ)
{
  int	index;
  int	i;

  if ((index = champ->load_addr) == -1)
    return ;
  i = -1;
  while (++i < champ->size)
    {
      game->arena[index] = (unsigned char) champ->code[i];
      index += 1;
    }
}
