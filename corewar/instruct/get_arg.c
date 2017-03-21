/*
** get_arg.c for get_arg in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Mar 20 21:56:31 2017 Arthur Knoepflin
** Last update Tue Mar 21 16:13:58 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

/*
** registre : direct : indirect
** -1 -> invalid
*/

const static int	g_byte_len[16][3] =
  {
    {INV, DIR_SIZE, INV},			/* live */
    {REG_SIZE, DIR_SIZE, IND_SIZE},		/* ld */
    {REG_SIZE, DIR_SIZE, IND_SIZE},		/* st */
    {REG_SIZE, INV, INV},			/* add */
    {REG_SIZE, INV, INV},			/* sub */
    {REG_SIZE, DIR_SIZE, IND_SIZE},		/* and */
    {REG_SIZE, DIR_SIZE, IND_SIZE},		/* or */
    {REG_SIZE, DIR_SIZE, IND_SIZE},		/* xor */
    {INV, IDX_SIZE, INV},			/* zjmp */
    {REG_SIZE, IDX_SIZE, IND_SIZE},		/* ldi */
    {REG_SIZE, IDX_SIZE, IND_SIZE},		/* sti */
    {INV, IDX_SIZE, INV},			/* fork */
    {REG_SIZE, DIR_SIZE, IND_SIZE},		/* lld */
    {REG_SIZE, IDX_SIZE, IND_SIZE},		/* lldi */
    {INV, IDX_SIZE, INV},			/* lfork */
    {REG_SIZE, INV, INV}			/* aff */
  };

static int	extract_val(char *arena, int len)
{
  int		i;
  unsigned char	*ret;

  if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
    return (0);
  i = -1;
  while (++i < len)
    ret[i] = arena[i];
  if (len == 1)
    return (ret[0]);
  if (len == 2)
    return ((short int) ((ret[0] << 8) | ret[1]));
  if (len == 3)
    return (((ret[0] << 16) | (ret[1] << 8) | ret[2]));
  if (len == 4)
    return (((ret[0] << 24) | (ret[1] << 16) | (ret[2] << 8) | ret[3]));
  return (0);
}

static int	particular(t_game *game, int index, t_ins *ret)
{
  if (ret->cmd == 1)
    {
      ret->type[0] = 2;
      ret->tot_byte = 5;
      ret->val[0] = extract_val(game->arena + index + 1, 4);
      return (1);
    }
  if (ret->cmd == 9 || ret->cmd == 12 || ret->cmd == 15)
    {
      ret->type[0] = 2;
      ret->tot_byte = 3;
      ret->val[0] = extract_val(game->arena + index + 1, 2);
      return (1);
    }
  return (0);
}

int	get_arg(t_game *game, int index, t_ins *ret)
{
  int	i;
  int	decal;

  ret->tot_byte = 0;
  if (particular(game, index, ret))
    return (0);
  i = -1;
  decal = 0;
  while (++i < ret->nb_arg)
    {
      ret->val[i] = extract_val(game->arena + index + 2 + decal,
				g_byte_len[ret->cmd - 1][ret->type[i] - 1]);
      decal += g_byte_len[ret->cmd - 1][ret->type[i] - 1];
    }
  ret->tot_byte += 2 + decal;
  return (0);
}