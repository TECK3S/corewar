/*
** get_load_address.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 04:01:43 2010 adrien barrau
** Last update Sat Dec 18 04:01:44 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "xfunctions.h"
#include "vm.h"

int	*get_la_value(t_param_vm *param_vm)
{
  int	i;
  int	*res;
  int	*old_res;
  int	len;

  len = 0;
  old_res = 0;
  res = xmalloc(1 * sizeof(*res));
  i = 0;
  res[0] = -1;
  while (i < MAX_CHAMPS)
    {
      if (param_vm->champs[i].load_address != -1)
	{
	  old_res = res;
	  len = my_tab_intlen(res);
	  res = xmalloc((len + 2) * sizeof(*res));
	  res = my_tab_intcpy(res, old_res);
	  res[len] = param_vm->champs[i].load_address;
	  res[len + 1] = -1;
	  free(old_res);
	}
      i = i + 1;
    }
  return (res);
}

void	add_load_address(int **la, int new_address)
{
  int	*old_res;
  int	len;

  old_res = *la;
  len = my_tab_intlen(*la);
  *la = xmalloc((len + 2) * sizeof(*la));
  *la = my_tab_intcpy(*la, old_res);
  (*la)[len] = new_address;
  (*la)[len + 1] = -1;
  free(old_res);
}

void	reset_address(int *max, int *idx, int **la)
{
  if ((*la)[0] == -1)
    {
      *max = 0;
      *idx = 0;
    }
}

void	find_far_address(t_param_vm *param_vm, int nbc, int **la)
{
  int	i;
  int	max;
  int	idx;

  idx = 0;
  max = 0;
  i = 0;
  while ((*la)[i] != -1 && (*la)[i + 1] != -1)
    {
      if (max < (*la)[i + 1] - (*la)[i])
	{
	  max = (*la)[i + 1] - (*la)[i];
	  idx = (*la)[i];
	}
      i = i + 1;
    }
  if (max < (MEM_SIZE - (*la)[i] + (*la)[0]))
    {
      max = MEM_SIZE - (*la)[i] + (*la)[0];
      idx = (*la)[i];
    }
  reset_address(&max, &idx, la);
  param_vm->champs[nbc].load_address =  ((max / 2) + idx) % MEM_SIZE;
  add_load_address(la, ((max / 2) + idx) % MEM_SIZE);
}

void	get_load_address(t_param_vm *param_vm)
{
  int	i;
  int	*la;

  la = get_la_value(param_vm);
  i = 0;
  my_sorttab_int(&la);
  while (i < MAX_CHAMPS)
    {
      if (param_vm->champs[i].load_address == -1 && param_vm->champs[i].path)
	{
	  find_far_address(param_vm, i, &la);
	  la = my_sorttab_int(&la);
	}
      i = i + 1;
    }
   free(la);
}
