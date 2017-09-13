/*
** my_sub.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sat Dec 18 05:30:29 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 17:14:53 2010 eugene-valentin ngontang-tchiadjie
*/

#include	<stdlib.h>
#include	"commons.h"
#include	"xfunctions.h"
#include	"asm.h"

static char	*end_sub(char *str_res, int i_res, char signe)
{
  int	i;
  char	*result;

  i = i_res;
  while (str_res[i] == BASE_INT[0] && str_res[i + 1] != '\0')
    i = i + 1;
  if (signe == MINUS)
    {
      i = i - 1;
      str_res[i] = MINUS;
    }
  result = my_strdup(&(str_res[i]));
  free(str_res);
  return (result);
}

static char	make_sub_lend(char **nbr1, char *nbr2, int i_op)
{
  int	tmp;
  char	c;
  int	i;

  tmp = get_index((*nbr1)[i_op]) + my_strlen(BASE_INT);
  c = BASE_INT[tmp - get_index(nbr2[i_op])];
  if ((*nbr1)[i_op - 1] == BASE_INT[0])
    {
      i = i_op - 1;
      while ((*nbr1)[i] == BASE_INT[0] && i > 0)
	(*nbr1)[i--] = BASE_INT[my_strlen(BASE_INT) - 1];
      (*nbr1)[i] = BASE_INT[get_index((*nbr1)[i]) - 1];
    }
  else
    (*nbr1)[i_op - 1] = BASE_INT[get_index((*nbr1)[i_op - 1]) - 1];
  return (c);
}

static void	begin_sub(char **nbr1, char **nbr2)
{
  if (my_strlen(*nbr1) > my_strlen(*nbr2))
    *nbr2 = fill_nbr(*nbr2,  my_strlen(*nbr1));
  else if (my_strlen(*nbr1) < my_strlen(*nbr2))
    *nbr1 = fill_nbr(*nbr1,  my_strlen(*nbr2));
}

static char 	*sub(char *nbr1, char *nbr2, char signe)
{
  int	i_op;
  int	i_res;
  char	*str_res;
  int	n;

  begin_sub(&nbr1, &nbr2);
  n = my_strlen(nbr1);
  str_res = xmalloc((n + 2) * sizeof(*str_res));
  i_op = n - 1;
  i_res = n + 1;
  str_res[i_res--] = '\0';
  while (i_op >= 0)
    {
      if (get_index(nbr1[i_op]) < get_index(nbr2[i_op]))
	str_res[i_res] = make_sub_lend(&nbr1, nbr2, i_op);
      else
	str_res[i_res] = BASE_INT[get_index(nbr1[i_op]) - get_index(nbr2[i_op])];
      i_op -= 1;
      i_res -= 1;
    }
  i_res = i_res + 1;
  str_res = end_sub(str_res, i_res, signe);
  free(nbr1);
  free(nbr2);
  return (str_res);
}

char	*my_sub(char *s1, char *s2, int n)
{
  char	*result;
  char	*tmp1;
  char	*tmp2;

  tmp1 = my_strdup(s1);
  tmp2 = my_strdup(s2);
  if (my_compar(tmp1, tmp2) == 0)
    result = my_strdup("0");
  else if (my_compar(tmp1, tmp2) > 0)
    result = sub(tmp1, tmp2, PLUS);
  else
    result = sub(tmp2, tmp1, MINUS);
  if (n == 1)
    free(s1);
  if (n == 2)
    free(s2);
  return (result);
}
