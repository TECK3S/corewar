/*
** check_valid_champs.c for corewar in /home/barrau_a//c/corewar/corewar_2013s/trunk/vm
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Sat Dec 18 04:00:49 2010 adrien barrau

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "commons.h"
#include "xfunctions.h"
#include "op.h"
#include "vm.h"

int	check_header_champ(t_param_vm *param_vm,
			   int fd,
			   unsigned char *big_male,
			   int i)
{
  int	ok;

  ok = 1;
  ok =  get_magicnum(fd);
  if (ok > 0)
    ok = get_name(param_vm, fd, i);
  if (ok > 0)
    ok = get_progsize(param_vm, fd, i);
  if (ok > 0)
    ok = get_comment(param_vm, fd, i);
  if (ok > 0)
    ok = check_too_close_address(param_vm, i);
  if (ok > 0)
    ok = load_champ(big_male, &(param_vm->champs[i]), fd);
  if (ok > 0)
    param_vm->champs[i].inlive = 1;
  close(fd);
  return (ok);
}

int	load_champ(unsigned char *big_male,
		   t_champion *champ,
		   int fd)
{
  int	ok;
  unsigned char	*buf;
  int	i;
  int	j;
  int	mem_read;

  j = 0;
  ok = 1;
  buf = xmalloc((champ->prog_size + 1) * sizeof(*buf));
  if ((mem_read = read(fd, buf, champ->prog_size + 1)) == -1)
    ok = BAD_READ_ERR_CODE;
  if (ok > 0 && (mem_read != champ->prog_size))
    ok = BAD_BYTE_CODE_ERR_CODE;
  else
    {
      i = champ->load_address;
      while (j < champ->prog_size)
	{
	  big_male[TO_ABS(i % MEM_SIZE)] = buf[j++];
	  i++;
	}
      init_registers(champ);
    }
  free(buf);
  return (ok);
}

int	check_valid_champs(t_param_vm *param_vm, unsigned char *big_male)
{
  int	i;
  int	ok;
  int	fd;

  ok = 1;
  i = 0;
  fd = 0;
  while (i < MAX_CHAMPS && ok > 0)
    {
      if (param_vm->champs[i].path != 0)
	{
	  if (access(param_vm->champs[i].path, F_OK) == -1)
	    ok = CHAMP_DOESNT_EXIST_ERR_CODE;
	  else if (access(param_vm->champs[i].path, R_OK) == -1)
	    ok = CHAMP_WRONG_RIGHT_ERR_CODE;
	  else if ((fd = open(param_vm->champs[i].path, O_RDONLY)) == -1)
	    ok = CHAMP_OPEN_FAIL_ERR_CODE;
	  else
	    ok = check_header_champ(param_vm, fd, big_male, i);
	}
      i = i + 1;
    }
  return (ok);
}
