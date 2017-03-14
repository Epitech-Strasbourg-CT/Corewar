/*
** instruct.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Tue Mar 14 14:32:36 2017 
** Last update Tue Mar 14 16:18:01 2017 
*/
#include <stdlib.h>
#include "asm.h"

int	load_instruct(t_asm *myasm)
{
  int	i;

  i = -1;
  myasm->instructs = NULL;  
  while (myasm->file[++i])
    my_put_list_instruct(&myasm->instructs, myasm->file[i]);
  free(myasm->file);
  myasm->file = NULL;
  return (0);
}
