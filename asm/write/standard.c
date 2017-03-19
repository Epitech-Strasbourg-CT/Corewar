#include "asm.h"
#include "op.h"

void	write_standard(t_instruct *current, t_asm *myasm)
{
  int	i;
  t_op	*op;

  i = -1;
  op = current->op;
  while (++i < op->nbr_args)
    {
      if (op->type[i] == T_REG)
	write_standard_reg(current, i, myasm);
      else if ((op->type[i] & T_IND) == T_IND)
	write_standard_ind(current, i, myasm);
      else if ((op->type[i] & T_DIR) == T_DIR)
	write_standard_dir(current, i, myasm);
    }
}
