/*
** ins_lfork.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:28:56 2010 adrien barrau
** Last update Fri Dec 17 20:38:54 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"
#include "xfunctions.h"

void	ins_lfork(t_champion *champ,
		  t_param_vm *param_vm,
		  unsigned char **big_male,
		  t_lives *lives)
{
  int		fork_idx;
  t_champion	*child;

  lives = lives;
  fork_idx = 0;
  if (param_vm->ctmo <= 0)
    {
      child = xmalloc(sizeof(*child));
      fork_idx = get_octets_dir(champ, big_male, IND_SIZE, 0);
      if (fork_idx < 0 && champ->pc + fork_idx < 0)
	fork_idx = MEM_SIZE + (champ->pc + fork_idx);
      child = fill_child(child, champ, fork_idx, 1);
      if (param_vm->is_verbose)
	my_printf(V_INS_FORK_MSG, champ->number, child->load_address);
      insert_child(child, champ);
    }
  champ->pc = (champ->pc + 1 + IND_SIZE) % MEM_SIZE;
}
