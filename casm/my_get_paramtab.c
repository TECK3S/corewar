/*
** my_get_paramtab.c for my_asm in /home/ngonta_e//my_home/rendu/c/corewar/corewar_2013s/trunk/casm
** 
** Made by eugene-valentin ngontang-tchiadjie
** Login   <ngonta_e@epitech.net>
** 
** Started on  Sun Dec 19 17:33:46 2010 eugene-valentin ngontang-tchiadjie
   Last update Sun Dec 19 23:05:51 2010 eugene-valentin ngontang-tchiadjie
** Started on  Sat Dec 11 05:07:24 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:42:47 2010 remi bartel
*/

#include	<stdlib.h>
#include	"xfunctions.h"
#include	"op.h"
#include	"commons.h"
#include	"asm.h"

static	int	is_space(unsigned char c)
{
  if (c == ' ' || c == '\t')
    return (1);
  else
    return (0);
}

static	int	param_len(unsigned char *str)
{
  int	nb;

  nb = 0;
  while (*str != SEPARATOR_CHAR && *str && *str != COMMENT_CHAR)
    {
      if (is_space(*str) == 0)
	++nb;
      ++str;
    }
  return (nb);
}

static	char	**fill_param_tab(unsigned char *str, char **tab, int nb)
{
  int	j;
  int	k;

  k = 0;
  while (*str && *str != COMMENT_CHAR && k < nb)
    {
      if (*str != SEPARATOR_CHAR)
	{
	  tab[k] = xmalloc((param_len(str) + 1) * sizeof(**tab));
	    j = 0;
	  while (*str && *str != SEPARATOR_CHAR && *str != COMMENT_CHAR)
	    {
	      if (is_space(*str) == 0)
		tab[k][j++] = *str;
	      str++;
	    }
	  tab[k][j] = '\0';
	  k++;
	  str--;
	}
      str++;
    }
  tab[k] = NULL;
  return (tab);
}

char	**my_get_paramtab(unsigned char *str, int nb)
{
  char  **t;

  t = xmalloc((nb + 1) * sizeof(*t));
  t = fill_param_tab(str, t, nb);
  return (t);
}
