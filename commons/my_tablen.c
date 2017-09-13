/*
** my_tablen.c for commons in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/commons
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Wed Dec  8 03:49:13 2010 eugene-valentin ngontang-tchiadjie
** Last update Wed Dec  8 03:49:43 2010 eugene-valentin ngontang-tchiadjie
*/

#include <stdlib.h>

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i] != NULL)
    i++;
  return (i);
}
