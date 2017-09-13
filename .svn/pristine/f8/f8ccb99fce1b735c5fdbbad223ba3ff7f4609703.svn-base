/*
** my_rev_list.c for my_rev_list in /home/bartel_r//afs/rendu/piscine/Jour_11
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Wed Oct 20 12:01:09 2010 remi bartel
** Last update Sat Dec 11 15:46:55 2010 remi bartel
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

void	rev_inst(t_inst **begin)
{
  t_inst	*current;
  t_inst	*end;
  t_inst	*tmp;

  end = NULL;
  current = *begin;
  while (current->next != 0)
    current = current->next;
  end = current;
  while (*begin != end)
    {
      current = *begin;
      while (current != end)
	current = current->next;
      tmp = (*begin);
      *begin = (*begin)->next;
      tmp->next = end->next;
      end->next = tmp;
    }
}
