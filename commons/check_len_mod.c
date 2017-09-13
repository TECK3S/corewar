/*
** check_len_mod.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 18:45:38 2010 adrien barrau
** Last update Wed Dec  1 00:57:54 2010 root
*/

#include <stdarg.h>
#include "commons.h"

void	check_len_mod(t_string *strct_str, t_format *strct_format)
{
  int	i;

  i = 0;
  while (gl_len_mod[i] && i >= 0)
    {
      if (my_strncmp_pf(&((strct_str->format)[strct_str->new_idx]),
			gl_len_mod[i],
			my_strlen(gl_len_mod[i])) == 0)
	{
	  strct_format->len_mod = gl_len_mod[i];
	  strct_str->new_idx += my_strlen(gl_len_mod[i]);
	  i = -42;
	}
      i++;
    }
}
