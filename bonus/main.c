/*
** main.c for main in /home/arthur/delivery/CPE/CPE_2016_corewar/corewar
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Feb 28 18:47:35 2017 Arthur Knoepflin
** Last update Sun Apr  2 01:16:15 2017 Nicolas Polomack
*/

#include <math.h>
#include <stdlib.h>
#include "sfcaster.h"
#include "corewar.h"
#include "my.h"
#include "op.h"

int		create_window(t_window *w, char *name,
			      int size)
{
  sfVideoMode	mode;

  mode.width = size;
  mode.height = size;
  mode.bitsPerPixel = 32;
  w->window = sfRenderWindow_create(mode, name, sfClose, NULL);
  if (w->window == NULL)
    return (-1);
  w->cols[0] = get_sfcolor(232, 66, 66, 255);
  w->cols[1] = get_sfcolor(26, 164, 26, 255);
  w->cols[2] = get_sfcolor(37, 37, 217, 255);
  w->cols[3] = get_sfcolor(118, 22, 249, 255);
  return (0);
}

int	init_buffers(t_window *w)
{
  int		size;

  size = ((int)sqrt(MEM_SIZE)) * 10;
  if ((w->buffer = assemble_texture(&w->tex, &w->spr,
				    size, size)) == NULL)
    return (-1);
  return (0);
}

void		check_events(t_window *w)
{
  sfEvent	e;

  while (sfRenderWindow_isOpen(w->window))
    if (sfRenderWindow_waitEvent(w->window, &e))
      if (e.type == sfEvtClosed ||
          (e.type == sfEvtKeyPressed &&
           e.key.code == sfKeyEscape))
        sfRenderWindow_close(w->window);
  free(w->buffer->pixels);
  free(w->buffer);
  sfTexture_destroy(w->tex);
  sfSprite_destroy(w->spr);
  sfRenderWindow_destroy(w->window);
}

void	disp_help(char *name)
{
  my_putstr("USAGE\n\t");
  my_putstr(name);
  my_putstr(" [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\n\n");
  my_putstr("DESCRIPTION\n\t-dump nbr_clycle dumbs the memory after \
the nbr_cycle execution (if the round isn't\n\t\t\t already over) with the \
following format: 32 bytes/line in\n\t\t\t hexadecimal (A0BCDEFE1DD3...)\n");
  my_putstr("\t-n prog_number   sets the next program's number. By default, \
the first free number\n\t\t\t in the parameter order\n");
  my_putstr("\t-a load_address  sets the next program's loading address.\
 When no address is\n\t\t\t specified, optimize the addresses so that \
the processes are as far\n\t\t\t away from each other as possible. \
The addresses are MEM_SIZE modulo\n");
}

int		main(int ac, char **av)
{
  t_parse	*parse;
  t_game	*g;
  t_window	w;

  if (ac == 1 || (ac > 1 && my_strcmp(av[1], "-h") == 0))
    {
      disp_help(av[0]);
      return (0);
    }
  if ((parse = get_parse(ac - 1, av + 1)) == NULL)
    return (84);
  if (create_window(&w, "Corewar", ((int)sqrt(MEM_SIZE)) * 10) == -1 ||
      init_buffers(&w))
    return (84);
  draw_grid(&w, NULL, 0);
  if ((g = game(&w, parse)) == NULL)
    return (84);
  if ((unsigned int) g->cycle <= g->parse->dump)
    my_show_live(g->msg);
  win_msg(g, &w);
  check_events(&w);
  return (0);
}
