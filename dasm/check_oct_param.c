/*
** check_oct_param.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 12:51:57 2010 adrien barrau
** Last update Sun Dec 19 12:51:58 2010 adrien barrau
*/

#include "commons.h"
#include "op.h"
#include "vm.h"
#include "xfunctions.h"

int	get_parameter(unsigned char *tab_oct, int idx)
{
  int	res;

  idx = idx - 1;
  if (tab_oct[idx * 2] == 0 && tab_oct[(idx * 2) + 1] == 1)
    res = T_REG;
  else if (tab_oct[idx * 2] == 1 && tab_oct[(idx * 2) + 1] == 0)
    res = DIR_SIZE;
  else if (tab_oct[idx * 2] == 1 && tab_oct[(idx * 2) + 1] == 1)
    res = IND_SIZE;
  else
    res = 0;
  return (res);
}

int	convert_c_to_bin(unsigned char c, unsigned char **c_bin, int idx)
{
  if (idx < 0)
    return (0);
  convert_c_to_bin(c / 2, c_bin, idx - 1);
  (*c_bin)[idx] = c % 2;
  return (0);
}

static void	remove_tab_oct(unsigned char **tab_oct)
{
  free(*tab_oct);
  *tab_oct = 0;
}

static void	check_params(unsigned char **tab_oct, int *i)
{
  while (*tab_oct && *i < MAX_ARGS_NUMBER)
    {
      if ((*tab_oct)[*i * 2] != 0 || (*tab_oct)[(*i * 2) + 1] != 0)
	remove_tab_oct(tab_oct);
      *i += 1;
    }
}

unsigned char	*check_oct_param(unsigned char code, unsigned char oct)
{
  unsigned char	*tab_oct;
  unsigned char	current_par;
  char		nb_args;
  int		i;

  tab_oct = xmalloc(NB_BITS_IN_OCT * sizeof(*tab_oct));
  convert_c_to_bin(oct, &tab_oct, NB_BITS_IN_OCT - 1);
  current_par = 0;
  nb_args = op_tab[code - 1].nbr_args;
  i = 0;
  while (tab_oct && i < nb_args)
    {
      if (tab_oct[i * 2] == 0 && tab_oct[(i * 2) + 1] == 1)
	current_par = T_REG;
      else if (tab_oct[i * 2] == 1 && tab_oct[(i * 2) + 1] == 0)
	current_par = T_DIR;
      else if (tab_oct[i * 2] == 1 && tab_oct[(i * 2) + 1] == 1)
	current_par = T_IND;
      else
	remove_tab_oct(&tab_oct);
      if (tab_oct && !(op_tab[code - 1].type[i++] & current_par))
	remove_tab_oct(&tab_oct);
    }
  check_params(&tab_oct, &i);
  return (tab_oct);
}
