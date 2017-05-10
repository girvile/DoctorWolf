/*
** get_map.c for get_map in /home/pion_b/wolf3d
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Wed Dec 14 15:20:27 2016 Virgile
** Last update Mon Jan 16 18:28:46 2017 Virgile
*/

#include "my.h"
#include "get_next_line.h"

int	get_height(char *path)
{
  int	height;
  int	fd;

  height = 0;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (-1);
  while (get_next_line(fd) != NULL)
    height++;
  close(fd);
  return (height);
}

int	*get_line_map(char *str)
{
  int	*line;
  int	i;

  i = 0;
  if ((line = malloc(sizeof(int *) * my_strlen(str))) == NULL)
    return (NULL);
  while (i < my_strlen(str))
    {
      line[i] = str[i] - '0';
      i++;
    }
  return (line);
}

int	**get_map(char *path, t_data *d)
{
  int	fd;
  int	height;
  int	**map;
  char	*str;
  int	i;
  int	once;

  once = 1;
  i = 0;
  height = get_height(path);
  if (((fd = open(path, O_RDONLY)) == -1) ||			\
      ((map = malloc(sizeof(int *) * (height + 1))) == NULL))
    return (NULL);
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((map[i] = get_line_map(str)) == NULL)
	return (NULL);
      if ((once == 1) && ((d->mapSize.x = my_strlen(str)) == my_strlen(str)))
	once = 0;
      free(str);
      i++;
    }
  d->mapSize.y = height;
  map[i] = NULL;
  return (map);
}
