/*
** ins_zjmp.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:23:31 2010 adrien barrau
** Last update Sat Dec 18 00:31:36 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void	ins_zjmp(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives)
{
  int	i;
  int	jump_idx;

  param_vm = param_vm;
  lives = lives;
  i = 0;
  jump_idx = get_octets_dir(champ, big_male, IND_SIZE, 0);
  if (jump_idx < 0 && champ->pc + jump_idx < 0)
    jump_idx = MEM_SIZE + (champ->pc + (jump_idx % IDX_MOD));
  if (champ->carry == 1)
    {
      champ->pc = (champ->pc + (jump_idx % IDX_MOD)) % MEM_SIZE;
      if (param_vm->is_verbose)
	my_printf(V_INS_ZJMP_MSG, champ->number, champ->pc);
    }
  else
    champ->pc = (champ->pc + 1 + IND_SIZE) % MEM_SIZE;
}
