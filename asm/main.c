/*
** main.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Wed Mar  1 17:32:57 2017 Nicolas Polomack
** Last update Fri Mar 10 18:05:57 2017 Nicolas Polomack
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "my_printf.h"
#include "asm.h"

char	*get_file_name(char *str)
{
  int	i;
  char	*name;

  name = str;
  while (*(++str));
  while (str != name && *str != '/')
    str -= 1;
  if (*str == '/')
    str += 1;
  i = my_strstr(str, ".s") - str;
  name = malloc(i + 5);
  name = my_strncpy(name, str, i);
  name[i] = 0;
  my_strcat(name, ".cor");
  return (name);
}

void			write_headers(t_asm *a)
{
  struct header_s	h;

  my_memset((char *)&h, 0, sizeof(struct header_s));
  h.magic = COREWAR_EXEC_MAGIC;
  my_strcpy(h.prog_name, a->header.name);
  my_strcpy(h.comment, a->header.comment);
  swap_endian(&h.magic, 4);
  write(a->fd, &h.magic, 4);
  write(a->fd, h.prog_name, PROG_NAME_LENGTH + 1);
  write(a->fd, h.comment, COMMENT_LENGTH + 1);
}

int		main(int ac, char **av)
{
  t_asm		a;

  if (ac != 2 || (check_dir(av[1]) == -1))
    return (84);
  a.file_name = get_file_name(av[1]);
  if ((a.fd = open(a.file_name,
		   O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (84);
  a.file = NULL;
  a.header.name = NULL;
  a.header.comment = NULL;
  if (read_file(&a, av[1]) == -1)
    return (84);
  parse_headers(&a);
  write_headers(&a);
  my_printf("NAME: %s\n", a.header.name);
  my_printf("COMMENT: %s\n", a.header.comment);
  //display_file(a.file);
  close(a.fd);
  return (0);
}
