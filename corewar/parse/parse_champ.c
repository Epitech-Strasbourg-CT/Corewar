/*
** parse_champ.c for parse_champ in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sun Mar 12 11:16:07 2017 Arthur Knoepflin
** Last update Sun Mar 12 13:51:51 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static int	init_champ(t_parse *parse, int nb)
{
  if ((parse->champ[nb] = malloc(sizeof(t_parse))) == NULL)
    return (1);
  parse->champ[nb]->id = -1;
  parse->champ[nb]->load_addr = -1;
  parse->champ[nb]->path = NULL;
  return (0);
}

static void	parse_arg(t_parse *parse, char **av, int *i, int nb_champ)
{
  if (!my_strcmp(av[*i], "-n"))
    {
      parse->champ[nb_champ]->id = my_getnbr(av[*i + 1]);
      *i += 2;
      return ;
    }
  if (!my_strcmp(av[*i], "-a"))
    {
      parse->champ[nb_champ]->load_addr = my_getnbr(av[*i + 1]);
      *i += 2;
      return ;
    }
}

int	auto_attribute_id(t_parse *parse, int nb_champ, int ac, char **av)
{
  int	i;
  int	new_id;
  char	*list_id;

  if (parse->champ[nb_champ]->id == -1)
    {
      if ((list_id = get_list_id(ac, av)) == NULL)
	return (1);
      new_id = 1;
      i = -1;
      while (++i < 4)
	if ((new_id == list_id[i] ||
	     (parse->champ[i] && new_id == parse->champ[i]->id)) && ((i = -1) || 1))
	  new_id += 1;
      parse->champ[nb_champ]->id = new_id;
    }
  return (0);
}

int	parse_champ(t_parse *parse, int ac, char **av)
{
  int	i;
  int	nb_champ;

  i = 0;
  nb_champ = 0;
  while (i < ac)
    {
      if (!my_strcmp(av[i], "-dump") && (i += 2))
	continue ;
      if (init_champ(parse, nb_champ))
	return (1);
      if ((is_an_arg(av[i]) == 2 || is_an_arg(av[i]) == 3))
	parse_arg(parse, av, &i, nb_champ);
      if ((is_an_arg(av[i]) == 2 || is_an_arg(av[i]) == 3))
	parse_arg(parse, av, &i, nb_champ);
      parse->champ[nb_champ]->path = my_strdup(av[i]);
      auto_attribute_id(parse, nb_champ, ac, av);
      nb_champ += 1;
      i += 1;
    }
  return (0);
}
