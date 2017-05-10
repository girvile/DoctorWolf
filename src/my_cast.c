/*
** my_cast.c for  in /home/pion_b/wolf3d
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Wed Dec 21 12:36:10 2016 Virgile
** Last update Sat Jan 14 22:14:23 2017 Virgile
*/

#include "my.h"
#include <stdio.h>

void		ini_step(t_ray *r)
{
  r->token = 0;
  r->angel.y = 0;
  r->angel.x = 0;
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

void		ini_ray(t_ray *r, float angle, sfVector2f pos)
{
  r->dir.x = cosf(angle);
  r->dir.y = sinf(angle);
  r->raydir.x = r->dir.x;
  r->raydir.y = r->dir.y;
  r->deltadist.x =  sqrtf(1.0 + (r->raydir.y * r->raydir.y)
			  / (r->raydir.x * r->raydir.x));
  if (r->deltadist.x > 0 && r->deltadist.x < 0.1)
    r->deltadist.x = 0.1;
  if (r->deltadist.x < 0 && r->deltadist.x > -0.1)
    r->deltadist.x = -0.1;
  r->deltadist.y =  sqrtf(1.0 + (r->raydir.x * r->raydir.x)
			  / (r->raydir.y * r->raydir.y));
  if (r->deltadist.y > 0 && r->deltadist.y < 0.1)
    r->deltadist.y = 0.1;
  if (r->deltadist.y < 0 && r->deltadist.y > -0.1)
    r->deltadist.y = 0.1;
  r->sidedist.x = (pos.x - r->map.x) * r->deltadist.x;
  r->sidedist.y = (pos.y - r->map.y) * r->deltadist.y;
  r->pos.x = (float)pos.x;
  r->pos.y = (float)pos.y;
  r->map.x = (int)pos.x;
  r->map.y = (int)pos.y;
  ini_step(r);
}

void		my_thread_cast(void *data)
{
  t_data	*d;
  int		x;

  d = (t_data *)data;
  x = -1;
  d->r = rcast(d->pos_player, d->angle, d, d->mapSize);
  d->real = d->r->norm;
  d->real_angel = d->r->angel.x;
  while (++x < WTH)
    {
      if (x % 1 == 0)
	{
	  d->new_angle = ((d->angle - (d->fov / 2)) +
			  ((x / (float)WTH) * d->fov));
	  d->r = rcast(d->pos_player, d->new_angle, d, d->mapSize);
	  if (d->r->map.y < 0 || d->r->map.y >= d->mapSize.y ||
	      d->r->map.x < 0 || d->r->map.x >= d->mapSize.x)
	    d->r->norm = 0;
	  d->real = d->r->norm;
	  d->r->norm = d->r->norm * cosf((d->angle - d->new_angle) / 180 * M_PI);
	  d->r->angel.y = d->r->angel.y * cosf((d->angle -			\
						d->new_angle) / 180 * M_PI);
	  make_walls(d, x);
	}
    }
}

void		my_cast(t_data *d)
{
  sfThread_launch(d->thread_cast);
  sfThread_wait(d->thread_cast);
}
