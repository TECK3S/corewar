/*
** parse_arg.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Nov 23 10:24:47 2010 adrien barrau
** Last update Mon Dec  6 17:03:28 2010 adrien barrau
*/

#include "commons.h"

int		parse_arg(char *format, int idx, int *chr_cnt, int fd)
{
  t_format	strct_format;
  t_string	strct_str;

  init_strct_format(&strct_format);
  strct_str.format = format;
  strct_str.new_idx = idx + 1;
  check_flag(&strct_str, &strct_format);
  check_width(&strct_str, &strct_format);
  if (format[strct_str.new_idx] == '.')
    check_precision(&strct_str, &strct_format);
  check_len_mod(&strct_str, &strct_format);
  if (check_con_spe(&strct_str, &strct_format, chr_cnt, fd) == 0)
    {
      strct_str.new_idx = idx;
      xcwrite('%', chr_cnt, fd);
    }
  return (strct_str.new_idx);
}

void	init_strct_format(t_format *strct_format)
{
  (strct_format->flags)[0] = 0;
  (strct_format->flags)[1] = 0;
  (strct_format->flags)[2] = 0;
  (strct_format->flags)[3] = 0;
  (strct_format->flags)[4] = 0;
  strct_format->width = 0;
  strct_format->precision = 0;
  strct_format->len_mod = "";
}
