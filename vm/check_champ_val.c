/*
** check_champ_val.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Dec 17 23:47:30 2010 adrien barrau
** Last update Fri Dec 17 23:47:31 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"

int	check_load_address(int *load_address,
			   t_args_par *args_par,
			   int *i,
			   int *current_champ)
{
  int	ok;

  ok = 1;
  if (*load_address)
    ok = OPT_A_EXIST_ERR_CODE;
  else
    {
      if (args_par->ac > *i + 1
	  && str_isnum((args_par->av)[*i + 1])
	  && (*load_address = my_getnbr((args_par->av)[*i + 1])) >= 0
	  && *load_address < MEM_SIZE)
	{
	  (((args_par->param_vm)->champs)[*current_champ]).load_address
	    = *load_address;
	  *i = *i + 1;
	}
      else
	ok = OPT_A_BAD_ERR_CODE;
    }
  return (ok);
}

int	check_prog_number(int *prog_number,
			  t_args_par *args_par,
			  int *i,
			  int *current_champ)
{
  int	ok;

  ok = 1;
  if (*prog_number)
    ok = OPT_N_EXIST_ERR_CODE;
  else
    {
      if (args_par->ac > *i + 1
	  && str_isnum((args_par->av)[*i + 1])
	  && (*prog_number = is_valid((args_par->av)[*i + 1],
				     args_par->param_vm)))
	{
	  (((args_par->param_vm)->champs)[*current_champ]).number
	    = *prog_number;
	  *i = *i + 1;
	}
      else
	ok = OPT_N_BAD_ERR_CODE;
    }
  return (ok);
}

int	check_add_champ(t_args_par *args_par, int *i, int *current_champ)
{
  int	ok;

  ok = 1;
  if (*i < args_par->ac)
    add_champ(args_par->param_vm, args_par->av[*i], current_champ);
  else
    ok = OPT_TOO_FEW_ARG_CODE;
  return (ok);
}

int     check_champ_val(t_args_par *args_par,
			int *current_champ,
			int *i)
{
  int	ok;
  int	load_address;
  int	prog_number;

  ok = 1;
  load_address = 0;
  prog_number = 0;
  if (*current_champ < MAX_CHAMPS)
    {
      while (args_par->ac > *i && (args_par->av)[*i][0] == '-' && ok > 0)
	{
	  if (my_strcmp(&((args_par->av)[*i][1]), A_NAME) == 0)
	    ok = check_load_address(&load_address, args_par, i, current_champ);
	  else if (my_strcmp(&((args_par->av)[*i][1]), N_NAME) == 0)
	    ok = check_prog_number(&prog_number, args_par, i, current_champ);
	  else
	    ok = OPT_BAD_OPT_ERR_CODE;
	  *i = *i + 1;
	}
      if (ok > 0)
	ok = check_add_champ(args_par, i, current_champ);
    }
  else
    ok = TOO_MANY_CHAMPS_ERR_CODE;
  return (ok);
}
