/*
** header_cpy.c for commons in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 11 06:28:58 2010 eugene-valentin ngontang-tchiadjie
** Last update Sat Dec 11 07:17:53 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>

void    header_cpy(char header[], char *src)
{
  int   i;

  i = 0;
  if (src != NULL)
    {
      while (src[i] != '\0')
        {
          dest[i] = src[i];
          i = i + 1;
        }
      dest[i] = '\0';
    }
  else
    dest[i] = '\0';
  return ;
}
