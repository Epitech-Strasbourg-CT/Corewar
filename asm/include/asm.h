/*
** asm.h for asm_corware in /home/cedric/delivery/CPE/CPE_2016_corewar
** 
** Made by 
** Login   <cedric.thomas@epitech.eu>
** 
** Started on  Wed Mar  1 09:59:16 2017 
** Last update Sun Mar 19 19:41:18 2017 
*/
#ifndef ASM_H_
# define ASM_H_

# define MAX_OPCODE	16

typedef struct	s_op	t_op;

typedef struct		s_label
{
  char			*name;
  char			*line;
  struct s_label	*prev;
  struct s_label	*next;
}			t_label;

typedef struct		s_instruct
{
  char			*raw;
  t_op			*op;
  char			**args;
  struct s_instruct	*prev;
  struct s_instruct	*next;
}			t_instruct;

typedef struct		s_mheader
{
  char			*name;
  char			*comment;
}			t_mheader;

typedef struct		s_asm
{
  char			**file;
  int			fd;
  char			*file_name;
  t_mheader		header;
  t_label		*labels;
  t_instruct		*instructs;
}			t_asm;

/*
**commands.c
*/
void	parse_commands(t_asm *a);

/*
** file.c
*/

void	display_file(char **file);
char	**my_realloc(char **file, char *line, int size);
int	read_file(t_asm *a, char *file);
int	check_dir(char *file);

/*
** header.c
*/

void	parse_headers(t_asm *a);

/*
** my_int_to_char.c
*/
char	*my_unsigned_to_char(unsigned int nbr);

/*
**bitshift.c
*/
char	*my_char_int_to_bytes(char *str, int *packets);
void	print_mem_char(char c, int zero);
int	get_prog_size(t_instruct *instr);

/*
** error.c
*/

void	error_header(int, int, int);
int	error_double_label(t_label **my_label, char *name);

/*
**MISC
*/

/*
**tab.c
*/
char	**epurtab(t_asm *my_asm);
char	**my_cpyrealloc(char **old, int new_size);

/*
**str.c
*/
int	my_cstrnlen(char *str, char c);
int	my_strnlen(char *str, char *c);
char	*my_strndup(char *str, int len);
int	is_only_composed_of(char *str, char *only_composed);

/*
**endian.c
*/

void		swap_endian(void *raw, int size);

/*
**epurstr.c
*/

char	*my_epurnstr(char *str, int nbspace, char *to_ep, char replace);

/*
**LABEL
*/

/*
**label.c
*/

int	change_label(t_asm *my_asm);

/*
**list_label.c
*/
int	my_put_list_label(t_label **ll, char *name, char *line);
int	my_show_label(t_label *ll);
int	my_del_list_label(t_label **ll, t_label *elem);
int	my_free_label(t_label **ll);

/*
**size.c
*/
int	label_to_addr(t_asm *myasm, t_instruct *current, char *name, int *error);

/*
**INSTRUCT
*/

/*
**instruct.c
*/

int	get_instruct_size(t_instruct *instruct);
int	write_args_type(t_instruct *instruct, int fd);
int	load_instruct(t_asm *my_asm);

/*
**list_instruct.c
*/
int	my_put_list_instruct(t_instruct **ll, char *raw);
int	my_show_instruct(t_instruct *ll);
int	my_del_list_instruct(t_instruct **ll, t_instruct *elem);
int	my_free_instruct(t_instruct **ll);

/*
**write_instructs.c
*/

int	write_instructs(t_instruct *instructs, t_asm *myasm);

/*
**WRITE
*/

/*
**standard.c
*/
void	write_standard_reg(t_instruct *instruct, int index, t_asm *myasm);
void	write_standard_dir(t_instruct *instruct, int index, t_asm *myasm);
void	write_standard_ind(t_instruct *instruct, int index, t_asm *myasm);
void	write_standard(t_instruct *current, t_asm *myasm);

/*
**write.c
*/
void	write_simple_instruct(t_instruct *instruct, t_asm *myasm);
void	write_live_instruct(t_instruct *instruct, t_asm *myasm);
void	write_math_instruct(t_instruct *instruct, t_asm *myasm);
void	write_logic_instruct(t_instruct *instruct, t_asm *myasm);

#endif /* !ASM_H_ */
