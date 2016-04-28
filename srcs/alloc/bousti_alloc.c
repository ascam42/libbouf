/*
** bousti_alloc.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 18:06:53 2016 Luca Ungaro
** Last update Thu Apr 28 19:50:24 2016 Luca Ungaro
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"
#include "boustifaille/alloc_guard_bouf.h"

t_sysmalloc		g_std_malloc = &malloc;
t_sysrealloc		g_std_realloc = &realloc;
t_syscalloc		g_std_calloc = &calloc;
t_sysfree		g_std_free = &free;

t_bousti_private_stack	*g_alloc_list = NULL;

void			*bousti_malloc(size_t	size)
{
  void			*ptr;
  t_bousti_alloc	*new;

  ptr = std_malloc(size);
  new = std_malloc(sizeof(t_bousti_alloc));
  if (ptr && new)
    {
      new->addr = ptr;
      new->size = size;
      bousti_private_stack_append(&g_alloc_list, new);
    }
  else
    bousti_abort();
  return (ptr);
}

void			*bousti_realloc(void	*ptr,
					size_t	size)
{
  bool			new;
  t_bousti_alloc	*update;

  new = true;
  update = find_with_address(ptr);
  if (!update)
    update = std_malloc(sizeof(t_bousti_alloc));
  else
    new = false;
  ptr = std_realloc(ptr, size);
  if (ptr && update)
    {
      update->addr = ptr;
      update->size = size;
      if (new)
	bousti_private_stack_append(&g_alloc_list, update);
    }
  else
    bousti_abort();
  return (ptr);
}

void			*bousti_calloc(size_t	nmemb,
				       size_t	size)
{
  void			*ptr;
  t_bousti_alloc	*new;

  ptr = std_calloc(nmemb, size);
  new = std_malloc(sizeof(t_bousti_alloc));
  if (ptr && new)
    {
      new->addr = ptr;
      new->size = nmemb * size;
      bousti_private_stack_append(&g_alloc_list, new);
    }
  else
    bousti_abort();
  return (ptr);
}
