/*
** my_put_nbr.c for my_put_nbr in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/assem
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Tue Nov 30 21:11:45 2010 eugene-valentin ngontang-tchiadjie
** Last update Tue Nov 30 21:13:36 2010 eugene-valentin ngontang-tchiadjie
*/

#include "lib_assem.h"

void	my_put_nbr(int nbr)
{
  if (nbr <= -10 || nbr >= 10)
    my_put_nbr(nbr / 10);
  else if (nbr < 0)
    my_putchar('-');
  nbr %= 10;
  if (nbr < 0)
    nbr *= -1;
  my_putchar(nbr + '0');
}
