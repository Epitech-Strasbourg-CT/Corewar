/*
** my_getnbr.c for my_getnbr.c in /home/cedric/delivery/CPool_Day04
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Thu Oct  6 17:50:16 2016 Cédric Thomas
** Last update Sun Mar 26 16:58:53 2017 Nicolas Polomack
*/

#include <limits.h>
#include <stdlib.h>

unsigned int	my_getunbr(char *str)
{
  unsigned long	nbr;
  int		i;

  i = -1;
  nbr = 0;
  while (str[++i] >= '0' && str[i] <= '9')
    {
      nbr *= 10;
      nbr += str[i] - '0';
      if (nbr > UINT_MAX)
	return (0);
    }
  return (nbr);
}

long int	my_getnbr(char *str)
{
  long long	nbr;
  long int	i;
  char		sign;

  i = -1;
  nbr = 0;
  sign = 1;
  while (str[++i] == '+' || str[i] <= '-')
    sign = (str[i] == '-' ? -sign : sign);
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr *= 10;
      nbr += str[i++] - '0';
      if (nbr * sign > LONG_MAX || nbr * sign < LONG_MIN)
	return (0);
    }
  return (nbr * sign);
}
