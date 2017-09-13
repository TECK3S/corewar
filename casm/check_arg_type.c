/*
** check_arg_type.c for check_arg_type in /home/bartel_r//Workspace/KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Wed Dec  8 16:23:55 2010 remi bartel
** Last update Sun Dec 19 22:15:22 2010 remi bartel
*/

#include "commons.h"
#include "op.h"
#include "asm.h"

static	int	check_offset(char *str)
{
  int	ok;

  ok = 1;
  str = go_next_word(str);
  if (*str != '+' && *str != '-')
    ok = 0;
  else
    ++str;
  str = go_next_word(str);
  if (*str && ok)
    ok = is_utterly_num(str);
  return (ok);
}

static	int	is_label_call(char *str, int extd)
{
  int	ok;

  ok = 1;
  if (*str != LABEL_CHAR)
    ok = 0;
  ++str;
  while (ok && ((is_num(*str)) || (is_alpha(*str)) || *str == '_'))
    ++str;
  str = go_next_word(str);
  if ((*str == '+' || *str == '-') &&  extd)
    ok = check_offset(str);
  else if (*str && *str != COMMENT_CHAR)
    ok = 0;
  return (ok);
}

static	int	check_dir(char *str, int line, int extd)
{
  int	ok;

  ok = 1;
  if (str[0] != '%' || ((!is_label_call(&str[1], extd))
			&& (!(is_utterly_num(&str[1])))))
    ok = -1;
  if (ok == -1)
    my_fprintf(STDERR, "Error line %d : %s\n", line, ERR_DIRECT);
  return (ok);
}

static	int	check_reg(char *str, int line)
{
  int	err;

  err = 0;
  if (str[0] != 'r')
    {
      my_fprintf(STDERR, "Error line %d : %s\n", line, ERR_REGIST);
      err = -1;
    }
  else
    {
      ++str;
      if (is_utterly_num(str) == 0)
	{
	  my_fprintf(STDERR, "Error line %d : %s\n", line, ERR_REGIST);
	  err = -1;
	}
    }
  return (err);
}

int	check_arg_type(char *str, char type, int line, int extd)
{
  if (type == T_REG)
    return (check_reg(str, line));
  if (type == T_DIR)
      return (check_dir(str, line, extd));
  return (0);
}
