/*
** bousti_unique_alloc.c for boustifaille in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Lemin
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Thu Apr 14 12:01:30 2016 Luca Ungaro
** Last update Thu Apr 28 19:52:51 2016 Luca Ungaro
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"

t_b_pv_stack	*g_unique_alloc_list = NULL;

void			*bousti_unique_malloc(void	*owner,
					      size_t	size)
{
  void			*ptr;
  t_bousti_unique_alloc	*new;

  ptr = std_malloc(size);
  new = std_malloc(sizeof(t_bousti_unique_alloc));
  if (ptr && new)
    {
      new->owner = owner;
      new->addr = ptr;
      new->size = size;
      bousti_private_stack_append(&g_unique_alloc_list, new);
    }
  else
    bousti_abort();
  return (ptr);
}

void			*bousti_unique_realloc(void	*owner,
					       void	*ptr,
					       size_t	size)
{
  bool			new;
  t_bousti_unique_alloc	*update;

  new = true;
  update = find_unique_with_address(ptr);
  if (!update)
    update = std_malloc(sizeof(t_bousti_unique_alloc));
  else
    new = false;
  if (update && update->owner == owner)
    {
      ptr = std_realloc(ptr, size);
      if (ptr)
	{
	  update->addr = ptr;
	  update->size = size;
	  if (new)
	    bousti_private_stack_append(&g_unique_alloc_list, update);
	}
      else
	bousti_abort();
    }
  else
    ptr = NULL;
  return (ptr);
}

void			*bousti_unique_calloc(void	*owner,
					      size_t	nmemb,
					      size_t	size)
{
  void			*ptr;
  t_bousti_unique_alloc	*new;

  ptr = std_calloc(nmemb, size);
  new = std_malloc(sizeof(t_bousti_unique_alloc));
  if (ptr && new)
    {
      new->owner = owner;
      new->addr = ptr;
      new->size = nmemb * size;
      bousti_private_stack_append(&g_unique_alloc_list, new);
    }
  else
    bousti_abort();
  return (ptr);
}
