/*
** do_code.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 19 21:08:24 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 21:17:37 2010 eugene-valentin ngontang-tchiadjie
*/

#include	"asm.h"

unsigned char	*do_code(unsigned char *str, char *s, int *i)
{
  int	cpt;

  cpt = 0;
  while (s[cpt] != '\0')
    {
      str = do_fill(str, *i, s[cpt] + '0');
      *i = *i + 1;
      cpt = cpt + 1;
    }
  return (str);
}
