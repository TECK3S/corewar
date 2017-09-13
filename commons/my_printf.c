/*
** my_printf.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 09:59:19 2010 adrien barrau
** Last update Mon Dec  6 17:19:12 2010 adrien barrau
*/

#include <stdlib.h>
#include <stdarg.h>
#include "commons.h"

char	gl_flags[]=
  {
    '#',
    '0',
    '-',
    ' ',
    '+',
    0
  };

char	*gl_len_mod[]=
  {
    "hh",
    "h",
    "l",
    "ll",
    "L",
    "q",
    "j",
    "z",
    "t",
    0,
  };

t_con_spe	gl_con_spe[]=
  {
    {'d', &my_put_int},
    {'i', &my_put_int},
    {'o', &my_put_uoctal},
    {'u', &my_put_uint},
    {'x', &my_put_uhex},
    {'X', &my_put_uhex_big},
    {'e', &my_put_expo_double},
    {'E', &my_put_expo_double_big},
    {'f', &my_put_double},
    {'F', &my_put_double_big},
    {'g', &my_put_e_or_f},
    {'G', &my_put_e_or_f_big},
    {'a', &my_put_double_hex},
    {'A', &my_put_double_hex_big},
    {'c', &my_put_char_pf},
    {'s', &my_put_string},
    {'S', &my_put_string_big},
    {'p', &my_put_ptr},
    {'n', &my_put_nb_char},
    {'%', &my_put_pourcent},
    {'b', &my_put_bin},
    {0, 0}
  };

va_list	gl_ap;

int	my_printf(char *format, ...)
{
  int	i;
  int	chr_cnt;

  i = 0;
  chr_cnt = 0;
  va_start(gl_ap, format);
  while (format && format[i])
    {
      if (format[i] == '%')
	i = parse_arg(format, i, &chr_cnt, STDOUT);
      else
	xcwrite(format[i], &chr_cnt, STDOUT);
      i++;
    }
  va_end(gl_ap);
  return (chr_cnt);
}

int	my_fprintf(int fd, char *format, ...)
{
  int	i;
  int	chr_cnt;
  
  i = 0;
  chr_cnt = 0;
  if (fd >= 0)
    {
      va_start(gl_ap, format);
      while (format && format[i])
	{
	  if (format[i] == '%')
	    i = parse_arg(format, i, &chr_cnt, fd);
	  else
	    xcwrite(format[i], &chr_cnt, fd);
	  i++;
	}
      va_end(gl_ap);
    }
  else
    my_fprintf(STDERR, BAD_FD_FPRINTF_ERR_MSG);
  return (chr_cnt);
}
