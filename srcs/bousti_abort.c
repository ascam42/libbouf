/*
** bousti_abort.c for boustifaille in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Lemin
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Thu Apr 14 11:41:42 2016 Luca Ungaro
** Last update Fri Apr 15 17:23:06 2016 Luca Ungaro
*/

#include "bouf.h"

void	bousti_abort(void)
{
#ifdef BOUSTI_ALLOCATOR_ABORT
  bousti_garbage_collect();
  bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
  exit(BOUSTI_ALLOC_ERROR);
#endif
}
