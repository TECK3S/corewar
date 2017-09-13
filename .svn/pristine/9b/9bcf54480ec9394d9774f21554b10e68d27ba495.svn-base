/*
** check_con_spe.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 19:03:24 2010 adrien barrau
** Last update Mon Dec  6 12:58:22 2010 adrien barrau
*/

#include <stdarg.h>
#include "commons.h"

int	check_con_spe(t_string *strct_str, t_format *strct_format, int *chr_cnt, int fd)
{
  int	i;
  int	found;

  i = 0;
  found = 0;
  while (!found && (gl_con_spe[i]).name)
    {
      if ((strct_str->format)[strct_str->new_idx] == (gl_con_spe[i]).name)
	{
	  (gl_con_spe[i]).fct(strct_format, chr_cnt, fd);
	  found = 1;
	}
      i++;
    }
  return (found);
}
