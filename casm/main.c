/*
** main.c for main in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Thu Dec  9 21:12:51 2010 remi bartel
** Last update Sat Dec 18 14:17:09 2010 mickael benichou
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "commons.h"
#include "xfunctions.h"

t_inst_code	inst_code_tab[]=
{
  {REG_CHAR, &add_reg},
  {DIRECT_CHAR, &add_dir},
  {0, 0}
};

t_ireg	ireg_tab[]=
{
  {"zjmp", &do_zjmp},
  {"live", &do_live},
  {"fork", &do_fork},
  {"lfork", &do_lfork},
  {"sti", &do_sti},
  {"ldi", &do_ldi},
  {"lldi", &do_lldi},
  {0, 0}
};

static	void	init_file(t_file *file, char *name)
{
  file->filename = my_strdup(name);
  file->header = xmalloc(sizeof(*(file->header)));
  file->header->magic = COREWAR_EXEC_MAGIC;
  file->header->prog_name[0] = '\0';
  file->header->prog_size = 0;
  file->header->comment[0] = '\0';
  file->label_list = NULL;
}

int	main(int ac, char **av)
{
  int		i;
  t_file	*file;

  i = 1;
  if (ac < 2)
    my_fprintf(STDERR, "%s.\n", ERROR_USAGE);
  else
    while (av && av[i] != NULL)
      {
	file = xmalloc(sizeof(*file));
	my_printf("%s :\n", av[i]);
	init_file(file, av[i]);
	compile(file);
	free_file(file);
	i++;
      }
  return (0);
}
