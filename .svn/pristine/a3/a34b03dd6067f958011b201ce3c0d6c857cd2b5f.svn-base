/*
** get_headerinfos.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 04:01:29 2010 adrien barrau
** Last update Sun Dec 19 03:35:52 2010 adrien barrau
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "commons.h"
#include "xfunctions.h"
#include "op.h"
#include "vm.h"

int	get_magicnum(int fd)
{
  int	ok;
  unsigned char	buf[MAGIC_SIZE];
  int	i;
  int	mem_read;

  i = 0;
  ok = 1;
  if ((mem_read = read(fd, buf, MAGIC_SIZE)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != MAGIC_SIZE)
    ok = BAD_BYTE_CODE_ERR_CODE;
  mem_read = 0;
  while (ok > 0 && i < MAGIC_SIZE)
    {
      mem_read <<= NB_BITS_IN_OCT;
      mem_read +=  buf[i++];
    }
  if (ok > 0 && mem_read != COREWAR_EXEC_MAGIC)
    ok = BAD_COR_FILE_ERR_CODE;
  return (ok);
}

int		get_name(t_param_vm *param_vm, int fd, int idx)
{
  int		ok;
  unsigned char	buf[PROG_NAME_LENGTH + 4];
  int		mem_read;

  ok = 1;
  if ((mem_read = read(fd, buf, PROG_NAME_LENGTH + 4)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != PROG_NAME_LENGTH + 4)
    ok = BAD_BYTE_CODE_ERR_CODE;
  if (ok > 0)
    {
      param_vm->champs[idx].name =
	xmalloc((PROG_NAME_LENGTH + 5) * sizeof(*buf));
      param_vm->champs[idx].name =
	my_strncpy(param_vm->champs[idx].name, (char *)buf, PROG_NAME_LENGTH + 4);
    }
  return (ok);
}

int	get_comment(t_param_vm *param_vm, int fd, int idx)
{
  int	ok;
  unsigned char	buf[COMMENT_LENGTH + 4];
  int	mem_read;

  mem_read = 0;
  ok = 1;
  if ((mem_read = read(fd, buf, COMMENT_LENGTH + 4)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != COMMENT_LENGTH + 4)
    ok = BAD_BYTE_CODE_ERR_CODE;
  if (ok > 0)
    {
      param_vm->champs[idx].comment =
	xmalloc((COMMENT_LENGTH + 5) * sizeof(*buf));
      param_vm->champs[idx].comment =
	my_strncpy(param_vm->champs[idx].comment, (char *)buf, COMMENT_LENGTH + 4);
    }
  return (ok);
}

int	get_progsize(t_param_vm *param_vm, int fd, int idx)
{
  int	ok;
  unsigned char	buf[MAGIC_SIZE];
  int	i;
  int	mem_read;

  i = 0;
  ok = 1;
  if ((mem_read = read(fd, buf, MAGIC_SIZE)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && mem_read != MAGIC_SIZE)
    ok = BAD_BYTE_CODE_ERR_CODE;
  while (ok > 0 && i < MAGIC_SIZE)
    {
      ok <<= NB_BITS_IN_OCT;
      ok += buf[i++];
    }
  if (ok > 0)
    param_vm->champs[idx].prog_size = ok;
  return (ok);
}
