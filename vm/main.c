/*
** main.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Sun Dec 19 17:52:17 2010 damien benloukil
** Last update Sun Dec 19 19:02:27 2010 adrien barrau
*/

#include "op.h"
#include "vm.h"
#include "commons.h"

char *gl_err_msg[]=
  {
    EMPTY_STRING,
    HOW_TO_MSG,
    TOO_MANY_CHAMPS_ERR_MSG,
    OPT_BAD_OPT_ERR_MSG,
    OPT_DUMP_NUM_ERR_MSG,
    OPT_DUMP_ERR_MSG,
    OPT_A_EXIST_ERR_MSG,
    OPT_A_BAD_ERR_MSG,
    OPT_A_TOO_CLOSE_ERR_MSG,
    OPT_N_EXIST_ERR_MSG,
    OPT_N_BAD_ERR_MSG,
    OPT_TOO_FEW_ARG_MSG,
    OPT_CTMO_NUM_ERR_MSG,
    OPT_CTMO_ERR_MSG,
    OPT_COMMENT_ERR_MSG,
    OPT_GRAPH_ERR_MSG,
    OPT_V_EXIST_ERR_MSG,
    CHAMP_DOESNT_EXIST_ERR_MSG,
    CHAMP_WRONG_RIGHT_ERR_MSG,
    CHAMP_OPEN_FAIL_ERR_MSG,
    BAD_READ_ERR_MSG,
    BAD_BYTE_CODE_ERR_MSG,
    BAD_CORE_FILE_ERR_MSG,
    SDL_ERR_INIT_MSG,
    0
  };

t_opt gl_tab_opt[]=
  {
    {DUMP_NAME, &check_dump_val},
    {N_NAME, &check_champ_val},
    {A_NAME, &check_champ_val},
    {CTMO_NAME, &check_ctmo_val},
    {COMMENT_NAME, &check_comment_val},
    {GRAPH_NAME, &check_graph_val},
    {VERBOSE_NAME, &check_verbose_val},
    {0, 0}
  };

void	(*gl_instructions[])(t_champion *,
			     t_param_vm *,
			     unsigned char **,
			     t_lives *)=
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

void	init_param_vm(t_param_vm *param_vm)
{
  int	i;

  i = 0;
  while (i < MAX_CHAMPS)
    {
      (param_vm->champs)[i].path = 0;
      (param_vm->champs)[i].name = 0;
      (param_vm->champs)[i].comment = 0;
      (param_vm->champs)[i].number = 0;
      (param_vm->champs)[i].load_address = -1;
      (param_vm->champs)[i].prog_size = 0;
      (param_vm->champs)[i].inlive = 0;
      (param_vm->champs)[i].pc = 0;
      (param_vm->champs)[i].carry = 0;
      (param_vm->champs)[i].instruction.code = 0;
      (param_vm->champs)[i].instruction.nb_cycle_to_wait = -1;
      (param_vm->champs)[i].address_instruction = 0;
      (param_vm->champs)[i].children = 0;
      (param_vm->champs)[i].papounet = 0;
      (param_vm->champs)[i].nb_child = 0;
      (param_vm->champs)[i].next = 0;
      i++;
    }
}

void	init_args(int *ac,
		  char **av,
		  t_args_par *args_par,
		  t_param_vm *param_vm)
{
  args_par->ac = *ac;
  args_par->av = av;
  args_par->param_vm = param_vm;
  param_vm->dump = 0;
  param_vm->have_comment = 0;
  param_vm->ctmo = -1;
  param_vm->opt_graph = 0;
  param_vm->is_verbose = 0;
}

static	void	close_SDL(t_param_vm *param_vm)
{
  SDL_FreeSurface(param_vm->SDL.start);
  SDL_Quit();
}

int		main(int ac, char **av)
{
  t_param_vm	param_vm;
  t_args_par	args_par;
  int		ok;

  init_param_vm(&param_vm);
  init_args(&ac, av, &args_par, &param_vm);
  ok = 1;
  if ((ok = parse_option(&args_par)) > 0)
    {
      if (param_vm.opt_graph)
	ok = init_SDL(&param_vm);
      if (ok > 0)
	ok = launch_virtual_machine(&param_vm);
    }
  if (ok < 0)
    my_fprintf(STDERR, gl_err_msg[(ok * -1)]);
  if (param_vm.opt_graph)
    close_SDL(&param_vm);
  return (0);
}
