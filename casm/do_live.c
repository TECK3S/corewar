/*
** do_live.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Dec 14 03:12:29 2010 eugene-valentin ngontang-tchiadjie
   Last update Sun Dec 19 23:01:50 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:38:35 2010 remi bartel
*/

#include	"asm.h"
#include	"op.h"

void	do_live(unsigned char **str, int *i,
		char **params, t_param **call_list)
{
  int	pc;

  pc = *i - 1;
  store_addr_call(call_list, pc, params[0], REG_SIZE);
  *str = put_param(*str, i, REG_SIZE, params[0]);
}
