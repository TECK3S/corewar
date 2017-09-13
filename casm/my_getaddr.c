/*
** my_getnbr.c for jour_04 in /home/ngonta_e//projet_jour_04
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Oct 16 17:03:53 2010 eugene-valentin ngontang-tchiadjie
** Last update Sat Dec 18 19:12:23 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"op.h"
#include	"asm.h"
#include	"commons.h"

int	my_getaddr(char *str)
{
  int	i;
  int	signe;
  int	nbr;

  nbr = 0;
  i = 0;
  signe = 1;
  while ((str[i] != '\0') && ((str[i] == PLUS) || (str[i] == MINUS)))
    {
      if (str[i] == MINUS)
	signe = signe * -1;
      i = i + 1;
    }
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      nbr = nbr * 10;
      nbr = nbr - (str[i] - '0');
      i = i + 1;
    }
  return (nbr * signe * (-1));
}
