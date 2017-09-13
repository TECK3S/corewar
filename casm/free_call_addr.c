/*
** free_call_addr.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Dec 16 01:55:32 2010 eugene-valentin ngontang-tchiadjie
** Last update Thu Dec 16 02:52:10 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"asm.h"

void	free_call_addr(t_param *call_list)
{
  t_param 	*buf;

  buf = call_list;
  while (buf != NULL)
    {
      buf = call_list->next;
      free(call_list->name);
      free(call_list);
      call_list = buf;
    }
}
