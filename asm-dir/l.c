#include "my.h"
#include "asm.h"

int main()
{
  int	i;
  char *str = my_char_int_to_bytes(my_unsigned_to_char(my_getunbr("-400")), &i);

  for (int n = 0; n < i; n++)
    {
      my_putchar(str[n]);
    }
}
