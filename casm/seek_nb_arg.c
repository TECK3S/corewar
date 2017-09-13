/*
** seek_nb_arg.c for seek_nb_arg in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Sat Dec 11 14:29:06 2010 remi bartel
** Last update Sun Dec 19 22:41:33 2010 remi bartel
*/

#include "asm.h"
#include "op.h"
#include "commons.h"
#include "xfunctions.h"

static unsigned char	*disp_inst_unknown(int line)
{
  my_fprintf(STDERR, "Error line %d : %s.\n", line, ERR_BADARG);
  return (NULL);
}

static unsigned char	*seek_spe(char *key, t_link *link, int line)
{
  int	i;
  int   len;

  i = 0;
  while (op_tab_spe[i].mnemonique)
    {
      len = my_strlen(op_tab_spe[i].mnemonique);
      if ((my_strncmp(key, op_tab_spe[i].mnemonique, len)) == 0 &&
          (key[len] == ' ' || key[len] == '\t'))
        {
          link->nb = op_tab[i].nbr_args;
          link->add = 1;
          link->extd = 1;
          link->mnemo = xmalloc((len + 1) * sizeof(*(link->mnemo)));
          link->mnemo = my_strncpy(link->mnemo, op_tab_spe[i].mnemonique, len);
          key += len;
          key = go_next_word(key);
          link->inst = (unsigned char*)my_strdup(key);
          return (op_tab_spe[i].type);
        }
      ++i;
    }
  return (disp_inst_unknown(line));
}

unsigned char	*seek_nb_arg(char *key, t_link *link, int line)
{
  int   i;
  int   len;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      len = my_strlen(op_tab[i].mnemonique);
      if ((my_strncmp(key, op_tab[i].mnemonique, len)) == 0 &&
          (key[len] == ' ' || key[len] == '\t'))
        {
          link->nb = op_tab[i].nbr_args;
          link->add = 1;
          link->mnemo = xmalloc((len + 1) * sizeof(*(link->mnemo)));
          link->mnemo = my_strncpy(link->mnemo, op_tab[i].mnemonique, len);
          key += len;
          key = go_next_word(key);
          link->inst = (unsigned char*)my_strdup(key);
          return (op_tab[i].type);
        }
      ++i;
    }
  if (link->spe & VAL_EXTD)
    return (seek_spe(key, link, line));
  return (disp_inst_unknown(line));
}
