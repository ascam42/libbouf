/*
** bousti_free.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 19:13:50 2016 Luca Ungaro
** Last update Fri May 13 17:23:39 2016 Luca Ungaro
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"

static void	_free(t_bousti_alloc	*elem)
{
  if (elem)
    {
      if (elem->addr)
	std_free(elem->addr);
      bousti_private_stack_pop(&g_alloc_list, elem);
    }
  free(elem);
}

static void	_unique_free(t_bousti_unique_alloc	*elem)
{
  void		*ptr;

  ptr = elem->owner;
  while (elem)
    {
      if (elem->addr)
	std_free(elem->addr);
      bousti_private_stack_pop(&g_unique_alloc_list, elem);
      elem = find_unique_with_owner(ptr);
    }
  free(elem);
}

/*
**
** if it's a unique container, we find some uniques owned by it
** and whether it's a container or not, it shall be freed itself !
*/
void			bousti_free(void	*ptr)
{
  t_bousti_alloc	*elem;
  t_bousti_unique_alloc	*unique_elem;

  printf("tirelipinpon\n");
  unique_elem = find_unique_with_owner(ptr);
  if (unique_elem)
    _unique_free(unique_elem);
  elem = find_with_address(ptr);
  if (elem)
    _free(elem);
  else
    std_free(ptr);
  printf("zouf\n");
}
