/*
** main.c for main in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Feb 28 18:47:35 2017 Arthur Knoepflin
** Last update Tue Mar 21 20:33:22 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include "op.h"

void	disp_help(char *name)
{
  my_putstr("USAGE\n\t");
  my_putstr(name);
  my_putstr(" [-dump nbr_cycle] [[-n prog_number] \
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

  if (ac == 1 || (ac > 1 && my_strcmp(av[1], "-h") == 0))
    {
      disp_help(av[0]);
      return (0);
    }
  if ((parse = get_parse(ac - 1, av + 1)) == NULL)
    return (84);
  /* printf("dump : %d && nb_champ : %d\n", parse->dump, parse->nb_champ); */
  /* int	i; */
  /* i = 0; */
  /* while (i < parse->nb_champ) */
  /*   { */
  /*     if (parse->champ[i]) */
  /* 	printf("id : %d load_addr : %d path : %s name : %s size : %d comment : %s\n", parse->champ[i]->id, */
  /* 	       parse->champ[i]->load_addr, parse->champ[i]->path, parse->champ[i]->name, */
  /* 	       parse->champ[i]->size, parse->champ[i]->comment); */
  /*     i += 1; */
  /*   } */
  if (game(parse))
    return (84);
  return (0);
}
