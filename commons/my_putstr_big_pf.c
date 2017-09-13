/*
** my_putstr_big_pf.c for my_printf in /home/barrau_a//c/my_printf/my_put_fct
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 19:05:11 2010 adrien barrau
** Last update Mon Dec  6 16:57:26 2010 adrien barrau
*/

#include "commons.h"
#include "xfunctions.h"

int	char_is_printable_pf(char c)
{
  int	is_printable;

  is_printable = 0;
  if (c >= 32 && c < 127)
    is_printable = 1;
  return (is_printable);
}

void	my_putstr_big_pf(char *str, int *chr_cnt, int fd)
{
  int	i;
  int	j;
  int	oct_len;

  i = 0;
  oct_len = 0;
  while (str && str[i])
    {
      if (char_is_printable_pf(str[i]))
	xcwrite(str[i], chr_cnt, fd);
      else
	{
	  j = 0;
	  xcwrite('\\', chr_cnt, fd);
	  oct_len = my_nbrlen_base_pf(str[i], "01234567");
	  *chr_cnt += oct_len;
	  while (j++ < 3 - oct_len)
	    {
	      xcwrite('0', chr_cnt, fd);
	      *chr_cnt += 1;
	    }
	  my_putnbr_base_pf(str[i], "01234567", chr_cnt, fd);
	}
      i++;
    }
}
