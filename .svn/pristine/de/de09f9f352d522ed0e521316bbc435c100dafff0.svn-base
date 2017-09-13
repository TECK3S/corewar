/*
** my_rev_list.c for my_rev_list in /home/bartel_r//afs/rendu/piscine/Jour_11
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Wed Oct 20 12:01:09 2010 remi bartel
** Last update Wed Dec 15 17:42:59 2010 eugene-valentin ngontang-tchiadjie
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

void	rev_label(t_label **begin)
{
  t_label	*current;
  t_label	*end;
  t_label	*tmp;

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
