/*
** op.h for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Sun Mar 19 20:01:10 2017 
*/

#ifndef _OP_H_
# define _OP_H_

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

# define REG_NUMBER		16

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		5
# define NBR_LIVE		40

# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

# define REG_SIZE		1
# define IND_SIZE		4
# define DIR_SIZE		2

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef char			t_args_type;

struct		s_op
{
  char		*mnemonique;
  char		nbr_args;
  t_args_type	type[MAX_ARGS_NUMBER];
  char		code;
  int		nbr_cycles;
  char		*comment;
};

struct		s_header
{
  int		magic;
  char		prog_name[PROG_NAME_LENGTH+1];
  int		prog_size;
  char		comment[COMMENT_LENGTH+1];
};

typedef struct	s_header	t_header;
typedef struct	s_op		t_op;

extern t_op	g_op_tab[];

#endif /* !_OP_H_ */
