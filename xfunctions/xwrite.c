/*
** xwrite.c for corewar in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk/commons
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Sat Nov 20 04:56:28 2010 mickael benichou
** Last update Tue Dec 14 15:24:53 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<unistd.h>
#include	"xfunctions.h"
#include	"commons.h"

size_t		xwrite(int fd, const void *buf, size_t count)
{
  int		wsize;

  if ((wsize = write(fd, buf, count)) == -1)
    my_fprintf(STDERR, "Corewar : Xwrite\n");
  return (wsize);
}
