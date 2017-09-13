/*
** launch_virtual_machine.c for corewar in /home/benlou_d//proj/coreware/corewar_2013s/trunk
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Fri Dec  3 20:41:42 2010 damien benloukil
** Last update Sat Dec 18 02:34:43 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

void		free_champs(t_param_vm *param_vm)
{
  int		i;
  t_champion	*child_prev;
  t_champion	*child_current;

  i = 0;
  while (i < MAX_CHAMPS)
    {
      free(param_vm->champs[i].name);
      free(param_vm->champs[i].comment);
      child_prev = 0;
      child_current = param_vm->champs[i].children;
      while (child_current)
	{
	  child_prev = child_current;
	  child_current = child_current->next;
	  free(child_prev);
	}
      i++;
    }
}

int	launch_virtual_machine(t_param_vm *param_vm)
{
  int		ok;
  unsigned char *big_male;

  ok = 1;
  get_progs_number(param_vm);
  get_load_address(param_vm);
  big_male = big_malloc();
  ok = check_valid_champs(param_vm, big_male);
  if (ok > 0)
    virtual_machine_core(param_vm, big_male);
  free_champs(param_vm);
  free (big_male);
  return (ok);
}
