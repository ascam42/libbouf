/*
** alloc_guard_bouf.h for libbouf in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Lemin
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Sat Apr 23 14:14:53 2016 Luca Ungaro
** Last update Sat Apr 23 14:15:53 2016 Luca Ungaro
*/

#ifndef ALLOC_GUARD_BOUF_H_
# define ALLOC_GUARD_BOUF_H_

# ifdef BOUSTI_ALLOCATOR_OVERLOAD

#  undef malloc
#  undef realloc
#  undef calloc
#  undef free

# endif /* !BOUSTI_ALLOCATOR_OVERLOAD */

#endif /*!ALLOC_GUARD_BOUF_H_  */
