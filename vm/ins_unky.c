/*
** ins_unky.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:30:04 2010 adrien barrau
** Last update Fri Dec 17 17:56:18 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void	ins_unky(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives)
{
  big_male = big_male;
  lives = lives;
  if (param_vm->is_verbose)
    my_printf(V_INS_UNKY_MSG, champ->number);
  champ->pc = (champ->pc + 1) % MEM_SIZE;
}
