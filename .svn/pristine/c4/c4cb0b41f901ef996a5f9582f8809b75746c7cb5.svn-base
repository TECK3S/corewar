/*
** check_name.c for check_name in /home/bartel_r//Workspace/KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Tue Dec  7 17:09:47 2010 remi bartel
** Last update Mon Dec 13 18:50:18 2010 remi bartel
*/

#include "commons.h"
#include "op.h"
#include "asm.h"
#include "xfunctions.h"

static	int	disp_quote_expected(void)
{
  my_fprintf(STDERR, "Error : %s.\n", ERR_QUOTEXP);
  return (0);
}

static	int	disp_no_name(void)
{
  my_fprintf(STDERR, "Error : %s.\n", ERR_NONAME);
  return (0);
}

int	check_name(char *str, t_link *link)
{
  unsigned	int	len;

  str = go_next_word(str);
  if (!*str)
    return (disp_no_name());
  else if (*str != '"')
    return (disp_quote_expected());
  ++str;
  len = 0;
  while (str[len] && str[len] != '"' && len < PROG_NAME_LENGTH)
    ++len;
  if (!len)
    return (disp_no_name());
  link->label = xmalloc((len + 1) * sizeof(*str));
  link->label = my_strncpy(link->label, str, len);
  while (str[len] && str[len] != '"')
    ++len;
  if (str[len] != '"')
    return (disp_quote_expected());
  link->add = 2;
  return (1);
}
