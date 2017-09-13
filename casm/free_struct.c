/*
** free_struct.c for free_struct in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Thu Dec  9 21:12:39 2010 remi bartel
   Last update Sun Dec 19 23:03:03 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:39:51 2010 remi bartel
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"commons.h"

void		free_inst(t_inst *instruction)
{
  t_inst	*buf;

  while (instruction != NULL)
    {
      buf = instruction;
      instruction = instruction->next;
      free(buf->mnemo);
      my_free_wt(buf->params);
      free(buf);
    }
}

void		free_label(t_label *label_list)
{
  t_label	*buf;

  buf = label_list;
  while (buf != NULL)
    {
      buf = label_list->next;
      free_inst(label_list->l_inst);
      free(label_list->label);
      free(label_list);
      label_list = buf;
    }
}

void	free_file(t_file *file)
{
  free_label(file->label_list);
  free(file->header);
  free(file->filename);
  free(file);
}
