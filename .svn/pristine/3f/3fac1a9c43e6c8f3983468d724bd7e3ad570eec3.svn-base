/*
** whole_parsing.c for whole_parsing in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Thu Dec  9 21:13:03 2010 remi bartel
   Last update Sun Dec 19 23:28:21 2010 mickael benichou
*/

#include <stdlib.h>
#include "xfunctions.h"
#include "asm.h"
#include "commons.h"

static	void	check_type_inst(t_link *link,
				t_file *file, t_call **call_list, int line)
{
  if (link->add != 1)
    fill_header(file, link->add, link->label);
  else
    my_put_inlist(link, &(file->label_list), call_list, line);
}

static	void	reset_link(t_link *link)
{
  link->nb = 0;
  link->extd = 0;
  link->add = 0;
  if (link->label != NULL)
    {
      free(link->label);
      link->label = NULL;
    }
  if (link->mnemo != NULL)
    {
      free(link->mnemo);
      link->mnemo = NULL;
    }
  if (link->inst != NULL)
    {
      free(link->inst);
      link->inst = NULL;
    }
}

static       void	free_call(t_call *call_list)
{
  t_call	*buf;

  buf = call_list;
  while (buf != NULL)
    {
      buf = call_list->next;
      free(call_list->label);
      free(call_list);
      call_list = buf;
    }
}

static void	init_data(t_link *link, int *line, int *cmp)
{
  link->spe = 0;
  link->add = 0;
  link->extd = 0;
  link->label = NULL;
  link->mnemo = NULL;
  link->inst = NULL;
  *cmp = 1;
  *line = 1;
}

int	whole_parsing(int fd, t_file *file)
 {
  char		*s;
  t_call	*call_list;
  t_link	link;
  int		line_count;
  int		cmp;

  call_list = NULL;
  s = NULL;
  init_data(&link, &line_count, &cmp);
  while ((s = get_next_line(fd)))
    {
      if ((parsing(s, line_count, &link) == 0) && cmp == 1)
	cmp = 0;
      if (link.add && cmp == 1)
     	check_type_inst(&link, file, &call_list, line_count);
      line_count++;
      free(s);
      reset_link(&link);
    }
  if (cmp == 1)
    cmp = check_call(call_list, file->label_list);
  free_call(call_list);
  do_rev(&file->label_list);
  return (cmp);
}
