/*
** my_put_ptr.c for my_printf in /home/barrau_a//c/my_printf/my_put_fct
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 18:41:00 2010 adrien barrau
** Last update Mon Dec  6 16:43:38 2010 adrien barrau
*/

#include <stdarg.h>
#include "commons.h"

void	my_put_ptr(t_format *strct_format, int *chr_cnt, int fd)
{
  int		hex_len;
  unsigned int	hex;
  char		c;

  hex = va_arg(gl_ap, unsigned int);
  hex_len = my_nbrlen_base_pf(hex, "0123456789abcdef");
  if (((strct_format->flags)[FL_PLUS_POS] == 1
       || (strct_format->flags)[FL_SPACE_POS] == 1) && hex > 0)
    hex_len++;
  hex_len += 2;
  my_putstr_pf("0x", chr_cnt, fd);
  c = 0;
  if ((strct_format->flags)[FL_SPACE_POS] == 1 && hex > 0)
    c = ' ';
  if ((strct_format->flags)[FL_PLUS_POS] == 1 && hex > 0)
    c = '+';
  if (c != 0)
    xcwrite(c, chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 0)
    fill_with_blank(strct_format, chr_cnt, hex_len, fd);
  my_putnbr_base_pf(hex, "0123456789abcdef", chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 1)
    fill_with_blank(strct_format, chr_cnt, hex_len, fd);
}
