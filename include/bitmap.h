/*
** bitmap.h for bitmap in /home/pion_b/igraph
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Thu Dec  8 10:43:55 2016 Virgile
** Last update Tue Jan 10 16:57:38 2017 Virgile
*/

#ifndef BITMAP_H_
#define BITMAP_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

#define N_READ (100000)

typedef struct	s_bitmap
{
  int			offset;
  unsigned int		width;
  unsigned int		height;
  int			color_plane;
  short			nb_bit;
  int			compression;
  int			size;
  int			ppm_width;
  int			ppm_height;
  int			nb_color_palette;
  int			nb_important_color;
  int			useless[100];
  t_my_framebuffer	*buffer;
  int			ret;
  unsigned int	       	x;
  unsigned int		y;
  int		   	i;
}		t_bitmap;

t_bitmap	*open_bitmap(char *path);

#endif /*BITMAP_H_*/
