/*
** parse.c for parse in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar  9 19:19:22 2017 Arthur Knoepflin
** Last update Wed Mar 29 17:00:45 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

int	nb_champ(int ac, char **av)
{
  int	i;
  int	nb_champ;

  i = 0;
  nb_champ = 0;
  while (i < ac)
    {
      if (!my_strcmp(av[i], "-dump"))
	i += 2;
      else
	{
	  if ((is_an_arg(av[i]) == 2 || is_an_arg(av[i]) == 3))
	    i += 2;
	  if ((is_an_arg(av[i]) == 2 || is_an_arg(av[i]) == 3))
	    i += 2;
	  nb_champ += 1;
	  i += 1;
	}
    }
  return (nb_champ);
}

void	init_parse(t_parse *parse, int ac, char **av)
{
  int	i;

  parse->dump = -1;
  parse->nb_champ = nb_champ(ac, av);
  i = -1;
  while (++i < 4)
    parse->champ[i] = NULL;
}

void	parse_dump(t_parse *parse, int ac, char **av)
{
  int	i;

  i = 0;
  while (i < ac)
    {
      if (!my_strcmp(av[i], "-dump") && (i += 1))
	parse->dump = my_getnbr(av[i++]);
      else
	{
	  if ((is_an_arg(av[i]) == 2 || is_an_arg(av[i]) == 3))
	    i += 2;
	  if ((is_an_arg(av[i]) == 2 || is_an_arg(av[i]) == 3))
	    i += 2;
	  i += 1;
	}
    }
}

void	mod_addr(t_parse *parse)
{
  int	i;

  i = -1;
  while (++i < parse->nb_champ)
    {
      if (parse->champ[i]->load_addr > -1)
	parse->champ[i]->load_addr %= MEM_SIZE;
    }
}

t_parse		*get_parse(int ac, char **av)
{
  t_parse	*parse;

  if ((parse = malloc(sizeof(t_parse))) == NULL)
    return (NULL);
  if (check_error(ac, av))
    return (NULL);
  init_parse(parse, ac, av);
  parse_dump(parse, ac, av);
  parse_champ(parse, ac, av);
  if (parse_file_champ(parse))
    return (NULL);
  mod_addr(parse);
  return (parse);
}
