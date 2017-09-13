/*
** my_put_pourcent.c for my_printf in /home/barrau_a//c/my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 19:34:29 2010 adrien barrau
** Last update Mon Dec  6 16:44:29 2010 adrien barrau
*/

#include "commons.h"

void	my_put_pourcent(t_format *strct_format, int *chr_cnt, int fd)
{
  strct_format = 0;
  my_putstr_pf("%", chr_cnt, fd);
}
