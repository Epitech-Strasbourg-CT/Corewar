/*
** my_getnbr_base.c for my_getnbr_base in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 21:49:37 2016 Arthur Knoepflin
** Last update Mon Mar 13 22:13:22 2017 Arthur Knoepflin
*/

int	my_isneg(char *str)
{
  int	i;
  int	neg;

  i = 0;
  neg = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	neg += 1;
      i += 1;
    }
  return (neg % 2);
}

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_search(char *str, char letter)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == letter)
	return (i);
      i += 1;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	long_base;
  int	long_str;
  long	ret;
  int	temp;
  int	i;
  int	neg;

  ret = 0;
  i = 0;
  long_base = my_strlen(base);
  long_str = my_strlen(str) - 1;
  while (i < long_str)
    {
      if ((temp = my_search(base, str[i])) != -1)
	ret += temp;
      ret *= long_base;
      i += 1;
    }
  if ((temp = my_search(base, str[i])) != -1)
    ret += temp;
  if (my_isneg(str))
    ret *= (-1);
  return (ret);
}
