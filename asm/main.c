/*
** main.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Wed Mar  1 17:32:57 2017 Nicolas Polomack
** Last update Wed Mar  1 17:33:28 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include "asm.h"

int		main(int ac, char **av)
{
  t_asm		a;

  if (ac != 2 || (check_dir(av[1]) == -1))
    return (84);
  a.file = NULL;
  if (read_file(&a, av[1]) == -1)
    return (84);
  display_file(a.file);
  return (0);
}
