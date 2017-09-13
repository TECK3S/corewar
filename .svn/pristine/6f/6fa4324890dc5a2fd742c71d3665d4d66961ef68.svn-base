/*
** fill_with_blank.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 00:29:09 2010 adrien barrau
** Last update Mon Dec  6 13:01:31 2010 adrien barrau
*/

#include "commons.h"

void	fill_with_blank(t_format *strct_format, int *chr_cnt, int nbr_len, int fd)
{
  int	i;
  char	c;

  i = 0;
  if ((strct_format->flags)[FL_ZERO_POS] == 1
      && (strct_format->flags)[FL_MINUS_POS] == 0)
    c = '0';
  else
    c = ' ';
  while (i < (strct_format->width - nbr_len)
	 || i < (strct_format->precision - nbr_len))
    {
      xcwrite(c, chr_cnt, fd);
      i++;
    }
}
