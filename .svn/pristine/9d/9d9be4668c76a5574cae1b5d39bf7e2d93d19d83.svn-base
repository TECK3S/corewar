/*
** init_SDL.c for init_SDL in /home/bartel_r//svn/corewar_2013s/trunk/vm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Sat Dec 18 17:02:35 2010 remi bartel

*/

#include "op.h"
#include "commons.h"
#include "vm.h"
#include "xfunctions.h"

static void	fill_ind(char *str, int nb, int len)
{
  while (len)
    {
      --len;
      str[len] = (nb % 10) + '0';
      nb /= 10;
    }
}

static void	get_series(SDL_Surface **post, char *path, int nb)
{
  char	*str;
  int	i;
  int	len;

  i = 0;
  while (i < nb)
    {
      len = 4;
      str = xmalloc((my_strlen(path) + len
		     + my_strlen(PIC_EXTEND) + 1) * sizeof(*str));
      my_strncpy(str, path, my_strlen(path));
      fill_ind(str + my_strlen(path), i + 1, len);
      my_strncpy(str + my_strlen(path) + len,
		 PIC_EXTEND, my_strlen(PIC_EXTEND));
      post[i] = IMG_Load(str);
      free(str);
      ++i;
    }
}

static void	load_pictures(SDL_data *SDL)
{
  SDL->base_zero = IMG_Load("vm/pictures/base_zero.png");
  get_series(SDL->base, "vm/pictures/base", 4);
  get_series(SDL->explosion, "vm/pictures/explosion/", 33);
  SDL->helico = IMG_Load("vm/pictures/Helicopter.png");
  SDL->start = IMG_Load("vm/pictures/start.png");
  SDL->tent = IMG_Load("vm/pictures/tent.png");
  get_series(SDL->in[0], "vm/pictures/in/p1/", 10);
  get_series(SDL->in[1], "vm/pictures/in/p2/", 10);
  get_series(SDL->in[2], "vm/pictures/in/p3/", 10);
  get_series(SDL->in[3], "vm/pictures/in/p4/", 10);
  get_series(SDL->out[0], "vm/pictures/out/p1/", 10);
  get_series(SDL->out[1], "vm/pictures/out/p2/", 10);
  get_series(SDL->out[2], "vm/pictures/out/p3/", 10);
  get_series(SDL->out[3], "vm/pictures/out/p4/", 10);
  get_series(SDL->round[0], "vm/pictures/round/p1/", 10);
  get_series(SDL->round[1], "vm/pictures/round/p2/", 10);
  get_series(SDL->round[2], "vm/pictures/round/p3/", 10);
  get_series(SDL->round[3], "vm/pictures/round/p4/", 10);
  get_series(SDL->fond, "vm/pictures/start/", 14);
}

int     init_SDL(t_param_vm *param_vm)
{
  SDL_Rect      pos;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (SDL_ERR_INIT_CODE);
  param_vm->SDL.screen = SDL_SetVideoMode
    (BOARD_WIDTH * SQUARE_SIZE, BOARD_HEIGHT *
     SQUARE_SIZE, BOARD_COLOR, SDL_HWSURFACE
     | SDL_RESIZABLE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption(NAME_WINDOW, NULL);
  load_pictures(&(param_vm->SDL));
  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(param_vm->SDL.start, NULL, param_vm->SDL.screen, &pos);
  SDL_Flip(param_vm->SDL.screen);
  return (on_pause());
}
