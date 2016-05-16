/*
** bousti_abort.c for boustifaille in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Lemin
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Thu Apr 14 11:41:42 2016 Luca Ungaro
** Last update Mon May 16 10:31:43 2016 Luca Ungaro
*/

#include "bouf.h"

void	bousti_abort(void)
{
#if defined (BOUSTI_ALLOCATOR_ABORT)
  bousti_garbage_collect();
  bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
  exit(BOUSTI_ALLOC_ERROR);
#elif defined (BOUSTI_ALLOCATOR_WARN)
  bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
#endif
}
