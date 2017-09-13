/*
** check_live_champs.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 22:21:54 2010 adrien barrau
** Last update Sun Dec 19 16:14:36 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	is_not_alone(t_lives *lives)
{
  int	i;
  int	inlive;

  i = 0;
  inlive = 0;
  while (i < MAX_CHAMPS)
    {
      if (lives->tab_inlive[i] == 1)
	inlive++;
      lives->tab_inlive[i] = 0;
      i++;
    }
  return (inlive);
}

static void	check_live_children(t_param_vm *param_vm, int i)
{
  t_champion	*child;

  child = param_vm->champs[i].children;
  while (child)
    {
      if (child->inlive == 2)
	child->inlive = 1;
      else if (child->inlive == 1)
	child->inlive = 0;
      child = child->next;
    }
}

int		check_live_champs(t_lives *lives,
				  t_param_vm *param_vm)
{
  int		i;
  int		inlive;

  i = 0;
  inlive = 2;
  if (lives->cycle >= lives->cycle_to_die)
    {
      while (i < MAX_CHAMPS)
	{
	  if (param_vm->champs[i].path)
	    {
	      if (lives->tab_inlive[i] == 1)
		{
		  param_vm->champs[i].inlive = 1;
		  check_live_children(param_vm, i);
		}
	      else
		param_vm->champs[i].inlive = 0;
	    }
	  i++;
	}
      inlive = is_not_alone(lives);
      lives->cycle = 0;
    }
  return (inlive);
}
