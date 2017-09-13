/*
** get_next_line.c for mylib in /home/benich_a//afs/rendu/c/minishell1/lib
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Sat Nov 13 05:07:51 2010 mickael benichou
** Last update Mon Nov 29 23:42:02 2010 mickael benichou
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "commons.h"
#include "xfunctions.h"

char	*get_next_line3(t_gnl *gnl, int *size, int *pos, char *buffer)
{
  while (42)
    {
      if (gnl->pos2 >= *size)
	{
	  gnl->s2 = xmalloc(gnl->pos2 - *pos + 1);
	  my_strncpy(gnl->s2, buffer + *pos, gnl->pos2 - *pos);
	  gnl->s2[gnl->pos2 - *pos] = 0;
	  *size = -1;
	  return (get_next_line2(gnl));
	}
      if (*(buffer + gnl->pos2) == '\n')
	{
	  gnl->s2 = xmalloc(gnl->pos2 - *pos + 1);
	  my_strncpy(gnl->s2, buffer + *pos, gnl->pos2 - *pos);
	  gnl->s2[gnl->pos2 - *pos] = 0;
	  *pos = gnl->pos2 + 1;
	  return (gnl->s2);
	}
      gnl->pos2++;
    }
}

char	*get_next_line2(t_gnl *gnl)
{
  if ((gnl->s3 = get_next_line(gnl->fd)))
    {
      gnl->s4 = xmalloc(my_strlen(gnl->s2) + my_strlen(gnl->s3) + 1);
      my_strncpy(gnl->s4, gnl->s2, my_strlen(gnl->s2));
      my_strncpy(gnl->s4 + my_strlen(gnl->s2), gnl->s3, my_strlen(gnl->s3));
      gnl->s4[my_strlen(gnl->s2) + my_strlen(gnl->s3)] = 0;
      free(gnl->s2);
      free(gnl->s3);
      return (gnl->s4);
    }
  else
    return (gnl->s2);
}

char	*get_next_line(int fd)
{
  static char	buffer[READ_SIZE];
  static int	pos = 0;
  static int	size = -1;
  t_gnl		gnl;

  gnl.fd = fd;
  if (size < 0 || pos >= size)
    {
      if ((size = read(gnl.fd, buffer, READ_SIZE)) <= 0)
        return (0);
      pos = 0;
    }
  gnl.pos2 = pos;
  return (get_next_line3(&gnl, &size, &pos, buffer));
}
