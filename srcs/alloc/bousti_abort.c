/*
** bousti_abort.c for boustifaille in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Lemin
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Thu Apr 14 11:41:42 2016 Luca Ungaro
** Last update Fri May 20 16:21:42 2016 Luca Ungaro
*/

#include "bouf.h"

bool	g_bousti_allocator_abort = false;
bool	g_bousti_allocator_warn = false;

void	bousti_abort(void)
{
  if (g_bousti_allocator_abort)
    {
      bousti_garbage_collect();
      bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
      exit(BOUSTI_ALLOC_ERROR);
    }
  else if (g_bousti_allocator_warn)
    {
      bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
    }
}
