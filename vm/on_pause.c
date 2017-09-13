/*
** on_pause.c for on_pause in /home/bartel_r//svn/corewar_2013s/trunk/vm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Wed Dec 15 15:42:01 2010 remi bartel
** Last update Sat Dec 18 18:15:43 2010 remi bartel
*/

#include "op.h"
#include "vm.h"
#include "commons.h"

int	on_pause(void)
{
  int		pause;
  SDL_Event	event;

  pause = 2;
  while (pause == 2)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
        pause = 0;
      if (event.type == SDL_KEYDOWN)
	{
	  if (!(event.key.keysym.sym == SDLK_ESCAPE))
	    pause = 1;
	  else
	    pause = 0;
	}
    }
  return (pause);
}
