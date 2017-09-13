/*
** my_getnbr_base.c for jour_06 in /home/ngonta_e//projet_jour_06
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Oct 17 17:08:52 2010 eugene-valentin ngontang-tchiadjie
** Last update Tue Dec 14 18:58:04 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"commons.h"

int	my_getunit(char c, char *base)
{  
  int	j;

  j = 0;
  while (base[j] != '\0')
    {
      if (c == base[j])
	return (j);
      j = j + 1;
    }
  return (0);
}

int	my_getnbr_base(char *str, char *base)
{
  int   i;
  int   signe;
  int   nbr;
  int	base_len;

  if (my_strlen(str) == 0)
    return (0);
  i = 0;
  signe = 1;
  while ((str[i] != '\0') && ((str[i] == '+') || (str[i] == '-')))
    {
      if (str[i] == '-')
        signe = signe * -1;
      i = i + 1;
    }
  base_len = my_strlen(base);
  nbr = 0;
  while (str[i] != '\0')
    {
      nbr = nbr * base_len;
      nbr = nbr - my_getunit(str[i], base);
      i = i + 1;
    }
  return (nbr * signe * -1);
}
	

 
