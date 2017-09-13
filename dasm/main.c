/*
** main.c for corewar in /home/benich_a//corewar_2013s/trunk/dasm
** 
** Made by mickael benichou
** Login   <benich_a@epitech.net>
** 
** Started on  Sat Dec 18 01:57:38 2010 mickael benichou
** Last update Sun Dec 19 20:27:55 2010 mickael benichou
*/

#include	"commons.h"
#include	"dasm.h"

char *gl_err_msg[]=
  {
    ERROR_USAGE_ERR_MSG,
    COR_DOESNT_EXIST_ERR_MSG,
    COR_WRONG_RIGHT_ERR_MSG,
    COR_OPEN_FAIL_ERR_MSG,
    BAD_READ_ERR_MSG,
    BAD_BYTE_CODE_ERR_MSG,
    BAD_COR_FILE_ERR_MSG,
    SRC_OPEN_FAIL_ERR_MSG,
    0
  };

void	(*gl_ins[])(t_file *file, int *i)=
{
  0,
  &ins_live,
  &ins_ld,
  &ins_st,
  &ins_add,
  &ins_sub,
  &ins_and,
  &ins_or,
  &ins_xor,
  &ins_zjmp,
  &ins_ldi,
  &ins_sti,
  &ins_fork,
  &ins_lld,
  &ins_lldi,
  &ins_lfork,
  &ins_aff,
  &ins_gtmd,
  &ins_unky,
  0
};

int		main(int argc, char **argv)
{
  int		i;

  i = 1;
  if (argc < 2)
    my_fprintf(STDERR, gl_err_msg[ERROR_USAGE_ERR_CODE]);
  else
    while (i < argc)
      {
	dasm(argv[i]);
	i++;
      }
  return (0);
}
