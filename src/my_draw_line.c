/*
** my_draw_line.c for my_draw_line.c in /home/pion_b/wireframe
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Nov 14 13:18:06 2016 Virgile
** Last update Wed Nov 23 00:23:32 2016 Virgile
*/

#include "my.h"

float		get_coef(int a, int b, int c, int d)
{
  float		xa;
  float		xb;
  float		ya;
  float		yb;

  xa = (float)a;
  xb = (float)b;
  ya = (float)c;
  yb = (float)d;
  return ((yb - ya) / (xb - xa));
}


void		my_put_line(t_my_framebuffer *framebuffer, sfVector2i from,	\
		    sfVector2i to, sfColor color)
{
  sfVector2i	tmp;
  float		coef;

  tmp.x = from.x;
  tmp.y = from.y;
  coef = get_coef(from.x, to.x, from.y, to.y);
  while ((tmp.x < to.x && coef < 1 && coef >= 0	)	\
	 ||(tmp.x < to.x && coef < 0 && coef > -1))
    {
      tmp.x++;
      tmp.y = to.y + ((tmp.x - to.x) * coef);
      my_put_pixel(framebuffer, tmp.x, tmp.y, color);
    }
  while (tmp.y < to.y && coef >= 1 && coef != 0)
    {
      tmp.y++;
      tmp.x = to.x + ((tmp.y - to.y) / coef);
      my_put_pixel(framebuffer, tmp.x, tmp.y, color);
    }
  while (tmp.y > to.y && coef <= -1 && coef != 0)
    {
      tmp.y--;
      tmp.x = to.x + ((tmp.y - to.y) / coef);
      my_put_pixel(framebuffer, tmp.x, tmp.y, color);
    }
}


void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,	\
		     sfVector2i to, sfColor color)
{
  sfVector2i	tmp;

  if (to.x < from.x)
    {
      tmp.x = to.x;
      to.x = from.x;
      from.x = tmp.x;
      tmp.y = to.y;
      to.y = from.y;
      from.y = tmp.y;
    }
  my_put_line(framebuffer, from, to, color);
}
