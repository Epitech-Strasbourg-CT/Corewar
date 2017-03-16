/*
** arena_create.c for arena in /home/arthur/delivery/CPE/CPE_2016_corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Mar 16 12:48:58 2017 Arthur Knoepflin
** Last update Thu Mar 16 20:53:32 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"

char	*arena_create(void)
{
  char	*arena;

  if ((arena = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    return (NULL);
  my_memset(arena, 0, MEM_SIZE);
  return (arena);
}
