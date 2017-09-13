/*
** my_int_to_char.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 19 01:34:34 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 14:07:22 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"commons.h"
#include	"xfunctions.h"
#include	"asm.h"

char	*get_sign(char *buff_char, int i, int signe)
{
  char	*result;

  result = NULL;
  if (signe == -1)
    {
      i = i - 1;
      buff_char[i] = MINUS;
    }
  result = my_strdup(&(buff_char[i]));
  free(buff_char);
  return (result);
}

char     *my_int_to_char(int nbr)
{
  char		*buff_char;
  int           i;
  int           n;
  int		signe;

  signe = 1;
  buff_char = xmalloc((BUFF_CHAR_SIZE + 1) * sizeof(*buff_char));
  n = my_strlen(BASE_INT);
  i = BUFF_CHAR_SIZE;
  if (nbr < 0)
    {
      signe = signe * (-1);
      nbr = nbr * (-1);
    }
  buff_char[i--] = '\0';
  while (nbr > 0)
    {
      buff_char[i] = (nbr % n) + '0';
      nbr = nbr / n;
      i = i - 1;
    }
  i = i + 1;
  return (get_sign(buff_char, i, signe));
}
