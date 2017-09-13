/*
** xmalloc.c for libmy in /u/all/benich_a/cu/rendu/lib/my
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Fri Dec  4 01:44:17 2009 mickael benichou
** Last update Mon Dec 13 20:47:00 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"commons.h"

void		*xmalloc(size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) != NULL)
    return (ptr);
  else
    {
      my_fprintf(STDERR, "malloc error");
      exit(EXIT_FAILURE);
    }
}
