/*
** ins_sub.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:20:10 2010 adrien barrau
** Last update Sat Dec 18 22:02:57 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void	do_sub(t_champion *champ,
	       t_param_vm *param_vm,
	       unsigned char **big_male)
{
  champ->registers[(*big_male)[TO_ABS((champ->pc + 4) % MEM_SIZE)] - 1] =
    champ->registers[(*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)] - 1]
    - champ->registers[(*big_male)[TO_ABS((champ->pc + 3) % MEM_SIZE)] - 1];
  champ->carry = 0;
  if (champ->registers[(*big_male)[TO_ABS((champ->pc + 4)
					  % MEM_SIZE)] - 1] == 0)
    champ->carry = 1;
  if (param_vm->is_verbose)
    my_printf(V_INS_SUB_MSG,
	      champ->number,
	      (*big_male)[TO_ABS((champ->pc + 3) % MEM_SIZE)],
	      (*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)],
	      (*big_male)[TO_ABS((champ->pc + 4) % MEM_SIZE)]);
  champ->pc = (champ->pc + 5) % MEM_SIZE;
}

void	ins_sub(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives)
{
  unsigned char	*tab_oct;

  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
		   (*big_male)[TO_ABS((champ->pc + 1) % MEM_SIZE)]);
  if (tab_oct)
    {
      if ((*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)] >= 1
	  && (*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)] <= REG_NUMBER
	  && (*big_male)[TO_ABS((champ->pc + 3) % MEM_SIZE)] >= 1
	  && (*big_male)[TO_ABS((champ->pc + 3) % MEM_SIZE)] <= REG_NUMBER
	  && (*big_male)[TO_ABS((champ->pc + 4) % MEM_SIZE)] >= 1
	  && (*big_male)[TO_ABS((champ->pc + 4) % MEM_SIZE)] <= REG_NUMBER)
	do_sub(champ, param_vm, big_male);
      else
	champ->pc = (champ->pc + 1) % MEM_SIZE;
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}
