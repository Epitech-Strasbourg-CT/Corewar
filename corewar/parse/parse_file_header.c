/*
** parse_file.c for parse_file in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Mar 13 21:57:35 2017 Arthur Knoepflin
** Last update Tue Mar 14 15:37:05 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"
#include "my.h"

static int	check_magicnum(t_header *head, char *path)
{
  swap_endian(&head->magic, 4);
  if (head->magic != COREWAR_EXEC_MAGIC)
    {
      my_puterror(path);
      my_puterror(": Is not a binary compatible\n");
      return (1);
    }
  return (0);
}

static int	attribute_size(t_header *head, t_nchamp *champ)
{
  swap_endian(&head->prog_size, 4);
  champ->size = head->prog_size;
}

int		parse_header(int fd, char *path, t_nchamp *champ)
{
  t_header	header;
  int		size;

  size = read(fd, &header, sizeof(header));
  if (size >= 4 && check_magicnum(&header, path))
    return (1);
  if (size >= 4 + PROG_NAME_LENGTH)
    champ->name = my_strdup(header.prog_name);
  if (size >= 8 + PROG_NAME_LENGTH)
    attribute_size(&header, champ);
  if (size >= 8 + PROG_NAME_LENGTH + COMMENT_LENGTH)
    champ->comment = my_strdup(header.comment);
  if (size != sizeof(header))
    {
      my_puterror(path);
      my_puterror(": Error in reading the header, check the champion\n");
      return (1);
    }
  return (0);
}
