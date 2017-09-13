/*
** my_put_int.c for my_printf in /home/barrau_a//my_printf/my_put_fct
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Nov 24 22:06:10 2010 adrien barrau
** Last update Mon Dec  6 13:02:50 2010 adrien barrau
*/

#include <stdarg.h>
#include "commons.h"

void	my_put_int(t_format *strct_format, int *chr_cnt, int fd)
{
  int	nbr_len;
  int	nbr;
  char	c;

  nbr = va_arg(gl_ap, int);
  nbr_len = my_nbrlen_pf(nbr);
  if (((strct_format->flags)[FL_PLUS_POS] == 1
       || (strct_format->flags)[FL_SPACE_POS] == 1) && nbr > 0)
    nbr_len++;
  c = 0;
  if ((strct_format->flags)[FL_SPACE_POS] == 1 && nbr > 0)
    c = ' ';
  if ((strct_format->flags)[FL_PLUS_POS] == 1 && nbr > 0)
    c = '+';
  if (c != 0)
    xcwrite(c, chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 0)
    fill_with_blank(strct_format, chr_cnt, nbr_len, fd);
  my_putnbr_pf(nbr, chr_cnt, fd);
  if ((strct_format->flags)[FL_MINUS_POS] == 1)
    fill_with_blank(strct_format, chr_cnt, nbr_len, fd);
}
