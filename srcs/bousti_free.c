/*
** bousti_free.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 19:13:50 2016 Luca Ungaro
** Last update Tue Apr 12 21:07:28 2016 Luca Ungaro
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

void			bousti_free(void	*ptr)
{
  t_bousti_alloc	*elem;

  elem = find_with_address(ptr);
  if (elem)
    {
      bousti_stack_pop(&g_alloc_list, elem);
      if (elem->addr)
	free(elem->addr);
    }
  free(elem);
}

void			bousti_free_everything(void)
{
  t_bousti_list		*loop;
  t_bousti_alloc	*elem;

  loop = g_alloc_list;
  while (loop && loop->data)
    {
      elem = (t_bousti_alloc *)(loop->data);
      if (elem)
	{
	  bousti_stack_pop(&g_alloc_list, elem);
	  if (elem->addr)
	    std_free(elem->addr);
	  std_free(elem);
	}
      loop = loop->next;
    }
  std_free(g_alloc_list);
}
