/*
** do_fill.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Mon Dec 13 20:29:35 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 13:09:45 2010 eugene-valentin ngontang-tchiadjie
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "commons.h"

static void	*xrealloc (void *base, size_t size)
{
void	*temp;

 if ((temp = realloc(base, size)) == NULL )
  {
    my_fprintf(STDERR, "realloc error");
    free(base);
    exit(EXIT_FAILURE);
  }
 else
   {
     base = temp;
     return (base);
   }
}

unsigned char	*do_fill(unsigned char *str, int i, unsigned char c)
{
  static int	count_size = 0;
  static int	mult = 2;

  if (i == 0)
    {
      count_size = 0;
      mult = 2;
    }
  count_size = count_size + 1;
  if (count_size >= BIN_SIZE)
    {
      str = xrealloc(str, ((BIN_SIZE * mult) * sizeof(*str)));
      count_size = 0;
      mult = mult + 1;
    }
  str[i] = c;
  return (str);
}
