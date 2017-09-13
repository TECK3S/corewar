/*
** ins_live.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Dec  9 00:36:41 2010 damien benloukil
** Last update Sun Dec 19 16:11:25 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

static void	get_champ_num(t_param_vm *param_vm,
			      int num_live,
			      int *champ_num)
{
  int	i;
  int	found;

  i = 0;
  found = 0;
  while (i < MAX_CHAMPS && !found)
    {
      if (num_live == ((param_vm->champs)[i]).number
	  && param_vm->champs[i].path
	  && param_vm->champs[i].inlive)
	{
	  *champ_num = i;
	  found = 1;
	}
      i++;
    }
}

void	ins_live(t_champion *champ,
		 t_param_vm *param_vm,
		 unsigned char **big_male,
		 t_lives *lives)
{
  int	num_live;
  int	champ_num;

  champ_num = -1;
  num_live = get_octets_dir(champ, big_male, DIR_SIZE, 0);
  champ->inlive = 2;
  lives->live = lives->live + 1;
  if (lives->live >= NBR_LIVE)
    {
      lives->cycle_to_die = lives->cycle_to_die - CYCLE_DELTA;
      lives->live = 0;
    }
  get_champ_num(param_vm, num_live, &champ_num);
  if (num_live >= 1 && num_live <= MAX_CHAMPS
      && champ_num != -1
      && param_vm->champs[champ_num].path
      && param_vm->champs[champ_num].inlive)
    {
      if (param_vm->is_verbose)
	my_printf(V_INS_LIVE_MSG, num_live);
      lives->tab_inlive[champ_num] = 1;
      lives->is_alive = num_live;
    }
  champ->pc = (((champ->pc + 1) % MEM_SIZE) + DIR_SIZE) % MEM_SIZE;
}
