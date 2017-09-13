/*
** ins_fork.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 11 03:26:29 2010 adrien barrau
** Last update Sat Dec 18 14:12:29 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"
#include "xfunctions.h"

t_champion	*fill_child(t_champion *child,
			    t_champion *champ,
			    int fork_idx,
			    int is_long)
{
  int		i;

  i = 0;
  child->path = champ->path;
  child->name = champ->name;
  child->comment = champ->comment;
  child->number = champ->number;
  child->address_instruction = champ->address_instruction;
  child->load_address = (champ->pc
     + (is_long ? (fork_idx % IDX_MOD) : fork_idx)) % MEM_SIZE;
  child->prog_size = champ->prog_size;
  child->inlive = champ->inlive;
  while (i++ < REG_NUMBER)
    child->registers[i - 1] = champ->registers[i - 1];
  child->pc = child->load_address;
  child->carry = champ->carry;
  child->instruction.code = champ->instruction.code;
  child->instruction.nb_cycle_to_wait = -1;
  child->children = 0;
  if (champ->papounet == 0)
    child->papounet = champ;
  else
    child->papounet = champ->papounet;
  return (child);
}

void	insert_child(t_champion *child, t_champion *champ)
{
  if (champ->papounet == 0)
    {
      child->next = champ->children;
      champ->children = child;
    }
  else
    {
      child->next = champ->papounet->children;
      champ->papounet->children = child;
    }
}

void		ins_fork(t_champion *champ,
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
	fork_idx = MEM_SIZE + (champ->pc + (fork_idx % IDX_MOD));
      child = fill_child(child, champ, fork_idx, 0);
      if (param_vm->is_verbose)
	my_printf(V_INS_FORK_MSG, champ->number, child->load_address);
      insert_child(child, champ);
    }
  champ->pc = (champ->pc + 1 + IND_SIZE) % MEM_SIZE;
}
