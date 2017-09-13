/*
** my_free_wt.c for corewar in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Wed Dec  8 00:59:39 2010 mickael benichou
** Last update Tue Dec 14 18:05:02 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>

void		my_free_wt(char **wt)
{
  int i;

  i = 0;
  while (wt[i])
    free(wt[i++]);
  free(wt);
}
