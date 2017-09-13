/*
** my_put_uoctal.c for my_printf in /home/barrau_a//c/my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 13:20:59 2010 adrien barrau
** Last update Mon Dec  6 13:02:37 2010 adrien barrau
*/

#include <stdarg.h>
#include "commons.h"

void		my_put_uoctal(t_format *strct_format, int *chr_cnt, int fd)
{
  int		oct_len;
  unsigned int	oct;
  char		c;

  oct = va_arg(gl_ap, unsigned int);
  oct_len = my_nbrlen_base_pf(oct, "01234567");
  if (((strct_format->flags)[FL_PLUS_POS] == 1
       || (strct_format->flags)[FL_SPACE_POS] == 1) && oct > 0)
    oct_len++;
  if ((strct_format->flags)[FL_DIESE_POS] == 1 && oct > 0)
    oct_len++;
  if ((strct_format->flags)[FL_DIESE_POS] == 1 && oct > 0)
    xcwrite('0', chr_cnt, fd);
  c = 0;
  if ((strct_format->flags)[FL_SPACE_POS] == 1 && oct > 0)
    c = ' ';
  if ((strct_format->flags)[FL_PLUS_POS] == 1 && oct > 0)
    c = '+';
  if (c != 0)
    xcwrite(c, chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 0)
    fill_with_blank(strct_format, chr_cnt, oct_len, fd);
  my_putnbr_base_pf(oct, "01234567", chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 1)
    fill_with_blank(strct_format, chr_cnt, oct_len, fd);
}
