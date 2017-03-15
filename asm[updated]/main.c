/*
** main.c for corewar-asm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/asm
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Wed Mar  1 17:32:57 2017 Nicolas Polomack
** Last update Tue Mar 14 16:19:40 2017 
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "my_printf.h"
#include "asm.h"

static char	*get_file_name(char *str)
{
  int		i;
  char		*name;

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

static void	write_headers(t_asm *a)
{
  t_header	h;

  my_memset((char *)&h, 0, sizeof(t_header));
  h.magic = COREWAR_EXEC_MAGIC;
  my_strcpy(h.prog_name, a->header.name);
  my_strcpy(h.comment, a->header.comment);
  swap_endian(&h.magic, 4);
  write(a->fd, &h.magic, 4);
  write(a->fd, h.prog_name, PROG_NAME_LENGTH);
  write(a->fd, h.comment, COMMENT_LENGTH);
}

static void	init_asm(t_asm *a, char **av)
{
  a->file_name = get_file_name(av[1]);
  a->file = NULL;
  a->header.name = NULL;
  a->header.comment = NULL;
}

int		main(int ac, char **av)
{
  t_asm		a;

  if (ac != 2 || (check_dir(av[1]) == -1))
    return (84);
  init_asm(&a, av);
  if ((a.fd = open(a.file_name,
		   O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (84);
  if (read_file(&a, av[1]) == -1)
    return (84);
  parse_headers(&a);
  write_headers(&a);
  change_label(&a);
  load_instruct(&a);
  
  //DEBUG
  
  my_printf("NAME: %s\n", a.header.name);
  my_printf("COMMENT: %s\n\n", a.header.comment);
  my_show_label(a.labels);
  my_putchar('\n');
  my_show_instruct(a.instructs);
  my_putchar('\n');
  close(a.fd);
  return (0);
}
