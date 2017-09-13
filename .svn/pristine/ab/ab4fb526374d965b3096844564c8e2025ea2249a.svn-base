/*
** compile.c for compile in /home/bartel_r//svn/corewar_2013s/trunk/casm
** 
** Made by remi bartel
** Login   <bartel_r@epitech.net>
** 
** Started on  Thu Dec  9 21:11:59 2010 remi bartel
** Last update Sun Dec 19 23:17:44 2010 eugene-valentin ngontang-tchiadjie
** Last update Sun Dec 19 22:35:23 2010 remi bartel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"
#include "commons.h"
#include "xfunctions.h"

static	int	seek_extend(char *file)
{
  while (*file)
    {
      if (*file == '.' && file[1] == 's' && file[2] == '\0')
	return (1);
      ++file;
    }
  return (0);
}

static	int	check_extend(char *file)
{
  int	res;

  if ((res = seek_extend(file)) == 0)
    my_fprintf(STDERR, "Error: %s\n", BADEXTEND);
  return (res);
}

static	int	check_status(char *str)
{
  if ((check_extend(str)) == 0)
    return (-1);
  return (1);
}

static char	*do_cor(char *cor_file, t_file *file)
{
  cor_file = xmalloc((my_strlen(file->filename) + 3)
		     * (sizeof(*file->filename)));
  cor_file = my_strncpy(cor_file, file->filename,
			my_strlen(file->filename) - 1);
  cor_file = my_strcat(cor_file, BIN_EXTENSION);
  return (cor_file);
}

void	compile(t_file *file)
{
  int	status;
  int	fd;
  int	to_update;
  char	*cor_file;

  to_update = 0;
  if ((status = check_status(file->filename)) < 0)
    return ;
  if ((fd = xopen(file->filename, O_RDONLY, S_IRWXU)) < 0)
    return ;
  cor_file = do_cor(cor_file, file);
   if ((status = check_log(file->filename, cor_file)) == 0)
     {
       free(cor_file);
       return ;
     }
   if (status == 1)
     to_update = 1;
   free(cor_file);
   if (whole_parsing(fd, file) == 1)
     do_cmp(file, to_update);
}
