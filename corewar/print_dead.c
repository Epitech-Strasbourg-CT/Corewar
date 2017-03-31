/*
** print_dead.c for print_dead in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Mar 31 22:49:16 2017 Arthur Knoepflin
** Last update Fri Mar 31 23:06:14 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

void	print_dead(t_game *g, int id)
{
  char	*name;
  char	*msg;

  name = get_name(g, id);
  if ((msg = malloc(sizeof(char) * (32 + my_strlen(name)))) != NULL)
    {
      my_memset(msg, ' ', 31);
      my_strcpy(msg, "Le joueur ");
      msg[10] = id + '0';
      my_strcpy(msg + 11, " (");
      my_strcpy(msg + 13, name);
      my_strcpy(msg + 13 + my_strlen(name), ") est mort.\n");
      msg[31] = '\0';
      my_put_list_live(&g->msg, msg);
    }
}
