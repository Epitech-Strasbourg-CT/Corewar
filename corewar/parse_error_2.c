/*
** parse_error_2.c for parse_error in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar  9 22:46:57 2017 Arthur Knoepflin
** Last update Thu Mar  9 23:24:43 2017 Arthur Knoepflin
*/

#include "my.h"

int	print_unknown_arg(char *str)
{
  my_puterror(str);
  my_puterror(": Invalid arg\n");
  return (1);
}

static int	print_msg(char *str)
{
  my_puterror(str);
  my_puterror(": This argument need a positive number\n");
  return (1);
}

int	check_valid_arg(int ac, char **av)
{
  int	i;

  i = 0;
  while (i < ac)
    {
      if (!my_strcmp(av[i], "-dump") && (i += 1))
	if (!is_a_num(av[i]))
	  return (print_msg("-dump"));
      if (!my_strcmp(av[i], "-n") && (i += 1))
	if (!is_a_num(av[i]))
	  return (print_msg("-n"));
      if (!my_strcmp(av[i], "-a") && (i += 1))
	if (!is_a_num(av[i]))
	  return (print_msg("-a"));
      i += 1;
    }
  return (0);
}
