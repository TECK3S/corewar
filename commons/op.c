/*
** op.c for coreware in /home/benlou_d//proj/coreware/corewar_2013s/trunk/vm
** 
** Made by damien benloukil
** Login   <benlou_d@epitech.net>
** 
** Started on  Fri Dec  3 17:36:39 2010 damien benloukil
** Last update Sun Dec 19 15:21:41 2010 remi bartel
*/

#include "op.h"

/*
** op_tab
*/

op_t    op_tab[]=
{
  {"live", 1, {T_DIR}, 1, 10, "alive"},
  {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
  {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
  {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
  {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
  {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
   6, 6, "et (and  r1,r2,r3   r1&r2 -> r3"},
  {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
   7, 6, "ou  (or   r1,r2,r3   r1|r2 -> r3"},
  {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
   8, 6, "ou (xor  r1,r2,r3   r1^r2 -> r3"},
  {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
  {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
   10, 25, "load index"},
  {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
   11, 25, "store index"},
  {"fork", 1, {T_DIR}, 12, 600, "fork"},
  {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
  {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
   14, 50, "long load index"},
  {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
  {"aff", 1, {T_REG}, 16, 2, "aff"},
  {"gtmd", 1, {T_REG}, 17, 1, "instruction gtmd"},
  {"unky", 0, {0}, 18, 1, "unknown instruction"},
  {0, 0, {0}, 0, 0, 0}
};

op_t    op_tab_spe[]=
{
  {"code", 1, {T_CODE}, 1, 1, "affiche les octets"},
  {0, 0, {0}, 0, 0, 0}

};
