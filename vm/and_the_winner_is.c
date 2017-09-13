/*
** and_the_winner_is.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Dec 17 23:46:41 2010 adrien barrau
** Last update Fri Dec 17 23:46:57 2010 adrien barrau
*/

#include "op.h"
#include "vm.h"
#include "commons.h"

void	print_winner(t_param_vm *param_vm, int winner)
{
  int	i;
  int	found;

  i = 0;
  found = 0;
  if (winner)
    {
      while (i < MAX_CHAMPS && !found)
	{
	  if (winner == param_vm->champs[i].number)
	    {
	      my_printf(WIN_MSG, winner, param_vm->champs[i].name);
	      if (winner && param_vm->have_comment)
		my_printf(COMMENT_WIN_MSG, param_vm->champs[i].comment);
	      my_printf("\n");
	      found = 1;
	    }
	  i++;
	}
    }
  else
    my_printf(DRAW_MATCH_MSG);
}

void	and_the_winner_is(t_param_vm *param_vm, t_lives *lives)
{
  int	i;
  int	found;
  int	winner;
  char	*comment;
  char	*name;

  winner = 0;
  found = 0;
  i = 0;
  comment = 0;
  name = 0;
  while (i < MAX_CHAMPS && !found)
    {
      if (lives->tab_inlive[i])
	{
	  found = 1;
	  winner = param_vm->champs[i].number;
	}
      i++;
    }
  if (winner == 0)
    winner = lives->is_alive;
  print_winner(param_vm, winner);
}
