/*
** my_putstr_pf.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Nov 24 15:58:51 2010 adrien barrau
** Last update Mon Dec  6 16:58:00 2010 adrien barrau
*/

#include <unistd.h>
#include "commons.h"

void	my_putstr_pf(char *str, int *chr_cnt, int fd)
{
  int	i;

  i = 0;
  while (str && str[i])
    xcwrite(str[i++], chr_cnt, fd);
}
