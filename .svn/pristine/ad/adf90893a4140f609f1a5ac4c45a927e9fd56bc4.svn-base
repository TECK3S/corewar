/*
** aff_helico.c for coreware in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 19:46:43 2010 adrien barrau
** Last update Sun Dec 19 20:44:48 2010 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include "op.h"
#include "vm.h"
#include "commons.h"

void	aff_buildbase(int i, t_param_vm *param_vm, SDL_Rect *pos)
{
 t_champion ins;

 ins = param_vm->champs[i];
 pos->x = pos->x + 25;
 pos->y = pos->y + 27;
 if (param_vm->champs[i].inlive > 0)
   {
     if (ins.nb_child >= 1 && ins.nb_child < 200)
       SDL_BlitSurface(param_vm->SDL.tent, NULL, param_vm->SDL.screen, pos);
     if (ins.nb_child >= 4000)
       {
	 SDL_BlitSurface(param_vm->SDL.tent, NULL, param_vm->SDL.screen, pos);
	 pos->x = pos->x - 22;
	 SDL_BlitSurface(param_vm->SDL.helico, NULL, param_vm->SDL.screen, pos);
	 pos->x = pos->x + 65;
	 SDL_BlitSurface(param_vm->SDL.tent, NULL, param_vm->SDL.screen, pos);
       }
     if (ins.nb_child >= 200 && ins.nb_child < 4000)
       {
	 pos->x = pos->x + 46;
	 SDL_BlitSurface(param_vm->SDL.tent, NULL, param_vm->SDL.screen, pos);
       }
   }
}
