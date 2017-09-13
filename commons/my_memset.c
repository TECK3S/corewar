/*
** my_memset.c for mylib in /u/all/benich_a/cu/rendu/c/minishell1
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Fri Nov 12 00:15:53 2010 mickael benichou
** Last update Sun Dec 19 10:49:37 2010 mickael benichou
*/

#include	<sys/types.h>
#include	"commons.h"

void		*my_memset(char *mem, unsigned char v, size_t len)
{
  unsigned int	i;

  i = 0;
  while (i < len)
    {
      mem[i] = v;
      i++;
    }
  return (mem);
}
