/*
** do_rev.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 19 17:32:15 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 17:39:53 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"

void	do_rev(t_label **list)
{
  t_label	*buf;

  if (*list && (*list)->next)
    rev_label(list);
  buf = *list;
  while (buf)
    {
      if (buf->l_inst && (buf->l_inst)->next)
	rev_inst(&(buf->l_inst));
      buf = buf->next;
    }
}
