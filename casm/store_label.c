/*
** store_label.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Dec 16 01:53:24 2010 eugene-valentin ngontang-tchiadjie
   Last update Sun Dec 19 19:36:57 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 12:29:05 2010 mickael benichou
*/

#include	"xfunctions.h"
#include	"asm.h"
#include	"commons.h"

void	store_label(t_call **all_label, char *label, int i)
{
  t_call	*element;

  element = xmalloc(sizeof(*element));
  element->label = my_strdup(label);
  element->line = i;
  element->next = *all_label;
  *all_label = element;
  return ;
}
