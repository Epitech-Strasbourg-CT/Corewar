/*
** parse_file_champ.c for parse_file_champ in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Mar 13 22:16:36 2017 Arthur Knoepflin
** Last update Thu Mar 16 20:57:56 2017 Arthur Knoepflin
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"
#include "my.h"

int	open_file(char *path)
{
  int	fd;

  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_puterror("The file \"");
      my_puterror(path);
      my_puterror("\" doesn't exist\n");
    }
  return (fd);
}

int	parse_file_champ(t_parse *parse)
{
  int	i;
  char	*tmp;
  int	fd;

  i = -1;
  while (++i < parse->nb_champ)
   {
      if ((fd = open_file(parse->champ[i]->path)) == -1)
	return (1);
      if (parse_header(fd, parse->champ[i]->path, parse->champ[i]))
	return (1);
      if ((parse->champ[i]->code = read_file(fd)) == NULL)
      	return (1);
      close(fd);
    }
  return (0);
}
