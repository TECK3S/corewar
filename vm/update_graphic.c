/*
** update_graphic.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Fri Dec 17 10:27:15 2010 damien benloukil
** Last update Sun Dec 19 20:23:16 2010 adrien barrau
*/

#include <stdlib.h>
#include <stdio.h>
#include "op.h"
#include "vm.h"
#include "commons.h"

void	first_quarter(t_param_vm *param_vm, int i, SDL_Rect *pos)
{
  if (param_vm->info_graph.ratio <= FIRST_QUARTER
      && param_vm->info_graph.ratio > 0)
    {
      if (param_vm->champs[i].load_address < IMG_CHAMP_SIZE_X)
	pos->x = 0;
      else
	pos->x = (param_vm->info_graph.ratio * QUARTER * WINDOW_WIDTH)
	  - IMG_CHAMP_SIZE_X;
      pos->y = 0;
   }
}

void    second_quarter(t_param_vm *param_vm, SDL_Rect *pos)
{
  if (param_vm->info_graph.ratio <= SECOND_QUARTER
      && param_vm->info_graph.ratio > FIRST_QUARTER)
    {
      pos->x = WINDOW_WIDTH - IMG_CHAMP_SIZE_X;
      pos->y = (param_vm->info_graph.ratio - FIRST_QUARTER)
	* QUARTER * WINDOW_HEIGHT - IMG_CHAMP_SIZE_Y;
    }
}

void    third_quarter(t_param_vm *param_vm, SDL_Rect *pos)
{
  if (param_vm->info_graph.ratio <= THIRD_QUARTER
      && param_vm->info_graph.ratio > SECOND_QUARTER)
    {
      pos->x = (1 -(param_vm->info_graph.ratio - SECOND_QUARTER) * QUARTER);
      pos->y = WINDOW_HEIGHT - IMG_CHAMP_SIZE_Y;
    }
}

void    fourth_quarter(t_param_vm *param_vm, int i, SDL_Rect *pos)
{
  if (param_vm->info_graph.ratio > THIRD_QUARTER)
    {
      pos->x = 0;
           if (param_vm->champs[i].load_address > MEM_SIZE - IMG_CHAMP_SIZE_X)
	pos->y = 0;
      else
	pos->y = ((1 -param_vm->info_graph.ratio) *
		  QUARTER * WINDOW_HEIGHT) - IMG_CHAMP_SIZE_Y;
    }
}

void	update_graphic(t_param_vm *param_vm,
		       unsigned char *big_male,
		       t_lives *lives)
{
  SDL_Rect		pos;
  int			i;

  param_vm->info_graph.lives = lives;
  param_vm->info_graph.big_male = big_male;
  frame_per_sec(param_vm, &pos);
  i = 0;
  while (i < MAX_CHAMPS)
    {
      if (param_vm->champs[i].path)
	{
	  param_vm->info_graph.ratio =
	    ((float)param_vm->champs[i].load_address) / (float)MEM_SIZE;
	  pos.x = 0;
	  pos.y = 0;
	  first_quarter(param_vm, i, &pos);
	  second_quarter(param_vm, &pos);
	  third_quarter(param_vm, &pos);
	  fourth_quarter(param_vm, i, &pos);
	  aff_base(i, param_vm, &pos);
	  aff_buildbase(i, param_vm, &pos);
	  aff_instruction(param_vm, &pos, i);
	}
      i ++;
    }
}

