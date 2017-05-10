/*
** my_cast.c for  in /home/pion_b/wolf3d
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Wed Dec 21 12:36:10 2016 Virgile
** Last update Sat Jan 14 20:39:34 2017 Virgile
*/

#include "my.h"

void		ini_step(t_ray *r)
{
  if (r->raydir.x < 0)
    {
      r->step.x = -1;
      r->sidedist.x = (r->pos.x - r->map.x) * r->deltadist.x;
    }
  else
    {
      r->step.x = 1;
      r->sidedist.x = (r->map.x + 1.0 - r->pos.x) * r->deltadist.x;
    }
  if (r->raydir.y < 0)
    {
      r->step.y = -1;
      r->sidedist.y = (r->pos.y - r->map.y) * r->deltadist.y;
    }
  else
    {
      r->step.y = 1;
      r->sidedist.y = (r->map.y + 1.0 - r->pos.y) * r->deltadist.y;
    }
}

void		ini_ray(t_ray *r, float angle, sfVector2f pos, t_data *d)
{
  (void)angle;
  r->camera = d->camera;
  r->plane = d->plane;
  r->dir.x = d->dir.x;
  r->dir.y = d->dir.y;
  r->raydir.x = r->dir.x + r->plane.x * r->camera.x;
  r->raydir.y = r->dir.y + r->plane.y * r->camera.x;
  r->deltadist.x =  sqrtf(1.0 + (r->raydir.y * r->raydir.y)
			  / (r->raydir.x * r->raydir.x));
  r->deltadist.y =  sqrtf(1.0 + (r->raydir.x * r->raydir.x)
			  / (r->raydir.y * r->raydir.y));
  r->sidedist.x = (pos.x - r->map.x) * r->deltadist.x;
  r->sidedist.y = (pos.y - r->map.y) * r->deltadist.y;
  r->pos.x = (float)pos.x;
  r->pos.y = (float)pos.y;
  r->map.x = (int)pos.x;
  r->map.y = (int)pos.y;
}

t_ray		*rcast(sfVector2f pos,
			float direction, t_data *d, sfVector2i mapSize)

{
  t_ray		*r;

  if ((r = malloc(sizeof(*r))) == NULL)
    return (NULL);
  ini_ray(r, direction / 180 * M_PI, pos, d);
  ini_step(r);
  while (r->pos.x > 0 && r->pos.x < mapSize.x &&
	 r->pos.y > 0 && r->pos.y < mapSize.y)
    {
      (r->sidedist.x < r->sidedist.y) ?                         \
	(r_x(r)) : (r_y(r));
      r->norm = ((r->side == 0) ?					\
		 ((r->map.x - pos.x + (1 - r->step.x) / 2) / r->raydir.x) \
		 : ((r->map.y - pos.y + (1 - r->step.y) / 2) / r->raydir.y));
      if (r->map.y >= 0 && r->map.y < mapSize.y && r->map.x >= 0 &&	\
	  (r->map.x < mapSize.x && d->map[(int)r->map.y][(int)r->map.x] == 1))
	return (r);
      if (r->map.y < 0 || r->map.y >= mapSize.y ||
	  r->map.x < 0 || r->map.x >= mapSize.x)
	return (r);
    }
  r->norm = 0;
  return (r);
}

void		my_cast(t_data *d)
{
  float		x;
  sfVector2i	from;
  sfVector2i	to;
  int		lineheight;

  x = 0;
  while (x < WTH)
    {
      d->camera.x = 2 * x / (double)WTH - 1;
      d->r = rcast(d->pos_player, d->angle, d, d->mapSize);
      if (d->r->map.y < 0 || d->r->map.y >= d->mapSize.y ||
	  d->r->map.x < 0 || d->r->map.x >= d->mapSize.x)
	d->r->norm = 0;
      lineheight = (int)((float)HGT / d->r->norm);
      from.x = x;
      to.x = x;
      from.y = HGT / 2 - lineheight / 2;
      to.y = HGT / 2 + lineheight / 2;
      if (d->r->side == 0)
	my_draw_line(d->buffer, from, to, sfRed);
      else
	my_draw_line(d->buffer, from, to, sfBlue);
      x++;
    }
}
