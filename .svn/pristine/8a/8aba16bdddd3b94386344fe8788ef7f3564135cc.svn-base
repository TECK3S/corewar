/*
** my_put_inlist.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/includes
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec  7 22:50:01 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 23:15:14 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:47:39 2010 remi bartel
*/

#include <stdlib.h>
#include "asm.h"
#include "commons.h"
#include "xfunctions.h"
#include "op.h"

static t_label		*create_label(char *str, t_label **list)
{
  t_label	*elmt;

  elmt = xmalloc(sizeof(*elmt));
  elmt->l_inst = NULL;
  if (str != NULL)
    elmt->label = my_strdup(str);
  else
    elmt->label = my_strdup("void");
  elmt->next = *list;
  *list = elmt;
  return (elmt);
}

void		my_put_inlist(t_link *link, t_label **label_list,
			      t_call **call_list, int line)
{
  if (link->label != NULL || *label_list == NULL)
      create_label(link->label, label_list);
  if (link->mnemo)
    my_insert_inst(&((*label_list)->l_inst), link, call_list, line);
}
