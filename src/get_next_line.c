/*
** main.c for main in /home/pion_b/CPE_2015_getnextline
**
** Made by Virgile Pion
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan  4 10:53:25 2016 Virgile Pion
** Last update Mon Jan 16 18:29:23 2017 Virgile
*/


#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

static char	*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (src[i] != '\0' && i < n)
   {
      dest[i] = src[i];
      i++;
    }
  if (n < i)
    dest[i] = '\0';
  return (dest);
}

static char	*add(char *line, char *buf, int *start, int nbread)
{
  char		*next;
  int		back;

  back = (line != 0) ? (my_strlen(line)) : (0);
  if ((next = malloc((back + nbread + 1) * sizeof(*next))) == NULL)
    return (NULL);
  if (line != 0)
    my_strncpy(next, line, back);
  else
    my_strncpy(next, "", back);
  next[back + nbread] = 0;
  my_strncpy(next + back, buf + *start, nbread);
  if (line)
    free(line);
  *start = *start + (nbread + 1);
  return (next);
}

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE];
  static int	nbbuf = 0;
  static int	start;
  char		*line;
  int		nbread;

  line = 0;
  nbread = 0;
  while (1)
    {
      if (nbbuf <= start && (start = 0) == 0)
	{
	  if (!(nbbuf = read(fd, buf, READ_SIZE)))
	    return (line);
	  if (((nbread = 0) == 0) && nbbuf == -1)
	    return (NULL);
	}
      if (buf[start + nbread] == '\n')
	return (line = add(line, buf, &start, nbread));
      if (start + nbread == nbbuf - 1					\
	  && (line = add(line, buf, &start, nbread + 1)) == NULL)
	    return (NULL);
      nbread++;
    }
}
