/*
** fill_nbr.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 18 05:27:44 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 11:11:08 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"xfunctions.h"
#include	"commons.h"
#include	"asm.h"

char    *fill_nbr(char *str, int n)
{
  char  *nbr;
  int   i;
  int   j;

  j = 0;
  i = 0;
  nbr = xmalloc((n + 1) * sizeof(*nbr));
  while (i < (n - my_strlen(str)))
    nbr[i++] = BASE_INT[0];
  while (str[j] != '\0')
    nbr[i++] = str[j++];
  nbr[i] = '\0';
  free(str);
  return (nbr);
}
