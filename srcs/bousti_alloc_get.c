/*
** bousti_alloc_get.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 19:13:50 2016 Luca Ungaro
** Last update Tue Apr 12 21:03:26 2016 Luca Ungaro
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

t_bousti_alloc		*find_with_address(void	*addr)
{
  t_bousti_alloc	*ret;
  t_bousti_alloc	*tmp;
  t_bousti_list		*loop;

  ret = NULL;
  loop = g_alloc_list;
  while (loop && loop->data && !ret)
    {
      tmp = (t_bousti_alloc *)(loop->data);
      if (tmp->addr == addr)
	ret = tmp;
      loop = loop->next;
    }
  return (ret);
}

size_t			bousti_get_allocated_size(void	*addr)
{
  size_t		ret;
  t_bousti_alloc	*elem;

  ret = 0;
  elem = find_with_address(addr);
  if (elem)
    ret = elem->size;
  return (ret);
}

size_t			bousti_get_total_allocated_size(void)
{
  size_t		ret;
  t_bousti_alloc	*cur;
  t_bousti_list		*loop;

  ret = 0;
  loop = g_alloc_list;
  while (loop && loop->data)
    {
      cur = (t_bousti_alloc *)(loop->data);
      if (cur)
	ret += cur->size;
      loop = loop->next;
    }
  return (ret);
}
