/*
** raycast.c for raycast in /home/pion_b/wolf3d
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Wed Dec 14 16:02:16 2016 Virgile
** Last update Thu Jan  5 11:28:40 2017 Virgile
*/

#include "my.h"
#include <unistd.h>

void		init_step(t_ray *r, sfVector2i *step, sfVector2f *pos, sfVector2f *map)
{
  if (r->raydir.x < 0)
    {
      step->x = -1;
      r->sidedist.x = (pos->x - map->x) * r->deltadist.x;
    }
  else
    {
      step->x = 1;
      r->sidedist.x = (map->x + 1.0 - pos->x) * r->deltadist.x;
    }
  if (r->raydir.y < 0)
    {
      step->y = -1;
      r->sidedist.y = (pos->y - map->y) * r->deltadist.y;
    }
  else
    {
      step->y = 1;
      r->sidedist.y = (map->y + 1.0 - pos->y) * r->deltadist.y;
    }
}

void		init_ray(t_ray *r, float angle, sfVector2f pos, sfVector2f map)
{
  r->raydir.x = cosf(angle);
  r->raydir.y = sinf(angle);
  r->deltadist.x =  sqrtf(1.0 + (r->raydir.y * r->raydir.y)
			  / (r->raydir.x * r->raydir.x));
  r->deltadist.y =  sqrtf(1.0 + (r->raydir.x * r->raydir.x)
			  / (r->raydir.y * r->raydir.y));
  r->sidedist.x = (pos.x - map.x) * r->deltadist.x;
  r->sidedist.y = (pos.y - map.y) * r->deltadist.y;
}

void		ray_x(t_ray *r, sfVector2f *map, sfVector2i step)
{
  r->sidedist.x += r->deltadist.x;
  map->x += step.x;
  r->side = 0;
}

void		ray_y(t_ray *r, sfVector2f *map, sfVector2i step)
{
  r->sidedist.y += r->deltadist.y;
  map->y += step.y;
  r->side = 1;
}

float		raycast(sfVector2f pos, float direction, int **mmap, sfVector2i mapSize)

{
  sfVector2f    map;
  sfVector2i    step;
  t_ray		*r;

  if ((r = malloc(sizeof(*r))) == NULL)
    return (0);
  map.x = (int)pos.x;
  map.y = (int)pos.y;
  init_ray(r, direction / 180 * M_PI, pos, map);
  init_step(r, &step, &pos, &map);
  while (pos.x > 0 && pos.x < mapSize.x && pos.y > 0 && pos.y < mapSize.y)
    {
      (r->sidedist.x < r->sidedist.y) ?				\
	(ray_x(r, &map, step)) : (ray_y(r, &map, step));
      r->norm = (r->side == 0) ?				\
	((map.x - pos.x + (1 - step.x) / 2) / r->raydir.x)	\
	: ((map.y - pos.y + (1 - step.y) / 2) / r->raydir.y);
      if (map.y >= 0 && map.y < mapSize.y && map.x >= 0 &&		\
	  (map.x < mapSize.x && mmap[(int)map.x][(int)map.y] == 1))
	return (r->norm);
      if (map.y < 0 || map.y >= mapSize.y || map.x < 0 || map.x >= mapSize.x)
	  return (0);
    }
  return (0);
}
