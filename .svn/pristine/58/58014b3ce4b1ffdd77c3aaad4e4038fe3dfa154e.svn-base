/*
** my_putnbr_base_pf.c for my_printf in /home/barrau_a//c/my_printf
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Thu Nov 25 13:30:18 2010 adrien barrau
** Last update Mon Dec  6 16:54:35 2010 adrien barrau
*/

#include "commons.h"

void	my_putnbr_base_pf(unsigned int nbr, char *base, int *chr_cnt, int fd)
{
  int	nb_base;

  nb_base = my_strlen(base);
  if ((nbr / nb_base) == 0)
    {
      xcwrite(base[nbr % nb_base], chr_cnt, fd);
      return;
    }
  my_putnbr_base_pf(nbr / nb_base, base, chr_cnt, fd);
  xcwrite(base[nbr % nb_base], chr_cnt, fd);
}
