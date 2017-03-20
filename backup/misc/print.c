/*
** print.c for asm in /home/cedric/delivery/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Mon Mar 13 15:02:18 2017 
** Last update Mon Mar 13 15:09:29 2017 
*/
#include "my.h"
#include "asm.h"

/*
**deprecated
*/

void	my_putnberror(int nb)
{
  char	c;

  if (nb < 0)
    {
      my_puterror("-");
      nb *= -1;
    }
  if (nb / 10 > 0)
    my_putnberror(nb);
  c = nb % 10 + '0';
  write(2, &c, 1);
}
