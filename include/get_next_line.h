/*
** get_next_line.h for get_next_line in /home/pion_b/CPE_2015_getnextline
**
** Made by Virgile Pion
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan  4 10:57:26 2016 Virgile Pion
** Last update Mon Nov 14 16:15:49 2016 Virgile
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#ifndef READ_SIZE
#define READ_SIZE (14)
#endif /* !READ_SIZE */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char		*get_next_line(const int fd);
//static char	*add(char *line, char *buf, int *start, int nbread);
//static char	*my_strncpy(char *dest, char *src, int n);
int		my_strlen(char *str);
#endif /* !GET_NEXT_LINE_H_ */
