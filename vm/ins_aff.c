/*
** ins_aff.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:29:15 2010 adrien barrau
** Last update Sat Dec 18 16:10:20 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void	ins_aff(t_champion *champ,
		t_param_vm *param_vm,
		unsigned char **big_male,
		t_lives *lives)
{
  unsigned char	*tab_oct;

  param_vm = param_vm;
  lives = lives;
  tab_oct = check_oct_param(champ->instruction.code,
			    (*big_male)[TO_ABS((champ->pc + 1) % MEM_SIZE)]);
  if (tab_oct)
    {
      if ((*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)] >= 1
	  && (*big_male)[TO_ABS((champ->pc + 2) % MEM_SIZE)] <= REG_NUMBER)
	{
	  my_printf("%c", (champ->registers[(*big_male)[TO_ABS((champ->pc + 2)
				     % MEM_SIZE)] - 1]) % ASCII_TABLE_SIZE);
	  champ->pc = (champ->pc + 3) % MEM_SIZE;
	}
      else
	champ->pc = (champ->pc + 1) % MEM_SIZE;
    }
  else
    champ->pc = (champ->pc + 1) % MEM_SIZE;
  free(tab_oct);
}
