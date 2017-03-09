/*
** main.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Wed Mar  1 17:32:57 2017 Nicolas Polomack
** Last update Tue Mar  7 15:05:17 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include "my_printf.h"
#include "asm.h"

int		main(int ac, char **av)
{
  t_asm		a;

  if (ac != 2 || (check_dir(av[1]) == -1))
    return (84);
  a.file = NULL;
  a.header.name = NULL;
  a.header.comment = NULL;
  if (read_file(&a, av[1]) == -1)
    return (84);
  parse_headers(&a);
  my_printf("NAME: %s\n", a.header.name);
  my_printf("COMMENT: %s\n", a.header.comment);
  display_file(a.file);
  return (0);
}
