/*
** virtual_machine_core.c for coreware  in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Wed Dec  8 17:32:06 2010 damien benloukil
** Last update Sat Dec 18 22:38:47 2010 adrien barrau
*/

#include <SDL/SDL.h>
#include "commons.h"
#include "op.h"
#include "vm.h"

void	throw_champ(t_champion *champ,
		    t_param_vm *param_vm,
		    t_lives *lives,
		    unsigned char **big_male)
{
  if (champ->instruction.nb_cycle_to_wait == -1)
    {
      champ->instruction.code = (*big_male)[TO_ABS(champ->pc % MEM_SIZE)];
      if (champ->instruction.code > MAX_INSTRUCTION ||
	  champ->instruction.code < MIN_INSTRUCTION)
	champ->instruction.code = UNKNOWN_INSTRUCTION_CODE;
      champ->instruction.nb_cycle_to_wait =
	op_tab[champ->instruction.code - 1].nbr_cycles;
    }
  if (champ->instruction.nb_cycle_to_wait == 0)
    {
      if ((champ->instruction.code <= MAX_INSTRUCTION &&
	   champ->instruction.code >= MIN_INSTRUCTION)
	  || champ->instruction.code == UNKNOWN_INSTRUCTION_CODE)
	gl_instructions[champ->instruction.code](champ, param_vm, big_male, lives);
    }
  champ->instruction.nb_cycle_to_wait -= 1;
}

void		exec_champs(t_param_vm *param_vm,
			    t_lives *lives,
			    unsigned char **big_male)
{
  t_champion	*child;

  lives->count = 0;
  while (lives->count < MAX_CHAMPS)
    {
      if (param_vm->champs[lives->count].path
	  && param_vm->champs[lives->count].inlive)
	{
	  throw_champ(&(param_vm->champs[lives->count]),
		      param_vm, lives, big_male);
	  child = param_vm->champs[lives->count].children;
	  while (child)
	    {
	      if (child->inlive)
		throw_champ(child, param_vm, lives, big_male);
	      child = child->next;
	    }
	}
      lives->count += 1;
    }
}

void	init_lives(t_lives *lives)
{
  int	i;

  i = 0;
  lives->is_alive = 0;
  lives->live = 0;
  lives->cycle = 0;
  lives->cycle_to_die = CYCLE_TO_DIE;
  while (i < MAX_CHAMPS)
    lives->tab_inlive[i++] = 0;
}

void	virtual_machine_core(t_param_vm *param_vm, unsigned char *big_male)
{
  int		dumped;
  int		champs_inlive;
  t_lives	lives;

  init_lives(&lives);
  dumped = 0;
  champs_inlive = 2;
  while (champs_inlive > 1 && lives.cycle_to_die > 0 && !dumped)
    {
      exec_champs(param_vm, &lives, &big_male);
      champs_inlive  = check_live_champs(&lives, param_vm);
      dumped = check_dump(param_vm, big_male, lives.cycle);
      update_ctmo(param_vm);
      ++(lives.cycle);
      if (param_vm->opt_graph)
	if (manage_event(param_vm, big_male, &lives) != 1)
	  break;
    }
  if (!dumped)
    and_the_winner_is(param_vm, &lives);
}
