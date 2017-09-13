##
## Makefile for corewar in /home/benich_a//afs/rendu/c/proj/corewar/corewar_2013s/trunk
## 
## Made by mickael benichou
## Login   <benich_a@epitech.net>
## 
## Started on  Sun Dec 19 10:26:43 2010 mickael benichou
## Last update Sun Dec 19 23:29:47 2010 mickael benichou
##

NAME_TAR	=	KoreWar.tar.gz
NAME_VM		=	corewar
NAME_CASM	=	asm
NAME_DASM	=	dcor

DIR_VM		=	vm
DIR_CASM	=	casm
DIR_DASM	=	dasm
DIR_COMMONS	=	commons
DIR_XFUNCTIONS	=	xfunctions
DIR_MY_CHAMP	=	my_champ
DIR_SVN		=	.svn

SRCS_VM		= 	$(DIR_VM)/main.c				\
			$(DIR_VM)/parse_option.c			\
			$(DIR_VM)/check_champ_val.c			\
			$(DIR_VM)/check_val.c				\
			$(DIR_VM)/get_load_address.c			\
			$(DIR_VM)/launch_virtual_machine.c		\
			$(DIR_VM)/tool_inttab.c				\
			$(DIR_VM)/check_valid_champs.c			\
			$(DIR_VM)/big_malloc.c				\
			$(DIR_VM)/dump_memory.c				\
			$(DIR_VM)/get_headerinfos.c			\
			$(DIR_VM)/virtual_machine_core.c		\
			$(DIR_VM)/check_live_champs.c			\
			$(DIR_VM)/check_oct_param.c			\
			$(DIR_VM)/get_octets.c				\
			$(DIR_VM)/get_octets_st.c			\
			$(DIR_VM)/init_SDL.c				\
			$(DIR_VM)/ins_live.c				\
			$(DIR_VM)/ins_ld.c				\
			$(DIR_VM)/ins_st.c				\
			$(DIR_VM)/ins_add.c				\
			$(DIR_VM)/ins_sub.c				\
			$(DIR_VM)/ins_and.c				\
			$(DIR_VM)/ins_or.c				\
			$(DIR_VM)/ins_xor.c				\
			$(DIR_VM)/ins_zjmp.c				\
			$(DIR_VM)/ins_ldi.c				\
			$(DIR_VM)/ins_sti.c				\
			$(DIR_VM)/ins_fork.c				\
			$(DIR_VM)/ins_lld.c				\
			$(DIR_VM)/ins_lldi.c				\
			$(DIR_VM)/ins_lfork.c				\
			$(DIR_VM)/ins_aff.c				\
			$(DIR_VM)/ins_gtmd.c				\
			$(DIR_VM)/ins_unky.c				\
			$(DIR_VM)/init_registers.c			\
			$(DIR_VM)/and_the_winner_is.c			\
			$(DIR_VM)/check_dump.c				\
			$(DIR_VM)/update_ctmo.c				\
			$(DIR_VM)/aff_graph.c				\
			$(DIR_VM)/update_graphic.c			\
			$(DIR_VM)/manage_event.c			\
			$(DIR_VM)/on_pause.c				\
			$(DIR_VM)/get_progs_number.c			\
			$(DIR_VM)/check_too_close_address.c		\
			$(DIR_VM)/addr_is_inside.c			\
			$(DIR_VM)/time_graph.c				\
			$(DIR_VM)/aff_helico.c


SRCS_CASM	=	$(DIR_CASM)/main.c				\
			$(DIR_CASM)/parsing.c				\
			$(DIR_CASM)/header.c				\
			$(DIR_CASM)/check_log.c				\
			$(DIR_CASM)/check_arg_nbr.c			\
			$(DIR_CASM)/disp_bad_header.c			\
			$(DIR_CASM)/is_num.c				\
			$(DIR_CASM)/is_alpha.c				\
			$(DIR_CASM)/is_valid.c				\
			$(DIR_CASM)/go_next_word.c			\
			$(DIR_CASM)/check_name.c			\
			$(DIR_CASM)/check_comment.c			\
			$(DIR_CASM)/free_struct.c			\
			$(DIR_CASM)/disp_wrong_type.c			\
			$(DIR_CASM)/fill_header.c			\
			$(DIR_CASM)/check_arg_type.c			\
			$(DIR_CASM)/disp_syntax_err.c			\
			$(DIR_CASM)/whole_parsing.c			\
			$(DIR_CASM)/my_get_paramtab.c			\
			$(DIR_CASM)/my_put_inlist.c			\
			$(DIR_CASM)/check_call.c			\
			$(DIR_CASM)/my_insert_inst.c			\
			$(DIR_CASM)/compile.c				\
			$(DIR_CASM)/seek_nb_arg.c			\
			$(DIR_CASM)/rev_inst.c				\
			$(DIR_CASM)/rev_label.c				\
			$(DIR_CASM)/get_length.c			\
			$(DIR_CASM)/do_cmp.c				\
			$(DIR_CASM)/add_reg.c				\
			$(DIR_CASM)/do_fill.c				\
			$(DIR_CASM)/my_getaddr.c			\
			$(DIR_CASM)/my_getchar_addr.c			\
			$(DIR_CASM)/do_power.c				\
			$(DIR_CASM)/put_param.c				\
			$(DIR_CASM)/my_putaddr.c			\
			$(DIR_CASM)/copy_addr.c				\
			$(DIR_CASM)/store_addr_call.c			\
			$(DIR_CASM)/store_label.c			\
			$(DIR_CASM)/free_label_stack.c			\
			$(DIR_CASM)/free_call_addr.c			\
			$(DIR_CASM)/add_ind.c				\
			$(DIR_CASM)/add_dir.c				\
			$(DIR_CASM)/check_inst.c			\
			$(DIR_CASM)/do_zjmp.c				\
			$(DIR_CASM)/do_rev.c				\
			$(DIR_CASM)/do_live.c				\
			$(DIR_CASM)/do_sti.c				\
			$(DIR_CASM)/do_ldi.c				\
			$(DIR_CASM)/do_lldi.c				\
			$(DIR_CASM)/do_fork.c				\
			$(DIR_CASM)/do_lfork.c				\
			$(DIR_CASM)/complete_header.c			\
			$(DIR_CASM)/end_copy.c				\
			$(DIR_CASM)/is_label.c				\
			$(DIR_CASM)/create_bin.c			\
			$(DIR_CASM)/my_fill_with_zero.c			\
			$(DIR_CASM)/fill_nbr.c				\
			$(DIR_CASM)/my_compar.c				\
			$(DIR_CASM)/trunc_nbr.c				\
			$(DIR_CASM)/trunc_neg.c				\
			$(DIR_CASM)/trunc_pos.c				\
			$(DIR_CASM)/get_index.c				\
			$(DIR_CASM)/my_sub.c				\
			$(DIR_CASM)/full_check.c			\
			$(DIR_CASM)/my_int_to_char.c			\
			$(DIR_CASM)/get_header.c			\
			$(DIR_CASM)/get_op.c				\
			$(DIR_CASM)/do_code.c				\
			$(DIR_CASM)/is_utterly_num.c			\
			$(DIR_CASM)/process_extd.c			

SRCS_DASM	=	$(DIR_DASM)/main.c				\
			$(DIR_DASM)/dasm.c				\
			$(DIR_DASM)/load_cor_file.c			\
			$(DIR_DASM)/write_source_file.c			\
			$(DIR_DASM)/get_header_infos.c			\
			$(DIR_DASM)/write_param.c			\
			$(DIR_DASM)/ins_live.c				\
			$(DIR_DASM)/ins_ld.c				\
			$(DIR_DASM)/ins_st.c				\
			$(DIR_DASM)/ins_add.c				\
			$(DIR_DASM)/ins_sub.c				\
			$(DIR_DASM)/ins_and.c				\
			$(DIR_DASM)/ins_or.c				\
			$(DIR_DASM)/ins_xor.c				\
			$(DIR_DASM)/ins_zjmp.c				\
			$(DIR_DASM)/ins_ldi.c				\
			$(DIR_DASM)/ins_sti.c				\
			$(DIR_DASM)/ins_fork.c				\
			$(DIR_DASM)/ins_lld.c				\
			$(DIR_DASM)/ins_lldi.c				\
			$(DIR_DASM)/ins_lfork.c				\
			$(DIR_DASM)/ins_aff.c				\
			$(DIR_DASM)/ins_gtmd.c				\
			$(DIR_DASM)/ins_unky.c				\
			$(DIR_DASM)/check_oct_param.c			\

SRCS_XFUNCT	=	$(DIR_XFUNCTIONS)/xmalloc.c			\
			$(DIR_XFUNCTIONS)/xwrite.c			\
			$(DIR_XFUNCTIONS)/xcwrite.c			\
			$(DIR_XFUNCTIONS)/xstat.c			\
			$(DIR_XFUNCTIONS)/xopen.c			

SRCS_COMN	=	$(DIR_COMMONS)/my_gnl.c				\
			$(DIR_COMMONS)/op.c				\
			$(DIR_COMMONS)/my_strncpy.c			\
			$(DIR_COMMONS)/my_memset.c			\
			$(DIR_COMMONS)/header_cpy.c			\
			$(DIR_COMMONS)/my_strdup.c			\
			$(DIR_COMMONS)/my_printf.c			\
			$(DIR_COMMONS)/parse_arg.c			\
			$(DIR_COMMONS)/check_flag.c			\
			$(DIR_COMMONS)/check_width.c			\
			$(DIR_COMMONS)/check_precision.c		\
			$(DIR_COMMONS)/check_len_mod.c			\
			$(DIR_COMMONS)/check_con_spe.c			\
			$(DIR_COMMONS)/my_put_fct.c			\
			$(DIR_COMMONS)/my_put_fct_long.c		\
			$(DIR_COMMONS)/my_put_int.c			\
			$(DIR_COMMONS)/my_put_uint.c			\
			$(DIR_COMMONS)/my_put_char_pf.c			\
			$(DIR_COMMONS)/my_put_string.c			\
			$(DIR_COMMONS)/my_put_uoctal.c			\
			$(DIR_COMMONS)/my_put_uhex.c			\
			$(DIR_COMMONS)/my_put_uhex_big.c		\
			$(DIR_COMMONS)/my_put_ptr.c			\
			$(DIR_COMMONS)/my_put_bin.c			\
			$(DIR_COMMONS)/my_put_pourcent.c		\
			$(DIR_COMMONS)/my_put_string_big.c		\
			$(DIR_COMMONS)/fill_with_blank.c		\
			$(DIR_COMMONS)/my_getnbr.c			\
			$(DIR_COMMONS)/my_nbrlen_pf.c			\
			$(DIR_COMMONS)/my_unbrlen_pf.c			\
			$(DIR_COMMONS)/my_strlen_pf.c			\
			$(DIR_COMMONS)/my_tablen.c			\
			$(DIR_COMMONS)/my_strlen_big_pf.c		\
			$(DIR_COMMONS)/my_strncmp_pf.c			\
			$(DIR_COMMONS)/my_putstr_pf.c			\
			$(DIR_COMMONS)/my_putstr_big_pf.c		\
			$(DIR_COMMONS)/my_putnbr_pf.c			\
			$(DIR_COMMONS)/my_putunbr_pf.c			\
			$(DIR_COMMONS)/my_putnbr_base_pf.c		\
			$(DIR_COMMONS)/my_nbrlen_base_pf.c		\
			$(DIR_COMMONS)/str_isnum.c			\
			$(DIR_COMMONS)/my_strcmp.c			\
			$(DIR_COMMONS)/my_strncmp.c			\
			$(DIR_COMMONS)/my_free_wt.c			\
			$(DIR_COMMONS)/my_strcat.c			\
			$(DIR_COMMONS)/my_wtlen.c			\
			$(DIR_COMMONS)/my_power_rec.c			\
			$(DIR_COMMONS)/my_getnbr_base.c		

OBJS_VM		=	$(SRCS_VM:.c=.o)
OBJS_CASM	=	$(SRCS_CASM:.c=.o)
OBJS_DASM	=	$(SRCS_DASM:.c=.o)
OBJS_XFUNCT	=	$(SRCS_XFUNCT:.c=.o)
OBJS_COMN	=	$(SRCS_COMN:.c=.o)

OS		=	$(shell uname -s)

ifeq			($(OS),Linux)
CC		=	gcc
RM		=	rm -Rf
ECHO		=	echo
TAR		=	tar
CLIBFLAG	+=	-lSDL -lSDL_image -lSDL_ttf
endif

ifeq			($(OS),FreeBSD)
CC		=	gcc
RM		=	rm -Rf
ECHO		=	echo
TAR		=	tar
CLIBFLAG	+=	-lSDL -lSDL_image -lSDL_ttf
endif

ifeq			($(OS),NetBSD)
CC		=	gcc
RM		=	rm -Rf
ECHO		=	echo
TAR		=	tar
CLIBFLAG	+=	-lSDL -lSDL_image -lSDL_ttf
endif

ifeq			($(OS),SunOS)
CC		=	gcc
RM		=	rm -Rf
ECHO		=	echo
TAR		=	tar
CLIBFLAG	+=	-lSDL -lSDL_image -lSDL_ttf
endif

CINCLUDES	=	./includes
CFLAGS		+=	-Werror -Wall -Wextra -Wstrict-prototypes -pedantic -ansi -O3
CFLAGSBUG	=	-v -g3 -I$(CINCLUDES)

all		:	untar $(NAME_VM) $(NAME_CASM) $(NAME_DASM)

$(NAME_VM)	:	$(OBJS_VM) $(OBJS_XFUNCT) $(OBJS_COMN)
			$(CC) $(OBJS_VM) $(OBJS_XFUNCT) $(OBJS_COMN) -o $(NAME_VM) $(CLIBFLAG)

$(NAME_CASM)	:	$(OBJS_CASM) $(OBJS_XFUNCT) $(OBJS_COMN)
			$(CC) $(OBJS_CASM) $(OBJS_XFUNCT) $(OBJS_COMN) -o $(NAME_CASM)  $(CLIBFLAG)

$(NAME_DASM)	:	$(OBJS_DASM) $(OBJS_XFUNCT) $(OBJS_COMN)
			$(CC) $(OBJS_DASM) $(OBJS_XFUNCT) $(OBJS_COMN) -o $(NAME_DASM)  $(CLIBFLAG)


$(NAME_TAR)	:	fclean
			$(TAR) -czvf $(NAME_TAR) $(DIR_CASM) $(DIR_DASM) $(DIR_VM) $(DIR_COMMONS) $(DIR_XFUNCTIONS) $(DIR_SVN) $(DIR_MY_CHAMP) $(CINCLUDES)
			$(RM) $(DIR_CASM) $(DIR_DASM) $(DIR_VM) $(DIR_COMMONS) $(DIR_XFUNCTIONS) $(DIR_SVN) $(DIR_MY_CHAMP) $(CINCLUDES)

untar		:
			@if [[ -a $(NAME_TAR) ]];then		\
			$(TAR) -xzvf $(NAME_TAR);		\
			$(RM) $(NAME_TAR);			\
			fi

.c.o		:
			$(CC) -o $@ -c $< $(CFLAGS) -I$(CINCLUDES)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS) -I$(CINCLUDES)

clean		:
			@$(RM) $(OBJS_VM) $(OBJS_CASM) $(OBJS_DASM) $(OBJS_XFUNCT) $(OBJS_COMN)
			@$(RM) *~

fclean		:	clean
			@$(RM) $(NAME_VM) $(NAME_CASM) $(NAME_DASM)

re		:	fclean all

debug		:
			$(CC) $(SRCS_VM) $(SRCS_XFUNCT) $(SRCS_COMN) $(CFLAGSBUG) $(CLIBFLAG) -o $(NAME_VM)
			$(CC) $(SRCS_CASM) $(SRCS_XFUNCT) $(SRCS_COMN) $(CFLAGSBUG) $(CLIBFLAG) -o $(NAME_CASM)
			$(CC) $(SRCS_DASM) $(SRCS_XFUNCT) $(SRCS_COMN) $(CFLAGSBUG) $(CLIBFLAG) -o $(NAME_DASM)

.PHONY		:	all clean fclean re debug untar
