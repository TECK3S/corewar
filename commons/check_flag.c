/*
** check_flag.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 16:11:44 2010 adrien barrau
** Last update Wed Dec  1 00:54:15 2010 root
*/

#include <stdarg.h>
#include "commons.h"

void	check_flag(t_string *strct_str, t_format *strct_format)
{
  int	pos;

  pos = -1;
  while ((pos = pos_flag((strct_str->format)[strct_str->new_idx])) != -1)
    {
      (strct_format->flags)[pos] = 1;
      strct_str->new_idx += 1;
    }
}

int	pos_flag(char c)
{
  int	pos;
  int	i;

  i = 0;
  pos = -1;
  while (gl_flags[i])
    {
      if (c == gl_flags[i])
	pos = i;
      i++;
    }
  return (pos);
}
