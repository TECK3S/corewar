/*
** my_putnbr_pf.c for my_printf in /home/barrau_a//my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Wed Nov 24 19:28:48 2010 adrien barrau
** Last update Mon Dec 13 20:27:07 2010 damien benloukil
*/

#include "commons.h"
#include "xfunctions.h"

void	my_putnbr_pf(int nbr, int *chr_cnt, int fd)
{
  if (nbr < 0)
    {
      xcwrite('-', chr_cnt, fd);
      nbr *= -1;
    }
  if ((nbr / 10) == 0)
    {
      xcwrite(TO_DIGIT(nbr % 10), chr_cnt, fd);
      return;
    }
  my_putnbr_pf(nbr / 10, chr_cnt, fd);
  xcwrite(TO_DIGIT(nbr % 10), chr_cnt, fd);
}
