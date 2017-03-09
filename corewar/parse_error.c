/*
** parse_error.c for parse_error in /home/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar  9 20:41:18 2017 Arthur Knoepflin
** Last update Thu Mar  9 23:26:07 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "my.h"

int	is_an_arg(char *str)
{
  if (!my_strcmp(str, "-dump") || !my_strcmp(str, "-n") ||
      !my_strcmp(str, "-a"))
    return (1);
  return (0);
}

int	check_champ(int ac, char **av, int *count, int *i)
{
  if (*i >= ac)
    return (1);
  if (av[*i][0] == '-' && !is_an_arg(av[*i]))
    return (print_unknown_arg(av[*i]));
  if (!my_strcmp(av[*i], "-a") && (*count += 2) && (*i += 2));
  if (*i >= ac)
    return (1);
  if (av[*i][0] == '-' && !is_an_arg(av[*i]))
    return (print_unknown_arg(av[*i]));
  if (!my_strcmp(av[*i], "-n") && (*count += 2) && (*i += 2));
  if (*i >= ac && av[*i][0] == '-' && !is_an_arg(av[*i]))
    return (1);
  if (!is_an_arg(av[*i]) && (*count += 1));
  return (0);
}

static int	print_msg(void)
{
  my_puterror("Check the syntax of the command\n");
  return (1);
}

int	check_nb_arg(int ac, char **av)
{
  int	count;
  int	already_d;
  int	i;

  i = 0;
  already_d = 0;
  count = 0;
  while (i < ac)
    {
      if (!my_strcmp(av[i], "-dump") && !already_d && (already_d = 1) &&
	  (i += 2) && (count += 2))
	continue ;
      else if (!my_strcmp(av[i], "-dump") && already_d)
	return (print_msg());
      if (check_champ(ac, av, &count, &i))
	return (print_msg());
      i += 1;
    }
  if (count != ac)
    print_msg();
  return (count != ac);
}

int	check_error(int ac, char **av)
{
  if (check_nb_arg(ac, av))
    return (1);
  if (check_valid_arg(ac, av))
    return (1);
  return (0);
}
