/*
** trunc_nbr.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 18 00:42:00 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 17:28:30 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"
#include	"commons.h"

static char	*check_and_trunc(char *str)
{
  if (str && str[0] == MINUS)
    {
      if (my_compar(&(str[1]), NEG_BOUND) > 0)
	str = trunc_neg(str);
    }
  else if (str )
    {
      if (my_compar(str, POS_BOUND) > 0)
	str = trunc_pos(str);
    }
  return (str);
}

char	*trunc_nbr(char	*str)
{
  char	*new_str;
  int	i;
  int	signe;

  i = 0;
  signe = 1;
  while ((str[i] != '\0') && ((str[i] == PLUS) || (str[i] == MINUS)))
    {
      if (str[i] == MINUS)
	signe = signe * -1;
      i = i + 1;
    }
  if (signe == -1)
    {
      i = i - 1;
      str[i] = MINUS;
    }
  new_str = my_strdup(&str[i]);
  free(str);
  new_str = check_and_trunc(new_str);
  return (new_str);
}
