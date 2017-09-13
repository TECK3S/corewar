/*
** my_strcat.c for commons in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec  7 17:28:33 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 17:12:06 2010 eugene-valentin ngontang-tchiadjie
*/

#include "commons.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  if (src && dest)
    {
      i = my_strlen(dest);
      j = 0;
      while (src[j] != '\0')
	dest[i++] = src[j++];
      dest[i] = '\0';
    }
  return (dest);
}

char	*my_strncat(char *dest, char *src, int n)
{
  int	i;
  int	j;

  if (src && dest)
    {
      i = my_strlen(dest);
      j = 0;
      while (j < n)
	dest[i++] = src[j++];
      dest[i] = '\0';
    }
  return (dest);
}
