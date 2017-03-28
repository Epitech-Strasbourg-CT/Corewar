/*
** put.c for put in /home/cedric/CPE_2016_corewar/desasm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Tue Mar 28 14:21:56 2017 
** Last update Tue Mar 28 15:16:57 2017 
*/
#include <unistd.h>
#include "corewar.h"
#include "my.h"

void	my_fputchar(int fd, char c)
{
  write(fd, &c, 1);
}

void	my_fputstr(int fd, char *str)
{
  int	len;

  len = my_strlen(str);
  write(fd, str, len);
}

void	my_fputnbr(int fd, long nb)
{
  if (nb < 0)
    {
      my_fputchar(fd, '-');
      nb *= -1;
    }
  if (nb / 10 > 0)
    my_fputnbr(fd, nb / 10);
  my_fputchar(fd, nb % 10 + '0');
}
