/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Thu Mar  9 19:30:27 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my_printf.h"
#include "op.h"
#include "asm.h"
#include "my.h"

char	**my_realloc(char **file, char *line, int size)
{
  int	i;
  char	**new;

  if ((new = malloc(sizeof(char *) * (size + 2))) == NULL)
    return (NULL);
  i = -1;
  while (++i < size)
    new[i] = file[i];
  new[i++] = line;
  new[i] = NULL;
  free(file);
  return (new);
}

int	is_comment(char *str)
{
  int	i;

  i = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i += 1;
  if (str[i] == COMMENT_CHAR || str[i] == 0)
    return (1);
  return (0);
}

int	read_file(t_asm *a, char *file)
{
  int	fd;
  int	size;
  char	*line;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  size = 0;
  while ((line = get_next_line(fd)))
    {
      if (is_comment(line))
	{
	  free(line);
	  continue;
	}
      else if (size == 0)
	{	
	  if ((a->file = malloc(sizeof(char *) * 2)) == NULL)
	    return (-1);
	  a->file[0] = line;
	  a->file[1] = NULL;
	}
      else
	if ((a->file = my_realloc(a->file, line, size)) == NULL)
	  return (-1);
      size += 1;
    }
  close(fd);
  return (0);
}

void	display_file(char **file)
{
  int	i;

  i = -1;
  while (file[++i] != NULL)
    my_printf("line %3d: '%s'\n", i + 1, file[i]);
}

int	check_dir(char *file)
{
  int	fd;

  if ((fd = open(file, O_DIRECTORY)) != -1)
    {
      close(fd);
      return (-1);
    }
  return (0);
}
