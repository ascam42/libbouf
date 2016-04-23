/*
** bousti_alloc_size.c for boustifaille in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Lemin
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Fri Apr 15 11:17:47 2016 Luca Ungaro
** Last update Fri Apr 15 11:22:46 2016 Luca Ungaro
*/

#include "bouf.h"

static size_t		_total_unique_allocated_size(void)
{
  size_t		ret;
  t_bousti_unique_alloc	*cur;
  t_bousti_list		*loop;

  ret = 0;
  loop = g_unique_alloc_list;
  while (loop && loop->data)
    {
      cur = (t_bousti_unique_alloc *)(loop->data);
      if (cur)
	ret += cur->size;
      loop = loop->next;
    }
  return (ret);
}

static size_t		_total_allocated_size(void)
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

size_t			bousti_get_total_allocated_size(void)
{
  size_t		ret;

  ret = _total_unique_allocated_size();
  ret += _total_allocated_size();
  return (ret);
}

size_t			bousti_get_allocated_size(void	*addr)
{
  size_t		ret;
  t_bousti_alloc	*elem;
  t_bousti_unique_alloc	*unique_elem;

  ret = 0;
  elem = find_with_address(addr);
  if (elem)
    ret = elem->size;
  else
    {
      unique_elem = find_unique_with_address(addr);
      if (unique_elem)
	ret = unique_elem->size;
    }
  return (ret);
}
