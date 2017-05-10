/*
** move_forward.c for move_forward in /home/pion_b/wolf3d
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Wed Dec 14 15:02:41 2016 Virgile
** Last update Wed Dec 14 15:58:46 2016 Virgile
*/

#include "my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	new_pos;
  float		angle;

  angle = direction / 180 * M_PI;
  new_pos.x = pos.x + distance * cos(angle);
  new_pos.y = pos.y + distance * sin(angle);
  return (new_pos);
}
