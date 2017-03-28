/*
** my_strcatdup.c for my_strcatdup in /home/arthur/delivery/PSU/PSU_2016_tetris
** 
** Made by 
** Login   <arthur@epitech.net>
** 
** Started on  Tue Feb 21 10:22:56 2017 
** Last update Wed Feb 22 22:20:54 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcatdup(char *s1, char *s2)
{
  int	i;
  char	*dest;
  int	len;

  i = 0;
  if (s2 == NULL)
    return (s1);
  len = 0;
  if (s1 != NULL)
    len = my_strlen(s1);
  if ((dest = malloc(sizeof(char) * (len + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  while (i <  (len + my_strlen(s2)))
    {
      if (i < len)
	dest[i] = s1[i];
      else
	dest[i] = s2[i - len];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}
