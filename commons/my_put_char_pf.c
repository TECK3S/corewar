/*
** my_put_char_pf.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 00:21:27 2010 adrien barrau
** Last update Mon Dec  6 16:40:52 2010 adrien barrau
*/

#include <stdarg.h>
#include "commons.h"

void	my_put_char_pf(t_format *strct_format, int *chr_cnt, int fd)
{
  int	c;

  c = va_arg(gl_ap, int);
  if ((strct_format->flags)[FL_MINUS_POS] == 0)
    fill_with_blank(strct_format, chr_cnt, 1, fd);
  xcwrite(c, chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 1)
    fill_with_blank(strct_format, chr_cnt, 1, fd);
}
