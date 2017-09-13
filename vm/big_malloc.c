/*
** big_malloc.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Dec 17 23:47:12 2010 adrien barrau
** Last update Fri Dec 17 23:47:13 2010 adrien barrau
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "commons.h"
#include "xfunctions.h"
#include "vm.h"

unsigned char	*big_malloc()
{
  unsigned char	*big_male;
  int i;

  i = 0;
  big_male = xmalloc(MEM_SIZE * sizeof(*big_male));
  while (i < MEM_SIZE)
    big_male[i++] = 0;
  return (big_male);
}
