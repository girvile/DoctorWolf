/*
** framebuffer.c for framebuffer in /home/pion_b/graph
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Nov 14 10:33:08 2016 Virgile
** Last update Thu Nov 17 00:08:49 2016 Virgile
*/

#include "my.h"

void			buffer_destroy(t_my_framebuffer *buffer)
{
  free (buffer->pixels);
  free (buffer);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*buffer;

  if ((buffer = malloc(sizeof(*buffer))) == NULL)
    return (NULL);
  if ((buffer->pixels = malloc((sizeof(buffer->pixels)		\
				* width * height * 4))) == NULL)
    {
      return (NULL);
    }
  buffer->width = width;
  buffer->height = height;
  return (buffer);
}
