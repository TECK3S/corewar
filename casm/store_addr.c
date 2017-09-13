/*
** store_addr.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 01:23:23 2010 eugene-valentin ngontang-tchiadjie
   Last update Sun Dec 19 23:05:32 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:49:05 2010 remi bartel
*/

#include	<stdlib.h>
#include	"xfunctions.h"
#include	"op.h"
#include	"asm.h"
#include	"commons.h"

char	*get_call(char *param)
{
  int	i;

  i = 0;
  while (param[i] != LABEL_CHAR)
    i++;
  i++;
  return (my_strdup(&param[i]));
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
      element->next = *call_list;
      *call_list = element;
    }
  return ;
}
