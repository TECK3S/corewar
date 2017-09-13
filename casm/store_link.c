/*
** store_link.c for store_link in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Thu Dec  9 21:58:44 2010 remi bartel
** Last update Fri Dec 10 01:37:21 2010 remi bartel
*/

#include "xfunctions.h"
#include "asm.h"
#include "op.h"
#include "commons.h"

t_label	*add_label(t_label *list, char *label)
{
  t_label	*link;

  link = xmalloc(sizeof(*link));
  link->label = my_strdup(label);
  link->l_inst = NULL;
  link->next = list;
  list = link;
  free(label);
  return (list);
}

void	store_link(t_file *file, t_link *data)
{
  if (data->label != NULL)
    file->label_list = add_label(file->label_list, data->label);

}
