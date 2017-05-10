/*
** my_put_pixel.c for my_put_pixel in /home/pion_b/graph
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Nov 14 11:05:33 2016 Virgile
** Last update Fri Dec  2 13:53:54 2016 Virgile
*/

#include "my.h"

void	my_put_pixel(t_my_framebuffer *framebuffer,	\
		     int x, int y, sfColor color)
{
  int	pos;

  pos = y * framebuffer->width + x;
  if (x >= 0 && x < framebuffer->width && y >= 0 && y < framebuffer->height)
    {
      framebuffer->pixels[pos * 4] = color.r;
      framebuffer->pixels[pos * 4 + 1] = color.g;
      framebuffer->pixels[pos * 4 + 2] = color.b;
      framebuffer->pixels[pos * 4 + 3] = color.a;
    }
}
void	my_pixel(t_my_framebuffer *framebuffer,	\
		     int x, int y, sfColor color)
{
  my_put_pixel(framebuffer, x, y, color);
}
