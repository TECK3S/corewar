/*
** time_graph.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Sun Dec 19 17:33:16 2010 damien benloukil
   Last update Sun Dec 19 23:14:21 2010 damien benloukil
*/

#include <stdlib.h>
#include <stdio.h>
#include "op.h"
#include "vm.h"
#include "commons.h"

void	frame_per_sec(t_param_vm *param_vm, SDL_Rect *pos)
{
  static unsigned int	old_tick = 0;
  unsigned int		new_tick;
  static   int		i = 0;
  static   int			temp;

  param_vm = param_vm;
  pos->x = 0;
  pos->y = 0;
  new_tick = SDL_GetTicks();
  if ((new_tick - old_tick) > REFRESH)
    {
      SDL_Flip(param_vm->SDL.screen);
      SDL_BlitSurface(param_vm->SDL.fond[i], NULL, param_vm->SDL.screen, pos);
      old_tick = new_tick;
      if (i == 14)
	temp = 1;
      else if (i == 0)
	temp = 0;
      if (temp == 0)
	i ++;
      else
	i --;
    }
}
