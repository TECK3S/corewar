/*
** free_label_stack.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Thu Dec 16 01:57:26 2010 eugene-valentin ngontang-tchiadjie
** Last update Thu Dec 16 02:51:38 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"asm.h"

void	free_label_stack(t_call *all_label)
{
   t_call	*buf;

   buf = all_label;
   while (buf != NULL)
     {
       buf = all_label->next;
       free(all_label->label);
       free(all_label);
       all_label = buf;
     }
}
