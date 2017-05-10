/*
** r_xy.c for r_xy in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sat Jan 14 20:38:17 2017 Virgile
** Last update Sat Jan 14 20:40:33 2017 Virgile
*/

#include "my.h"

void		r_x(t_ray *r)
{
  r->sidedist.x += r->deltadist.x;
  r->map.x += r->step.x;
  r->side = 0;
}

void		r_y(t_ray *r)
{
  r->sidedist.y += r->deltadist.y;
  r->map.y += r->step.y;
  r->side = 1;
}
