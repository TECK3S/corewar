/*
** my_rev_list.c for my_rev_list in /home/bartel_r//afs/rendu/piscine/Jour_11
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Wed Oct 20 12:01:09 2010 remi bartel
** Last update Thu Dec  9 22:37:43 2010 remi bartel
*/

#include "op.h"
#include "asm.h"
#include "commons.h"

int	my_rev_label(t_label **begin)
{
  t_label	*current;
  t_label	*end;
  t_label	*tmp;

  end = NULL;
  current = *begin;
  while (current->next != 0)
    {
      current = current->next;
    }
  end = current;
  while (*begin != end)
    {
      current = *begin;
      while (current != end)
	{
	  current = current->next;
	}
      tmp = (*begin);
      *begin = (*begin)->next;
      tmp->next = end->next;
      end->next = tmp;
    }
  return (0);
}
