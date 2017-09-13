/*
** my_compar.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 18 00:03:56 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 15:10:43 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"commons.h"

int	my_compar(char *s1, char *s2)
{
  int	i;
  char	*tmp1;
  char	*tmp2;
  int	result;

  i = 0;
  while (s1 && s1[i] == '0')
    i++;
  tmp1 = my_strdup(&s1[i]);
  i = 0;
  while (s2 && s2[i] == '0')
    i++;
  tmp2 = my_strdup(&s2[i]);
  if (my_strlen(tmp1) > my_strlen(tmp2))
    result = 1;
  else if (my_strlen(tmp1) < my_strlen(tmp2))
    result = -1;
  else
    result = my_strcmp(tmp1, tmp2);
  free(tmp1);
  free(tmp2);
  return (result);
}
