/*
** parse_get_list_id.c for get_list_id in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sun Mar 12 12:04:18 2017 Arthur Knoepflin
** Last update Sun Mar 12 12:37:34 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static void	treat_arg(int ac, char **av, int *i, char *val)
{
  if ((is_an_arg(av[*i]) == 2 || is_an_arg(av[*i]) == 3))
    {
      if (is_an_arg(av[*i]) == 2)
	*val = my_getnbr(av[*i + 1]);
      *i += 2;
    }
}

char	*get_list_id(int ac, char **av)
{
  int	i;
  int	nb_champ;
  char	*ret;

  if ((ret = malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  my_memset(ret, -1, 4);
  i = -1;
  nb_champ = 0;
  while (++i < ac)
    {
      if (!my_strcmp(av[i], "-dump") && (i += 2))
	continue ;
      treat_arg(ac, av, &i, &ret[nb_champ]);
      treat_arg(ac, av, &i, &ret[nb_champ]);
      nb_champ += 1;
    }
  return (ret);
}

int	my_free(char *tab)
{
  free(tab);
  return (1);
}

static int	same_id(int val, int index, char *list_id)
{
  int		j;

  j = -1;
  while (++j < 4)
    {
      if (index != j && val == list_id[j] &&
	  (my_puterror("Two champion have the same id\n")))
	return (1);	
    }
  return (0);
}

int	check_id(int ac, char **av)
{
  int	i;
  int	j;
  char	*list_id;

  if ((list_id = get_list_id(ac, av)) == NULL)
    return (1);
  i = -1;
  while (++i < 4)
    {
      if (list_id[i] == -1)
      	continue ;
      if ((list_id[i] < 1 || list_id[i] > 4) &&
	  (my_puterror("The id need to be between 1 and 4\n")))
	return (my_free(list_id));
      if (same_id(list_id[i], i, list_id))
	return (my_free(list_id));
    }
  free(list_id);
  return (0);
}
