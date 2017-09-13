/*
** my_strdup.c for libmy in /u/all/benich_a/cu/rendu/lib/my
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Thu Dec 10 18:52:03 2009 mickael benichou
** Last update Sun Dec 19 07:25:49 2010 eugene-valentin ngontang-tchiadjie
*/

#include <stdlib.h>
#include "xfunctions.h"
#include "commons.h"

char		*my_strdup(char *str)
{
  char		*dest;
  int		cpt;

  dest = xmalloc((my_strlen(str) + 1) * sizeof(*dest));
  cpt = 0;
  while ( str && str[cpt] != '\0')
    {
      dest[cpt] = str[cpt];
      cpt++;
    }
  dest[cpt] = '\0';
  return (dest);
}
