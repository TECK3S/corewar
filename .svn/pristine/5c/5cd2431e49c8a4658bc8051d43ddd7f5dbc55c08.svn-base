/*
** my_putunbr_pf.c for my_printf in /home/barrau_a//my_printf/my_put_fct
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 02:19:00 2010 adrien barrau
** Last update Mon Dec  6 16:58:35 2010 adrien barrau
*/

#include "commons.h"
#include "xfunctions.h"

void	my_putunbr_pf(unsigned int nbr, int *chr_cnt, int fd)
{
  if ((nbr / 10) == 0)
    {
      xcwrite(TO_DIGIT(nbr % 10), chr_cnt, fd);
      return;
    }
  my_putunbr_pf(nbr / 10, chr_cnt, fd);
  xcwrite(TO_DIGIT(nbr % 10), chr_cnt, fd);
}
