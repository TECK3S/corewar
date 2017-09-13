/*
** catch_SDL_events.c for catch_events in /home/bartel_r//svn/corewar_2013s/trunk/vm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Wed Dec 15 20:02:27 2010 remi bartel
** Last update Sun Dec 19 17:51:23 2010 damien benloukil
*/

#include "op.h"
#include "vm.h"

int	manage_event(t_param_vm *param_vm,
		     unsigned char *big_male,
		     t_lives *lives)
{
  SDL_Event	event;
  int		val;

  val = 1;
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	val = 0;
      else if (event.key.keysym.sym == SDLK_ESCAPE)
	val = 0;
      else if (event.key.keysym.sym == SDLK_p)
	if ((on_pause()) == 0)
	  val = 0;
    }
  update_graphic(param_vm, big_male, lives);
  return (val);
}

