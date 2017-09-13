/*
** my_put_string.c for my_printf in /home/barrau_a//my_printf/my_put_fct
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 01:40:11 2010 adrien barrau
** Last update Mon Dec  6 16:41:57 2010 adrien barrau
*/

#include <stdarg.h>
#include "commons.h"

void	my_put_string(t_format *strct_format, int *chr_cnt, int fd)
{
  int	str_len;
  char*	str;

  str = va_arg(gl_ap, char *);
  str_len = my_strlen(str);
  if ((strct_format->flags)[FL_MINUS_POS] == 0)
    fill_with_blank(strct_format, chr_cnt, str_len, fd);
  my_putstr_pf(str, chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 1)
    fill_with_blank(strct_format, chr_cnt, str_len, fd);
}
