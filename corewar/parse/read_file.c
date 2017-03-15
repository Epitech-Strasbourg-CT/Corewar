/*
** read_file.c for read_file in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Mar 14 15:51:54 2017 Arthur Knoepflin
** Last update Tue Mar 14 16:26:16 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "my.h"

char	*my_strcat_size(char *str1, char *str2, int size)
{
  char	*ret;
  int	i;
  int	j;

  if ((ret = malloc(sizeof(char) * (my_strlen(str1) + size + 1))) == NULL)
    return (NULL);
  ret[my_strlen(str1) + size] = '\0';
  i = -1;
  while (str1[++i])
    ret[i] = str1[i];
  j = 0;
  while (j < size)
    {
      ret[i] = str2[j];
      i += 1;
      j += 1;
    }
  free(str1);
  return (ret);
}

char	*read_file(int fd)
{
  char	*ret;
  int	size;
  char	buffer[BUF_SIZE];

  if ((ret = my_strdup("")) == NULL)
    return (NULL);
  while ((size = read(fd, buffer, BUF_SIZE)) != 0)
    {
      if ((ret = my_strcat_size(ret, buffer, size)) == NULL)
	return (NULL);
    }
  return (ret);
}
