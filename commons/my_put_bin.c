/*
** my_put_bin.c for my_printf in /home/barrau_a//c/my_printf/my_put_fct
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 18:53:23 2010 adrien barrau
** Last update Mon Dec  6 16:45:08 2010 adrien barrau
*/

#include <stdarg.h>
#include "commons.h"

void	my_put_bin(t_format *strct_format, int *chr_cnt, int fd)
{
  int		bin_len;
  unsigned int	bin;
  char		c;

  bin = va_arg(gl_ap, unsigned int);
  bin_len = my_nbrlen_base_pf(bin, "01");
  if (((strct_format->flags)[FL_PLUS_POS] == 1
       || (strct_format->flags)[FL_SPACE_POS] == 1) && bin > 0)
    bin_len++;
  c = 0;
  if ((strct_format->flags)[FL_SPACE_POS] == 1 && bin > 0)
    c = ' ';
  if ((strct_format->flags)[FL_PLUS_POS] == 1 && bin > 0)
    c = '+';
  if (c != 0)
    xcwrite(c, chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 0)
    fill_with_blank(strct_format, chr_cnt, bin_len, fd);
  my_putnbr_base_pf(bin, "01", chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 1)
    fill_with_blank(strct_format, chr_cnt, bin_len, fd);
}
