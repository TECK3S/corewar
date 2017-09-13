/*
** parsing.c for parsing.c in /home/bartel_r//Workspace/KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Fri Dec  3 19:40:28 2010 remi bartel
   Last update Sun Dec 19 23:00:25 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:48:44 2010 remi bartel
*/

#include <stdlib.h>
#include "commons.h"
#include "asm.h"
#include "op.h"
#include "xfunctions.h"

static	char	*get_label(char *str, t_link *link, int len, int *step)
{
  int	i;

  --*step;
  link->label = xmalloc(len + 1 * sizeof(link->label));
  i = 0;
  while (is_valid(str[i]) && i < len)
    {
      link->label[i] = str[i];
      ++i;
    }
  link->label[i] = '\0';
  link->add = 1;
  return (str + 1);
}

static	char	*get_arg(char *str, char type, int line, int extd)
{
  int	i;
  char	*res;

  i = 0;
  if ((check_arg_type(str, type, line, extd)) == -1)
    return (NULL);
  while (str[i] && str[i] != SEPARATOR_CHAR && str[i])
    ++i;
  if (str[i] == SEPARATOR_CHAR)
    ++str;
  else if (str[i] == ' ' || str[i] == '\t')
    {
      res = go_next_word(&str[i]);
      if (*res != COMMENT_CHAR && *res != '\0')
	{
	  my_fprintf(STDERR, "Error line %d : %s.\n", line, ERR_COMMA);
	  return (NULL);
	}
    }
  return (&str[i]);
}

static	char	*process_arg(t_link *link, char *str, char type, int line)
{
  char	*res;

  if (!(link->extd))
    res = get_arg(str, type, line, (link->spe & VAL_EXTD));
  else
    res = process_extd(link->inst, type);
  return (res);
}

static	int	line_scanning(char *str, t_link *link, int line, int *step)
{
  int		len;
  unsigned char	*arg_arr;

  arg_arr = NULL;
  while (*str && *str != COMMENT_CHAR &&
	 (!link->nb || (link->nb && *step <= link->nb)))
    {
      if (*step == 0)
	{
	  len = get_length(str);
	  if (str[len] == LABEL_CHAR && link->label == NULL)
	    str = get_label(str, link, len, step);
	  else if ((arg_arr = seek_nb_arg(str, link, line)) == NULL)
	    return (-1);
	  str += len;
 	}
      else if ((str = process_arg(link, str, arg_arr[*step - 1], line))
	       == NULL)
	return (-1);
      str = go_next_word(str);
      ++*step;
    }
   return (0);
}

int     parsing(char *str, int count, t_link *link)
{
  int	step;

  step = 0;
  str = go_next_word(str);
  if (str[0] == '.')
    {
      if (!(link->spe & VAL_EXTD))
	return (seek_header(str, link, count));
      ++str;
    }
  if (*str != '\0' && *str != COMMENT_CHAR && (link->spe & VAL_NAME) == 0)
    {
      link->spe += VAL_NAME;
      disp_bad_header(count);
      return (0);
    }
  if (*str == COMMENT_CHAR || !*str)
    return (1);
  if (line_scanning(str, link, count, &step) == -1)
    return (0);
  if (step > 0)
    return (check_arg_nb(link->nb, step - 1, count));
  return (1);
}
