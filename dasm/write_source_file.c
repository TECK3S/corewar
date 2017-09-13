/*
** write_source_file.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 02:22:33 2010 adrien barrau
** Last update Sun Dec 19 23:12:41 2010 damien benloukil
*/

#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"op.h"
#include        "commons.h"
#include        "dasm.h"

void    write_header(t_file *file)
{
  my_printf("\t%s\n\t%s\n", file->filename, file->comment);
  my_fprintf(file->fd, "%s\t\t\"%s\"\n%s\t\"%s\"\n%s\n\n%s%c",
	     NAME_CMD_STRING,
	     file->filename,
	     COMMENT_CMD_STRING,
	     file->comment,
	     DOT_EXTEND,
	     MAIN_LABEL,
	     LABEL_CHAR);
}

void    write_binary(t_file *file)
{
  int i;

  i = 0;
  while (i < file->prog_size)
    {
      if ((file->output_file)[i] >= MIN_INSTRUCTION
	  && (file->output_file)[i] <= MAX_INSTRUCTION)
	gl_ins[(int)(file->output_file)[i]](file, &i);
      else
	gl_ins[UNKNOWN_INSTRUCTION_CODE](file, &i);
    }
}

void	free_file(t_file *file)
{
  free(file->pathname);
  free(file->filename);
  free(file->comment);
  free(file->output_file);
}

int     write_source_file(t_file *file)
{
  int   ok;

  ok = 1;
  if ((file->fd = open(file->pathname,
		       O_RDWR | O_CREAT | O_TRUNC,
		       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    ok = SRC_OPEN_FAIL_ERR_CODE;
  else
    {
      write_header(file);
      write_binary(file);
      close(file->fd);
      free_file(file);
    }
  return (ok);
}
