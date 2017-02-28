/*
** my_strndup.c for my_strndup in /home/arthur/delivery/PSU/PSU_2016_tetris
** 
** Made by 
** Login   <arthur@epitech.net>
** 
** Started on  Tue Feb 21 14:23:56 2017 
** Last update Tue Feb 21 14:35:50 2017 
*/


#include <stdlib.h>
#include "my.h"

char	*my_strndup(char *src, int len)
{
  char	*resp;
  int	count;

  count = 0;
  resp = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (resp == NULL)
    return (NULL);
  while (src[count] != '\0' && count < len)
    {
      resp[count] = src[count];
      count = count + 1;
    }
  resp[count] = '\0';
  return (resp);
}
