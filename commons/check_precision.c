/*
** check_precision.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 18:37:26 2010 adrien barrau
** Last update Fri Dec  3 12:26:48 2010 damien benloukil
*/

#include <stdarg.h>
#include "commons.h"

void	check_precision(t_string *strct_str, t_format *strct_format)
{
  int	precision;

  precision = 0;
  strct_str->new_idx += 1;
  if ((strct_str->format)[strct_str->new_idx] == '*')
    {
      precision = va_arg(gl_ap, int);
      strct_str->new_idx += 1;
    }
  else
    {
      precision = my_getnbr(&((strct_str->format)[strct_str->new_idx]));
      strct_str->new_idx += my_nbrlen_pf(precision);
    }
  strct_format->precision = precision;
}
