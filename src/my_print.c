/*
** my_print.c for my_print in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sat Jan 14 21:13:31 2017 Virgile
** Last update Sat Jan 14 22:38:36 2017 Virgile
*/

#include "my.h"

void		print_sky(t_data *d)
{
  sfVector2i	pos;
  sfColor	color;
  int		x_pos;


  pos.x = 0;
  pos.y = 0;
  while (pos.y < HGT / 2)
    {
      pos.x = 0;
      while (pos.x < WTH)
	{
	  x_pos = pos.x + d->sky_pas;
	  while (x_pos >= 2 * WTH)
	    x_pos -= 2 * WTH;
	  while (x_pos < 0)
	    x_pos += 2 * WTH - 1;
	  color = color_pos(x_pos, pos.y, d->sky);
	  if (color.a != 0)
	    my_put_pixel(d->buffer, pos.x, pos.y, color);
	  pos.x++;
	}
      pos.y++;
    }
}

void		print_rateau(t_data *d)
{
  sfColor	color;
  int		x;
  int		y;
  int		i;
  int		j;

  j = 0;
  y = HGT - 512;
  x = WTH / 2 - (d->rateau->width / 2);
  while (y < HGT)
    {
      i = 0;
      x = WTH / 2 - (d->rateau->width / 2);
      while (i < 512)
	{
	  color = ((d->clic == 0) ?                                     \
		   (color_pos(i, j, d->rateau)) : (color_pos(i, j, d->rateau2)));
	  if ((color.r < 110 || color.g > 30 || color.b < 110) && j > 1)
	    my_put_pixel(d->buffer, x, y, color);
	  x++;
	  i++;
	}
      j++;
      y++;
    }
}


void		print_video(t_my_framebuffer *buffer, t_my_framebuffer *pic)
{
  int		x;
  int		y;
  int		pos;
  sfColor	color;

  y = 0;
  while (y < pic->height)
    {
      x = 0;
      while (x < pic->width)
	{
	  pos = y * pic->width + x;
	  color.r = pic->pixels[pos * 4];
	  color.g = pic->pixels[pos * 4 + 1];
	  color.b = pic->pixels[pos * 4 + 2];
	  color.a = pic->pixels[pos * 4 + 3];
	  my_put_pixel(buffer, x + (WTH - pic->width)           \
		       / 2, y + (HGT - pic->height) / 2, color);
	  x++;
	}
      y++;
    }
}

void		print_titre(t_my_framebuffer *buffer, t_my_framebuffer *titre)
{
  int		x;
  int		y;
  sfColor	color;
  int		pos;

  y = 0;
  while (y < titre->height)
    {
      x = 0;
      while (x < titre->width)
	{
	  pos = y * titre->width + x;
	  color.r = titre->pixels[pos * 4];
	  color.g = titre->pixels[pos * 4 + 1];
	  color.b = titre->pixels[pos * 4 + 2];
	  color.a = 255;
	  if (color.r < 150 || color.g > 30 || color.b < 150)
	    my_put_pixel(buffer, x, y, color);
	  x++;
	}
      y++;
    }
}

void		print_loose(t_my_framebuffer *buffer, t_my_framebuffer *loose)
{
  int		x;
  int		y;
  int		pos;
  sfColor	color;

  x = 0;
  y = 0;
  while (y < loose->height)
    {
      x = 0;
      while (x < loose->width)
	{
	  pos = y * loose->width + x;
	  color.r = loose->pixels[pos * 4];
	  color.g = loose->pixels[pos * 4 + 1];
	  color.b = loose->pixels[pos * 4 + 2];
	  color.a = loose->pixels[pos * 4 + 3];
	  my_put_pixel(buffer, x, y, color);
	  x++;
	}
      y++;
    }
}
