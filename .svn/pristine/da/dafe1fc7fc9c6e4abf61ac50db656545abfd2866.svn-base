/*
** my_insert_inst.c for asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Wed Dec  8 14:11:13 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 23:16:06 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:48:00 2010 remi bartel
*/

#include <stdlib.h>
#include "asm.h"
#include "commons.h"
#include "xfunctions.h"
#include "op.h"

static	char		*check_params(char *param)
{
  while (*param)
    {
      if (*param == LABEL_CHAR)
	  return (param + 1);
      ++param;
    }
  return (NULL);
}

static	void		my_insert_call(char **params,
				       t_call **call_list, int line_count)
{
  t_call		*new_call;
  char			*label;
  int			i;
  int			len;

  i = 0;
  while (params[i])
    {
      if ((label = check_params(params[i])) != NULL)
	{
	  new_call = xmalloc(sizeof(*new_call));
	  len = get_length(label);
	  new_call->label = xmalloc((len + 1) * sizeof(*new_call));
	  new_call->label = my_strncpy(new_call->label, label, len);
	  new_call->line = line_count;
	  new_call->next = *call_list;
	  *call_list = new_call;
	}
      ++i;
    }
}

void		my_insert_inst(t_inst **list, t_link *link,
			       t_call **call_list, int line)
{
  t_inst	*new_inst;
  int		i;

  new_inst = xmalloc(sizeof(*new_inst));
  new_inst->mnemo = my_strdup(link->mnemo);
  new_inst->params = my_get_paramtab(link->inst, link->nb);
  new_inst->next = *list;
  *list = new_inst;
  i = 0;
  my_insert_call(new_inst->params, call_list, line);
}
