/*
** check_comment.c for check_comment in /home/bartel_r//Workspace/KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Tue Dec  7 17:09:47 2010 remi bartel
** Last update Mon Dec 13 18:51:24 2010 remi bartel
*/

#include "commons.h"
#include "op.h"
#include "asm.h"
#include "xfunctions.h"

static	int	disp_quote_expected(void)
{
  my_fprintf(STDERR, "Error : %s.\n", ERR_QUOTEXPC);
  return (0);
}

int	check_comment(char *str, t_link *link)
{
  int	len;

  str = go_next_word(str);
  if (*str != '"')
    {
      link->label = NULL;
      return (1);
    }
  ++str;
  len = 0;
  while (str[len] && str[len] != '"' && len < COMMENT_LENGTH)
    ++len;
  link->label = xmalloc((len + 1) * sizeof(*str));
  link->label = my_strncpy(link->label, str, len);
  while (str[len] && str[len] != '"')
    ++len;
  if (str[len] != '"')
    return (disp_quote_expected());
  link->add = 3;
  return (1);
}
