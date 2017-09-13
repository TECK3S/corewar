/*
** my_strlen_big_pf.c for my_printf in /home/barrau_a//c/my_printf/my_put_fct
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 19:16:30 2010 adrien barrau
** Last update Wed Dec  1 01:14:36 2010 root
*/

#include "commons.h"

int	my_strlen_big_pf(char *str)
{
  int	len;
  int	i;

  len = 0;
  i = 0;
  while (str && str[i])
    {
      if (char_is_printable_pf(str[i]))
	len++;
      else
	len += my_nbrlen_base_pf(str[i], "01234567");
      i++;
    }
  return (len);
}
