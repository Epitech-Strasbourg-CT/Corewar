/*
** op.h for op in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Mar 14 13:40:17 2017 Arthur Knoepflin
** Last update Thu Mar 16 20:58:24 2017 Arthur Knoepflin
*/

#ifndef OP_H_
# define OP_H_

# define MEM_SIZE		(6*1024)
# define IDX_MOD		512
# define MAX_ARGS_NUMBER	4
# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

/*
** regs
*/

# define REG_NUMBER	16

typedef char	t_args_type;

# define T_REG	1
# define T_DIR	2
# define T_IND	4
# define T_LAB	8

struct		s_op
{
  char		*mnemonique;
  char		nbr_args;
  t_args_type	type[MAX_ARGS_NUMBER];
  char		code;
  int		nbr_cycles;
  char		*comment;
};

typedef struct s_op	t_op;

/*
** size (in bytes)
*/

# define REG_SIZE	4
# define IND_SIZE	2
# define DIR_SIZE	REG_SIZE

/*
** op_tab
*/

extern	t_op	op_tab[];

/*
** header
*/

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

struct	s_header
{
  int	magic;
  char	prog_name[PROG_NAME_LENGTH + 1];
  int	prog_size;
  char	comment[COMMENT_LENGTH + 1];
};

typedef struct s_header t_header;

/*
** live
*/

# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA	5
# define NBR_LIVE	40

#endif /* !OP_H_ */
