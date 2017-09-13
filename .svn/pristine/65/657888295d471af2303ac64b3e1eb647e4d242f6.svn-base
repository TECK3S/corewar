/*
** header.c for header in /home/bartel_r//Workspace/KoreWar/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Mon Dec  6 13:31:58 2010 remi bartel
** Last update Fri Dec 10 23:43:17 2010 eugene-valentin ngontang-tchiadjie
*/

#include "asm.h"
#include "commons.h"

t_spe	tab_spe[] =
  {
    {VAL_NAME, ".name"},
    {VAL_COMM, ".comment"},
    {VAL_EXTD, ".extend"},
    {0, 0}
  };

static	void	header_err(int line)
{
  my_fprintf(STDERR, "Error line %d : %s.\n", line, ERR_HDUNKN);
}

static	void header_misp(int line, char *str)
{
  my_fprintf(STDERR, "Error line %d : %s %s.\n", line, str, ERR_HDMISP);
}

int	seek_header(char *val, t_link *link, int line)
{
  int	i;

  i = 0;
  while (tab_spe[i].val)
    {
      if (i > 0 && ((tab_spe[i - 1].val & link->spe) == 0))
	break;
      if ((my_strncmp(val, tab_spe[i].lib, my_strlen(tab_spe[i].lib))) == 0)
	{
	  link->spe += tab_spe[i].val;
	  if (tab_spe[i].val == VAL_NAME)
	    return (check_name(val + my_strlen(tab_spe[i].lib), link));
	  else if (tab_spe[i].val == VAL_COMM)
	    return (check_comment(val + my_strlen(tab_spe[i].lib), link));
	  return (1);
	}
      ++i;
    }
  if (tab_spe[i].val)
    header_misp(line, tab_spe[i].lib);
  else
    header_err(line);
  return (0);
}
