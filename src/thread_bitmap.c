/*
** thread_bitmap.c for thread_bitmap in /home/pion_b/wolf3d/bonus
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Sat Jan 14 20:53:54 2017 Virgile
** Last update Sat Jan 14 21:08:52 2017 Virgile
*/

#include "my.h"
#include "bitmap.h"

void		thread_bitmap(void *data)
{
  t_data	*d;
  t_bitmap	*video;
  int		i;

  i = 0;
  while (i < 584)
    {
      if (i % 4 == 0)
	{
	  d = (t_data *)data;
	  video = NULL;
	  video = open_bitmap(get_path(d->path_pic, i));
	  if (video != NULL)
	    d->video[i] = video->buffer;
	}
      i++;
    }
}

void		thread_bitmap2(void *data)
{
  t_data	*d;
  t_bitmap	*video;
  int		i;

  i = 0;
  while (i < 584)
    {
      if (i % 4 == 1)
	{
	  d = (t_data *)data;
	  video = NULL;
	  video = open_bitmap(get_path(d->path_pic, i));
	  if (video != NULL)
	    d->video[i] = video->buffer;
	}
      i++;
    }
}

void		thread_bitmap3(void *data)
{
  t_data	*d;
  t_bitmap	*video;
  int		i;

  i = 0;
  while (i < 584)
    {
      if (i % 4 == 2)
	{
	  d = (t_data *)data;
	  video = NULL;
	  video = open_bitmap(get_path(d->path_pic, i));
	  if (video != NULL)
	    d->video[i] = video->buffer;
	}
      i++;
    }
}

void		thread_bitmap4(void *data)
{
  t_data	*d;
  t_bitmap	*video;
  int		i;

  i = 0;
  while (i < 584)
    {
      if (i % 4 == 3)
	{
	  d = (t_data *)data;
	  video = NULL;
	  video = open_bitmap(get_path(d->path_pic, i));
	  if (video != NULL)
	    d->video[i] = video->buffer;
	}
      i++;
    }
}
