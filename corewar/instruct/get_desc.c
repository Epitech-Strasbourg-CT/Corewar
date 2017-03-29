/*
** get_desc.c for get_desc in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Mar 20 17:42:56 2017 Arthur Knoepflin
** Last update Wed Mar 29 17:16:44 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static char	*add_zero(char *in)
{
  int		i;
  int		j;
  char		*ret;

  if ((ret = malloc(sizeof(char) * 9)) == NULL)
    return (NULL);
  ret[8] = '\0';
  i = -1;
  while (++i < (8 - my_strlen(in)))
    ret[i] = '0';
  j = 0;
  while (i < 8)
    {
      ret[i] = in[j];
      i += 1;
      j += 1;
    }
  free(in);
  return (ret);
}

static int	nb_arg(char *base)
{
  int		i;
  int		ret;

  ret = 0;
  i = 0;
  while (i < 8)
    {
      if (base[i] != '0' || base[i + 1] != '0')
	ret += 1;
      i += 2;
    }
  return (ret);
}

static int	my_free(void *ptr)
{
  free(ptr);
  return (1);
}

int	get_desc(int desci, t_ins *ret)
{
  int	i;
  char	*b;
  char	*desc;

  if ((desc = my_int_to_char(desci)) == NULL)
    return (1);
  if ((b = convert_base(desc, "0123456789", "01")) == NULL)
    return (my_free(desc));
  free(desc);
  if (my_strlen(b) != 8)
    if ((b = add_zero(b)) == NULL)
      return (1);
  if ((ret->nb_arg = nb_arg(b)) != g_op_tab[ret->cmd - 1].nbr_args)
    return (1);
  i = -1;
  while (++i < ret->nb_arg)
    {
      ret->type[i] = 0;
      if (b[i * 2] == '1')
	ret->type[i] = ret->type[i] | 0x2;
      if (b[i * 2 + 1] == '1')
	ret->type[i] = ret->type[i] | 0x1;
    }
  free(b);
  return (0);
}
