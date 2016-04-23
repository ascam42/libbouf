/*
** bousti_alloc_get.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 19:13:50 2016 Luca Ungaro
** Last update Fri Apr 15 11:17:38 2016 Luca Ungaro
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

t_bousti_unique_alloc		*find_unique_with_address(void	*addr)
{
  t_bousti_unique_alloc	*ret;
  t_bousti_unique_alloc	*tmp;
  t_bousti_list		*loop;

  ret = NULL;
  loop = g_unique_alloc_list;
  while (loop && loop->data && !ret)
    {
      tmp = (t_bousti_unique_alloc *)(loop->data);
      if (tmp->addr == addr)
	ret = tmp;
      loop = loop->next;
    }
  return (ret);
}

t_bousti_unique_alloc		*find_unique_with_owner(void	*addr)
{
  t_bousti_unique_alloc	*ret;
  t_bousti_unique_alloc	*tmp;
  t_bousti_list		*loop;

  ret = NULL;
  loop = g_unique_alloc_list;
  while (loop && loop->data && !ret)
    {
      tmp = (t_bousti_unique_alloc *)(loop->data);
      if (tmp->owner == addr)
	ret = tmp;
      loop = loop->next;
    }
  return (ret);
}
