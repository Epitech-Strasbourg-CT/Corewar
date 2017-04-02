/*
** draw.c for corewar-vm in /home/nicolaspolomack/cpe/2/CPE_2016_corewar/bonus
** 
** Made by Nicolas Polomack
** Login   <nicolas.polomack@epitech.eu>
** 
** Started on  Sat Apr  1 18:03:10 2017 Nicolas Polomack
** Last update Sun Apr  2 03:16:18 2017 Nicolas Polomack
*/

#include "corewar.h"
#include "sfcaster.h"

sfVector2i	prepare(sfVector2i vec, int i)
{
  vec.x += i;
  vec.y += i;
  return (vec);
}

void		update_frame(t_window *w)
{
  sfTexture_updateFromPixels(w->tex, w->buffer->pixels,
                             w->buffer->width,
                             w->buffer->height, 0, 0);
  sfRenderWindow_drawSprite(w->window, w->spr, NULL);
  sfRenderWindow_display(w->window);
}

void		draw_heads(t_window *w, t_game *game,
			   sfVector2i pos, sfVector2i sizes)
{
  t_heads	*head;

  pos.y = 0;
  while (pos.y < w->buffer->height)
    {
      pos.x = 0;
      while (pos.x < w->buffer->width)
	{
	  head = game->heads;
	  while (head)
	    if (head->pos == (pos.y / sizes.y) *
		(w->buffer->width / sizes.y) +
		(pos.x / sizes.x))
	      {
		draw_square(w->buffer, prepare(pos, 1),
			    prepare(sizes, -2),
			    w->cols[head->id - 1]);
		break;
	      }
	    else
	      head = head->next;
	  pos.x += sizes.x;
	}
      pos.y += sizes.y;
    }
}

void		draw_grid(t_window *w, t_game *game, int won)
{
  sfVector2i	pos;
  sfVector2i	sizes;

  pos.y = 0;
  sizes.x = 10;
  sizes.y = 10;
  while (pos.y < w->buffer->height)
    {
      pos.x = 0;
      while (pos.x < w->buffer->width)
        {
	  draw_square(w->buffer, pos, sizes, sfBlack);
          draw_square(w->buffer, prepare(pos, 1), prepare(sizes, -2),
		      (won) ? w->cols[won - 1] :
		      (!game || game->arena[(pos.y / sizes.y) *
					    (w->buffer->width / sizes.y) +
					    (pos.x / sizes.x)] == 0) ?
		      sfWhite : get_sfcolor(83, 83, 83, 255));
          pos.x += sizes.x;
        }
      pos.y += sizes.y;
    }
  if (game && !won)
    draw_heads(w, game, pos, sizes);
  update_frame(w);
}
