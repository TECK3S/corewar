/*
** my_strncmp_pf.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Nov 24 15:41:54 2010 adrien barrau
** Last update Mon Dec  6 11:11:48 2010 remi bartel
*/

#include "commons.h"

int	my_strncmp_pf(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (i < (nb - 1) && s1[i] && s2[i] && s1[i] == s2[i])
    ++i;
  return (s1[i] - s2[i]);
}
