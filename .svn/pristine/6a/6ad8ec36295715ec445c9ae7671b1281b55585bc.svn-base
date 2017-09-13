/*
** check_width.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 16:26:23 2010 adrien barrau
** Last update Fri Dec  3 12:27:38 2010 damien benloukil
*/

#include <stdarg.h>
#include "commons.h"

void	check_width(t_string *strct_str, t_format *strct_format)
{
  int	width;

  width = my_getnbr(&((strct_str->format)[strct_str->new_idx]));
  if (width == 0)
    {
      if ((strct_str->format)[strct_str->new_idx] == '*')
	{
	  width = va_arg(gl_ap, int);
	  strct_str->new_idx += 1;
	}
     }
  else
    strct_str->new_idx += my_nbrlen_pf(width);
  strct_format->width = width;
}
