/*
** aff_graph.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Sun Dec 19 16:03:01 2010 damien benloukil
** Last update Sun Dec 19 19:04:20 2010 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include "op.h"
#include "vm.h"
#include "commons.h"

static void	get_pos(SDL_Rect *pos, t_champion *ins)
{
  pos->x = (ins->address_instruction) % 96;
  pos->y = ((ins->address_instruction / 64) % 64);
  pos->x = (pos->x * 10);
  pos->y = (pos->y * 10);
}

void	aff_children(t_param_vm *param_vm, SDL_Rect *pos, int i)
{
  t_champion	*ins;

  ins = param_vm->champs[i].children;
  while (ins != NULL && ins->next != NULL)
    {
        if (ins->address_instruction != 0 && param_vm->champs[i].inlive > 0)
	{
	  get_pos(pos, ins);
	  if (ins->address_instruction != 0 && param_vm->champs[i].inlive > 0)
	    {
	      if ((ins->instruction.code == 2 || ins->instruction.code == 10
		   || ins->instruction.code == 13 || ins->instruction.code == 14))
		SDL_BlitSurface(param_vm->SDL.out[i][SDL_GetTicks() % 10], NULL,
				param_vm->SDL.screen, pos);
	      else if ((ins->instruction.code == 3 || ins->instruction.code == 11))
		SDL_BlitSurface(param_vm->SDL.in[i][SDL_GetTicks() % 10],
				NULL, param_vm->SDL.screen, pos);
	      else
		SDL_BlitSurface(param_vm->SDL.round[i][SDL_GetTicks() % 10],
				NULL, param_vm->SDL.screen, pos);
	    }
	  param_vm->champs[i].nb_child += 1;
	}
      ins = ins->next;
    }
}

void	 aff_instruction(t_param_vm *param_vm, SDL_Rect *pos, int i)
{
  pos->x = (param_vm->champs[i].address_instruction) % 96;
  pos->y = ((param_vm->champs[i].address_instruction / 64) % 64);
  pos->x = (pos->x * 10);
  pos->y = (pos->y * 10);
  if (param_vm->champs[i].address_instruction != 0 &&
      param_vm->champs[i].inlive > 0)
    {
      if ((param_vm->champs[i].instruction.code == 2 ||
	   param_vm->champs[i].instruction.code == 10 ||
	   param_vm->champs[i].instruction.code == 13 ||
	   param_vm->champs[i].instruction.code == 14))
	SDL_BlitSurface(param_vm->SDL.out[i][SDL_GetTicks() % 10],
			NULL, param_vm->SDL.screen, pos);
      else if ((param_vm->champs[i].instruction.code == 3 ||
		param_vm->champs[i].instruction.code == 11))
	SDL_BlitSurface(param_vm->SDL.in[i][SDL_GetTicks() % 10], NULL,
			param_vm->SDL.screen, pos);
      else
	SDL_BlitSurface(param_vm->SDL.round[i][SDL_GetTicks() % 10], NULL,
			param_vm->SDL.screen, pos);
    }
  aff_children(param_vm, pos, i);
}

void	aff_base(int i, t_param_vm *param_vm, SDL_Rect *pos)
{
  static int champ[MAX_CHAMPS] = {0};

  if (param_vm->champs[i].inlive == 0)
    {
      if (champ[i] != 32)
	SDL_BlitSurface(param_vm->SDL.explosion[champ[i]++],
			NULL, param_vm->SDL.screen, pos);
      else
	SDL_BlitSurface(param_vm->SDL.base_zero, NULL,
			param_vm->SDL.screen, pos);
    }
  else
    SDL_BlitSurface(param_vm->SDL.base[i], NULL,
		    param_vm->SDL.screen, pos);
}
