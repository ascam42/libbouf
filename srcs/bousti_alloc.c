/*
** bousti_alloc.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 18:06:53 2016 Luca Ungaro
** Last update Tue Apr 12 21:27:18 2016 Luca Ungaro
*/

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | Boustifaille corp's library overload                                      |
** |                                                                           |
** | This file and all the other ones with it are under BeerWare license       |
** | (revision 42) :                                                           |
** |                                                                           |
** |   | <luca.ungaro@epitech.eu> wrote this file. As long as you retain this  |
** |   | notice you can do whatever you want with this stuff. If we meet some  |
** |   | day and you think this stuff is worth it, you can buy me a beer in    |
** |   | return.                                                               |
** |   |                                                                       |
** |   | Luca Ungaro, for Boustifaille Corp.                                   |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
# include "bouf.h"

t_bousti_list		*g_alloc_list = NULL;

t_sysmalloc	g_std_malloc = &malloc;
t_sysrealloc	g_std_realloc = &realloc;
t_syscalloc	g_std_calloc = &calloc;
t_sysfree	g_std_free = &free;

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
      bousti_stack_append(&g_alloc_list, new);
    }
#ifdef BOUSTI_ALLOCATOR_ABORT
  else
    {
      bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
      exit(BOUSTI_ALLOC_ERROR);
    }
#endif
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
	bousti_stack_append(&g_alloc_list, update);
    }
#ifdef BOUSTI_ALLOCATOR_ABORT
  else
    {
      bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
      exit(BOUSTI_ALLOC_ERROR);
    }
#endif
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
      bousti_stack_append(&g_alloc_list, new);
    }
#ifdef BOUSTI_ALLOCATOR_ABORT
  else
    {
      bousti_fdprintf(STDERR, "%s\n", BOUSTI_ALLOC_ERROR_MSG);
      exit(BOUSTI_ALLOC_ERROR);
    }
#endif
  return (ptr);
}
