/*
** my_draw_wall.c for wall in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sun Dec 25 19:51:32 2016 Virgile
** Last update Sat Jan 14 22:19:10 2017 Virgile
*/

#include "my.h"

sfColor		get_color(t_my_framebuffer *buffer, int i, int h, float wall)
{
  sfColor	color;
  int		pos;
  int		x;
  int		y;

  x = wall * buffer->width;
  y = ((float)i / (float)h) * (buffer->height);
  pos = y * buffer->width + x;
  if (x >= 0 && x < buffer->width && y >= 0 && y < buffer->height)
    {
      color.r = buffer->pixels[pos * 4];
      color.g = buffer->pixels[pos * 4 + 1];
      color.b = buffer->pixels[pos * 4 + 2];
      color.a = buffer->pixels[pos * 4 + 3];
    }
  return (color);
}


void		my_draw_wall(t_data *d, sfVector2i from, sfVector2i to, float wall)
{
  int		h;
  int		i;
  sfColor	color;

  i = 1;
  h = to.y - from.y;
  while (i < h)
    {
      if (from.y + i < HGT)
	{
	  if (d->bloc == 1)
	    color = get_color(d->wall, i, h, wall);
	  if (d->bloc == 3)
	    color = get_color(d->closedoor, i, h, wall);
	  if (d->r->side == 1)
	    {
	      color.r /= 2;
	      color.g /= 2;
	      color.b /= 2;
	    }
	  my_put_pixel(d->buffer, from.x, from.y + i, color);
	}
      i++;
    }
}

void		my_draw_angel(t_data *d, sfVector2i from, sfVector2i to, float wall)
{
  int		h;
  int		i;
  sfColor	color;

  i = 1;
  h = to.y - from.y;
  while (i < h)
    {
      if (from.y + i < HGT)
	{
	  if (d->spe_bloc == 2)
	    color = get_color(d->ange, i, h, wall);
	  if (d->spe_bloc == 4)
	    color = get_color(d->opendoor, i, h, wall);
	  if (d->spe_bloc == 5)
	    color = get_color(d->tardis, i, h, wall);
	  if (color.r < 245 && color.b < 245 && color.g > 5)
	    my_put_pixel(d->buffer, from.x, from.y + i, color);
	}
      i++;
    }
}


void		make_walls(t_data *d, float x)
{
  sfVector2i	from;
  sfVector2i	to;
  int		lineheight;
  int		height_angel;
  sfVector2f	wall;

  lineheight = (int)((float)HGT / (d->r->norm));
  height_angel = (int)((float)HGT / (d->r->angel.y));
  from.x = x;
  to.x = x;
  from.y = HGT / 2 - lineheight / 2;
  to.y = HGT / 2 + lineheight / 2;
  wall.x = d->r->pos.y + d->real * d->r->raydir.y;
  wall.y = d->r->pos.x + d->real * d->r->raydir.x;
  wall.x -= floor(wall.x);
  wall.y -= floor(wall.y);
  (d->r->side == 0) ? (my_draw_wall(d, from, to, wall.x))	\
    : (my_draw_wall(d, from, to, wall.y));
  from.x = x;
  to.x = x;
  from.y = (d->spe_bloc == 5) ? (HGT / 2 - height_angel * 1.5)	\
    : (HGT / 2 - height_angel / 2);
  to.y = HGT / 2 + height_angel / 2;
  if (d->r->angel.y > 0.3)
    my_draw_angel(d, from, to, d->r->angel.x);
}
