/*
** open_bitmap.c for open_bitmap in /home/pion_b/igraph
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Thu Dec  8 10:42:31 2016 Virgile
** Last update Mon Jan 16 18:28:33 2017 Virgile
*/

#include "bitmap.h"

void		get_header(t_bitmap *b, int fd)
{
  int		i;

  i = 0;
  i = read(fd, b->useless, 10);
  i = read(fd, &b->offset, 4);
  i = read(fd, b->useless, 4);
  i = read(fd, &b->width, 4);
  i = read(fd, &b->height, 4);
  i = read(fd, &b->color_plane, 2);
  i = read(fd, &b->nb_bit, 2);
  i = read(fd, &b->compression, 4);
  i = read(fd, &b->size, 4);
  i = read(fd, &b->ppm_width, 4);
  i = read(fd, &b->ppm_height, 4);
  i = read(fd, &b->nb_color_palette, 4);
  i = read(fd, &b->nb_important_color, 4);
  (void)i;
}

void		read_bitmap(t_bitmap *b, int fd, char *buf, sfUint8 *pixel)
{
  if (b->i < b->ret)
    {
      *pixel = buf[b->i];
      b->i++;
    }
  else
    {
      b->ret = read(fd, buf, N_READ);
      b->i = 0;
      *pixel = buf[b->i];
      b->i++;
    }
}

void		get_buffer(t_bitmap *b, char *path)
{
  int		fd;
  sfColor	color;
  char		buf[N_READ];

  b->y = b->height;
  b->ret = 0;
  fd = open(path, O_RDONLY);
  b->i = read(fd, b->useless, b->offset);
  b->i = 0;
  while (b->y > 0)
    {
      b->x = 0;
      while (b->x < b->width)
	{
	  read_bitmap(b, fd, buf, &color.b);
	  read_bitmap(b, fd, buf, &color.g);
	  read_bitmap(b, fd, buf, &color.r);
	  ((b->nb_bit == 32) ?						\
	   (read_bitmap(b, fd, buf, &color.a)) : (color.a = 255));
	  my_put_pixel(b->buffer, b->x, b->y, color);
	  b->x++;
	}
      b->y--;
    }
  close(fd);
}

t_bitmap	*open_bitmap(char *path)
{
  t_bitmap	*b;
  int		fd;

  if ((b = malloc(sizeof(*b))) == NULL)
    return (NULL);
  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  get_header(b, fd);
  if ((b->buffer = my_framebuffer_create(b->width, b->height)) == NULL)
    return (NULL);
  close(fd);
  get_buffer(b, path);
  return (b);
}
