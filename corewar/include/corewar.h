/*
** corewar.h for corewar in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Thu Mar  9 19:04:34 2017 Arthur Knoepflin
** Last update Wed Mar 29 17:58:36 2017 Arthur Knoepflin
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "op.h"

# define BUF_SIZE	2048

typedef struct		s_live
{
  char			*name;
  struct s_live		*prev;
  struct s_live		*next;
}			t_live;

typedef struct	s_nchamp
{
  int		id;
  int		load_addr;
  char		*path;
  int		size;
  char		*name;
  char		*comment;
  char		*code;
}		t_nchamp;

typedef struct		s_heads
{
  int			id;
  int			reg[16];
  int			ctn_cycle;
  int			carry;
  int			pos;
  struct s_heads	*next;
}			t_heads;

typedef struct		s_parse
{
  unsigned int		dump;
  int			nb_champ;
  struct s_nchamp	*champ[4];
}			t_parse;

typedef struct	s_ins
{
  int		nb_arg;
  int		cmd;
  int		type[4];
  long		val[4];
  int		tot_byte;
}		t_ins;

typedef struct	s_game
{
  int		*live;
  t_parse	*parse;
  unsigned char	*arena;
  int		old_cycle_verrif;
  int		cycle;
  int		cycle_to_die;
  int		old_check;
  t_heads	*heads;
  t_heads	*read;
  t_live	*msg;
}		t_game;

/*
** arena/arena_create.c
*/

unsigned char	*arena_create(void);
int		init_arena(t_game *);

/*
** arena/average_champ.c
*/

int	get_ecart(t_parse *);

/*
** arena/is_overlap.c
*/

int	*get_tab_pos(t_parse *, int);
int	is_overlap_lock(t_parse *);

/*
** arena/load_champ.c
*/

int	nb_champ_with_addr(t_parse *);
int	load_champ(t_game *, t_nchamp *, int);
int	load_all_champ(t_game *, int);
int	load_champ_addr(t_game *, int);

/*
** dump.c
*/

void	dump(t_game *);

/*
** endian.c
*/

void	swap_endian(void *, int);

/*
** fnt_tab.c
*/

void	get_fnt_tab(void (*fnt[16])(t_game *, t_heads *, t_ins *));

/*
** fnt/live.c
*/

void	live(t_game *, t_heads *, t_ins *);

/*
** fnt/ld.c
*/

void	ld(t_game *, t_heads *, t_ins *);

/*
** fnt/st.c
*/

void	st(t_game *, t_heads *, t_ins *);

/*
** fnt/add.c
*/

void	add(t_game *, t_heads *, t_ins *);

/*
** fnt/sub.c
*/

void	sub(t_game *, t_heads *, t_ins *);

/*
** fnt/and.c
*/

void	and(t_game *, t_heads *, t_ins *);

/*
** fnt/or.c
*/

void	or(t_game *, t_heads *, t_ins *);

/*
** fnt/xor.c
*/

void	xor(t_game *, t_heads *, t_ins *);

/*
** fnt/zjmp.c
*/

void	zjmp(t_game *, t_heads *, t_ins *);

/*
** fnt/ldi.c
*/

void	ldi(t_game *, t_heads *, t_ins *);

/*
** fnt/sti.c
*/

void	sti(t_game *, t_heads *, t_ins *);

/*
** fnt/fork.c
*/

void	fork_head(t_game *, t_heads *, t_ins *);

/*
** fnt/lld.c
*/

void	lld(t_game *, t_heads *, t_ins *);

/*
** fnt/lldi.c
*/

void	lldi(t_game *, t_heads *,t_ins *);

/*
** fnt/lfork.c
*/

void	lfork(t_game *, t_heads *, t_ins *);

/*
** fnt/aff.c
*/

void	aff(t_game *, t_heads *, t_ins *);

/*
** game.c
*/

int	game(t_parse *);

/*
** head/exec_head.c
*/

void	exec_head(t_game *,
		  t_heads *,
		  void (*fnt[16])(t_game *, t_heads *, t_ins *));

/*
** head/head.c
*/

int	new_head(t_heads, t_heads **);
int	delete_heads(t_heads *, t_heads **);

/*
** head/init_head.c
*/

void	init_head(t_game *);

/*
** head/kill_player.c
*/

void	kill_player(t_game *, int);

/*
** instruct/error_desc.c
*/

int	error_desc(t_ins *);

/*
** instruct/get_arg.c
*/

int	extract_val(unsigned char *, int);
int	get_arg(t_game *, int, t_ins *);

/*
** instruct/get_desc.c
*/

int	get_desc(int, t_ins *);

/*
** instruct/get_instruc.c
*/

t_ins	*get_instruc(t_game *, int);

/*
** live.c
*/

int	init_live(t_game *);
void	update_live(t_game *);
void	check_live(t_game *, int *);

/*
** parse/parse.c
*/

t_parse	*get_parse(int, char **);

/*
** parse/parse_champ.c
*/

int	parse_champ(t_parse *, int, char **);

/*
** parse/parse_error.c
*/

int	is_an_arg(char *);
int	check_error(int, char **);

/*
** parse/parse_error_2.c
*/

int	print_unknown_arg(char *);
int	check_valid_arg(int, char **);
int	check_nb_champ(int, char **);

/*
** parse/parse_get_list_id.c
*/

char	*get_list_id(int, char **);
int	check_id(int, char **);

/*
** parse/parse_file_champ.c
*/

int	parse_file_champ(t_parse *);

/*
** parse/parse_file.c
*/

int	read_comment(int, char *, t_nchamp *);
int	read_name(int, char *, t_nchamp *);
int	check_magic_number(int, char *);
int	parse_header(int, char *, t_nchamp *);

/*
** parse/read_file.c
*/

char	*read_file(int);

#endif /* !COREWAR_H_ */
