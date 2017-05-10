/*
** sky.c for sky in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Fri Dec 23 05:52:27 2016 Virgile
** Last update Mon Jan 16 18:30:05 2017 Virgile
*/

#include "my.h"
#include "bitmap.h"

sfColor		color_pos(int x, int y, t_my_framebuffer *buffer)
{
  sfColor	color;
  int		pos;

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

void		print_map(t_data *d)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (j / 10 < d->mapSize.y)
    {
      i = 0;
      while (i / 10 < d->mapSize.x)
	{
	  if (d->map[j / 10][i / 10] == 1)
	    my_put_pixel(d->buffer, i, j, sfBlack);
	  else if ((float)(i) > d->pos_player.x * 10 &&			\
		   (float)(i) < (d->pos_player.x + 0.3) * 10 &&		\
		   (float)(j) > d->pos_player.y * 10&&			\
		   (float)(j) < (d->pos_player.y + 0.3) * 10)
	    my_put_pixel(d->buffer, i, j, sfRed);
	  else
	    my_put_pixel(d->buffer, i, j, sfWhite);
	  	  if (d->map[j / 10][i / 10] == 5)
	    my_put_pixel(d->buffer, i, j, sfBlue);
	  i++;
	}
      j++;
    }
}

char		*my_new_path(char *new_path, int n)
{
  new_path[n] = '.';
  new_path[n + 1] = 'b';
  new_path[n + 2] = 'm';
  new_path[n + 3] = 'p';
  new_path[n + 4] = '\0';
  return (new_path);
}

char		*get_path(char *path, int i)
{
  int		nb_digit;
  int		nb;
  int		nb_digit_copy;
  char		*new_path;
  int		n;

  nb = i + 1;
  nb_digit = 1;
  i = (i + 1) * 10;
  while ((i /= 10) > 9 && ((n = -1) == -1))
    nb_digit++;
  if ((new_path = malloc((my_strlen(path) + 7) * sizeof(char *))) == NULL)
    return (NULL);
  while (++n < my_strlen(path) && ((i = -1) == -1))
    new_path[n] = path[n];
  while (++i < 3 - nb_digit)
    new_path[n++] = '0';
  i = -1;
  nb_digit_copy = nb_digit;
  while (++i < nb_digit_copy)
    {
      new_path[n++] = nb / pow(10, nb_digit - 1) + '0';
      nb = nb % (int)pow(10, nb_digit-- - 1);
    }
  return (my_new_path(new_path, n));
}

void		thread_go(t_data *d, sfThread *thread)
{
  (void)d;
  sfThread_wait(thread);
  sfThread_terminate(thread);
}
