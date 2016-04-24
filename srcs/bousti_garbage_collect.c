/*
** bousti_garbage_collect.c for boustifaille in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Lemin
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Fri Apr 15 11:12:36 2016 Luca Ungaro
** Last update Sun Apr 24 18:26:26 2016 Luca Ungaro
*/

#include "bouf.h"

static void		_bousti_unique_garbage(void)
{
  t_bousti_list		*loop;
  t_bousti_unique_alloc	*elem;

  loop = g_unique_alloc_list;
  while (loop)
    {
      elem = (t_bousti_unique_alloc *)(loop->data);
      if (elem)
	{
	  if (elem->addr)
	    std_free(elem->addr);
	  bousti_stack_pop(&g_unique_alloc_list, elem);
	  std_free(elem);
	}
      loop = loop->next;
    }
  std_free(g_unique_alloc_list);
}

static void		_bousti_garbage(void)
{
  t_bousti_list		*loop;
  t_bousti_alloc	*elem;

  loop = g_alloc_list;
  while (loop)
    {
      elem = (t_bousti_alloc *)(loop->data);
      if (elem)
	{
	  if (elem->addr)
	    std_free(elem->addr);
	  bousti_stack_pop(&g_alloc_list, elem);
	  std_free(elem);
	  loop = g_alloc_list;
	}
      else
	loop = loop->next;
    }
  std_free(g_alloc_list);
}

void			bousti_garbage_collect(void)
{
  _bousti_unique_garbage();
  _bousti_garbage();
}
