/*
** load_cor_file.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/dasm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sun Dec 19 00:06:51 2010 adrien barrau
** Last update Sun Dec 19 17:21:34 2010 adrien barrau
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "commons.h"
#include "dasm.h"
#include "xfunctions.h"

static char     *get_pathname(char *cor_name)
{
  char  *pathname;
  int   cor_len;

  cor_len = my_strlen(cor_name);
  if (my_strcmp(&(cor_name[cor_len - COR_EXT_LEN]), COR_EXTENSION) == 0)
    {
      pathname = xmalloc((cor_len - COR_EXT_LEN
			  + SRC_EXT_LEN + 1) * sizeof(*pathname));
      pathname = my_strncpy(pathname, cor_name, cor_len - COR_EXT_LEN);
    }
  else
    {
      pathname = xmalloc((cor_len + SRC_EXT_LEN + 1) * sizeof(*pathname));
      pathname = my_strncpy(pathname, cor_name, cor_len);
    }
  pathname = my_strcat(pathname, SRC_EXTENSION);
  return (pathname);
}

static int      get_header_cor(int fd, t_file *file)
{
  int   ok;

  ok = 1;
  ok =  get_magicnum(fd);
  if (ok > 0)
    ok = get_name(fd, file);
  if (ok > 0)
    ok = get_progsize(fd, file);
  if (ok > 0)
    ok = get_comment(fd, file);
  if (ok > 0)
    ok = get_code(fd, file);
  return (ok);
}

int     load_cor_file(char *cor_name, t_file *file)
{
  int   fd;
  int   ok;

  file->pathname = get_pathname(cor_name);
  if (access(cor_name, F_OK) == -1)
    ok = COR_DOESNT_EXIST_ERR_CODE;
  else if (access(cor_name, R_OK) == -1)
    ok = COR_WRONG_RIGHT_ERR_CODE;
  else if ((fd = open(cor_name, O_RDONLY)) == -1)
    ok = COR_OPEN_FAIL_ERR_CODE;
  else
    {
      ok = get_header_cor(fd, file);
      my_printf(DASM_MESSAGE, cor_name);
      close(fd);
    }
  return (ok);
}
