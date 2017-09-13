/*
** check_call.c for check_call in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Thu Dec  9 21:11:19 2010 remi bartel
** Last update Sun Dec 19 18:39:42 2010 remi bartel
*/

#include <stdlib.h>
#include "xfunctions.h"
#include "asm.h"
#include "commons.h"

static	int	is_defined(char *label, t_label *label_list)
{
  while (label_list != NULL)
    {
      if (my_strcmp(label, label_list->label) == 0)
	return (1);
      label_list = label_list->next;
    }
  return (0);
}

int	check_call(t_call *call_list, t_label *label_list)
{
  while (call_list != NULL)
    {
      if (is_defined(call_list->label, label_list) == 0)
	{
	  my_fprintf(STDERR, "\nError: line %d : ", call_list->line);
	  my_fprintf(STDERR, "%s %s\n", CALL_ERROR, call_list->label);
	  return (0);
	}
      call_list = call_list->next;
    }
  return (1);
}
