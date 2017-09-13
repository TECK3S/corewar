/*
** store_addr_call.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 01:23:23 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 23:10:57 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 18:24:52 2010 remi bartel
** Last update Sun Dec 19 22:45:05 2010 remi bartel
*/

#include	<stdlib.h>
#include	"xfunctions.h"
#include	"op.h"
#include	"asm.h"
#include	"commons.h"

static	int	get_lab_len(char *str)
{
  int	len;

  len = 0;
  while (is_alpha(str[len]) || is_num(str[len]) || str[len] == '_')
    ++len;
  return (len);
}

static char	*get_call(char *param)
{
  int	i;
  int	len;
  char	*str;

  i = 0;
  while (param[i++] != LABEL_CHAR);
  len = get_lab_len(&param[i]);
  str = xmalloc((len + 2) * sizeof(*str));
  str = my_strncpy(str, &param[i], len);
  str = xmalloc((len + 1) * sizeof(*str));
  my_strncpy(str, &param[i], len);
  return (str);
}

static t_param	*do_extend(t_param *element, char *param)
{
  int	i;
  char	sign;
  
  i = 0;
  element->sign = '0';
  element->val = 0;
  while (param[i] != '\0' && ((sign = get_op(param[i])) == '0'))
    i = i + 1;
  if (sign != '0')
    {  
      element->sign = sign; 
      if (param[i] != '\0')
	{
	  while (param[i] != '\0' && !is_num(param[i]))
	    i = i + 1;
	  if (param[i] != '\0')
	    element->val = my_getaddr(&(param[i]));
	}
    }
  return (element);
} 

void	store_addr_call(t_param **call_list, int pc, char *param, int nb_oct)
{
  t_param	*element;
  int		addr;

  addr = my_getaddr(param);
  if (is_label(param))
    {
      element = xmalloc(sizeof(*element));
      element->name = get_call(param);
      element->index = pc;
      element->param_size = nb_oct;
      element = do_extend(element, param);
      element->next = *call_list;
      *call_list = element;
    }
}
