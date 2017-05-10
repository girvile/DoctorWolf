/*
** rcast.c for rcast in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sat Jan 14 21:37:15 2017 Virgile
** Last update Sat Jan 14 22:09:50 2017 Virgile
*/

#include "my.h"


void		special_cast(t_ray *r, t_data *d, float direction)
{
  r->token = 1;
  d->spe_bloc = d->map[(int)r->map.y][(int)r->map.x];
  r->angel.y = r->norm;
  r->angel.x = ((r->side == 0) ?                        \
		(r->pos.y + r->angel.y * r->raydir.y) : \
		(r->pos.x + r->angel.y * r->raydir.x));
  r->angel.x -= floor(r->angel.x);
  if (d->clic == 1 && direction == d->angle     \
      && d->spe_bloc == 4 && d->porte == 0)
    {
      d->map[(int)r->map.y][(int)r->map.x] = 3;
      sfMusic_play(d->open);
      d->porte = 1;
    }
  if (direction == d->angle && d->spe_bloc == 2)
    d->start = 3;
}

t_ray		*normal_cast(t_ray *r, t_data *d, float direction)
{
  d->bloc = d->map[(int)r->map.y][(int)r->map.x];
  if (d->clic == 1 && direction == d->angle && d->bloc == 3     \
      && d->porte == 0)
    {
      d->map[(int)r->map.y][(int)r->map.x] = 4;
      sfMusic_play(d->close);
      d->porte = 1;
    }
  return (r);
}

void		init_cast_loop(t_ray *r, sfVector2f pos)
{
       if (r->sidedist.x < r->sidedist.y)
	 r_x(r);
       else
	 r_y(r);
       r->norm = ((r->side == 0) ?					\
		 ((r->map.x - pos.x + (1 - r->step.x) / 2) / r->raydir.x) \
		  : ((r->map.y - pos.y + (1 - r->step.y) / 2) / r->raydir.y));
}

t_ray		*rcast(sfVector2f pos,
		       float direction, t_data *d, sfVector2i mapSize)

{
  t_ray		*r;

  if ((r = malloc(sizeof(*r))) == NULL)
    return (NULL);
  ini_ray(r, direction / 180 * M_PI, pos);
  while (r->pos.x < mapSize.x && r->pos.y < mapSize.y)
    {
      init_cast_loop(r, pos);
      if ((r->map.y >= 0 && r->map.y < mapSize.y && r->map.x >= 0 &&	\
	   r->map.x < mapSize.x) && ((d->map[(int)r->map.y][(int)r->map.x] == 1) || \
				     (d->map[(int)r->map.y][(int)r->map.x] == 3)))
	return (normal_cast(r, d, direction));
      if (r->map.y >= 0 && r->map.y < mapSize.y && r->map.x >= 0 &&     \
	            r->map.x < mapSize.x &&                                       \
	  (d->map[(int)r->map.y][(int)r->map.x] == 2 ||                 \
	   d->map[(int)r->map.y][(int)r->map.x] == 4 ||                 \
	   d->map[(int)r->map.y][(int)r->map.x] == 5)&&         \
	  r->token == 0)
	special_cast(r, d, direction);
       if (r->map.y < 0 || r->map.y >= mapSize.y ||
	  r->map.x < 0 || r->map.x >= mapSize.x)
	return (r);
    }
  return (r);
}
