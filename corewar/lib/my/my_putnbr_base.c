/*
** my_putnbr_base.c for my_putnbr_base in /home/arthur/delivery/CPool_Day06
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Mon Oct 10 18:05:53 2016 Arthur Knoepflin
** Last update Thu Mar 16 20:55:38 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"

int	my_putnbr_base_length(char *base)
{
  int	i;

  i = 0;
  while (base[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	size_nb(int nbr, char *base)
{
  int	ret;
  int	long_base;

  ret = 0;
  long_base = my_putnbr_base_length(base);
  if (nbr == 0)
    return (1);
  if (nbr < 0)
    nbr *= -1;
  while (nbr != 0)
    {
      ret += 1;
      nbr /= long_base;
    }
  return (ret);
}

void	my_putnbr_base(int nbr, char *base)
{
  int	digit_display;
  int	long_base;
  long	nb_long;

  nb_long = nbr;
  long_base = my_putnbr_base_length(base);
  if (long_base == 0)
    return ;
  if (nb_long < 0)
    {
      my_putchar('-');
      nb_long *= (-1);
    }
  if  (nb_long < long_base)
    {
      my_putchar(base[nb_long]);
    }
  else
    {
      digit_display = nb_long % long_base;
      nb_long = nb_long / long_base;
      my_putnbr_base(nb_long, base);
      my_putchar(base[digit_display]);
    }
}
