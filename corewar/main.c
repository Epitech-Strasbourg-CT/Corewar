/*
** main.c for main in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Feb 28 18:47:35 2017 Arthur Knoepflin
** Last update Thu Mar  9 20:45:18 2017 Arthur Knoepflin
*/

#include "corewar.h"
#include "my.h"

void	disp_help()
{
  my_putstr("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\n\n");
  my_putstr("DESCRIPTION\n\t-dump nbr_clycle dumbs the memory after \
the nbr_cycle execution (if the round isn't\n\t\t\t already over) with the \
following format: 32 bytes/line in\n\t\t\t hexadecimal (A0BCDEFE1DD3...)\n");
  my_putstr("\t-n prog_number   sets the next program's number. By default, \
the first free number\n\t\t\t in the parameter order\n");
  my_putstr("\t-a load_address  sets the next program's loading address.\
 When no address is\n\t\t\t specified, optimize the addresses so that \
the processes are as far\n\t\t\t away from each other as possible. \
The addresses are MEM_SIZE modulo\n");
}

int		main(int ac, char **av)
{
  t_parse	*parse;

  if (ac == 1)
    disp_help();
  if (ac > 1 && my_strcmp(av[1], "-h") == 0)
    disp_help();
  parse = get_parse(ac - 1, av + 1);
  return (0);
}
