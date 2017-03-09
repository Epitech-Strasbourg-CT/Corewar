/*
** parse.c for parse in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar  9 19:19:22 2017 Arthur Knoepflin
** Last update Thu Mar  9 22:42:07 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"

t_parse		*get_parse(int ac, char **av)
{
  t_parse	*parse;

  if ((parse = malloc(sizeof(t_parse))) == NULL)
    return (NULL);
  if (check_error(ac, av))
    return (NULL);
  
  return (parse);
}
