/*
** bousti_put_in_circ.c for lib in /home/ungaro_l/rendu/UNIX_system/PSU_2015_bousti_select/lib/my
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed Dec  2 10:21:18 2015 Luca Ungaro
** Last update Sun Apr 24 23:23:13 2016 Luca Ungaro
*/

#include "bouf.h"

t_list		*bousti_create_root(void)
{
  t_list	*root;

  root = std_malloc(sizeof(t_list));
  if (root)
    {
      root->data = NULL;
      root->prev = NULL;
      root->next = NULL;
    }
  return (root);
}

int		bousti_put_in_end_dbcirc(t_list **list, void *data)
{
  int		ret;
  t_list	*tmp;
  t_list	*prev;

  ret = bousti_put_in_end_circ(list, data);
  tmp = bousti_get_root(*list);
  prev = NULL;
  while (tmp && (tmp = tmp->next) && tmp->data)
    {
      tmp->prev = prev;
      prev = tmp;
    }
  return (ret);
}

int		bousti_put_in_dbcirc(t_list **list, void *data)
{
  int		ret;
  t_list	*new_elem;
  t_list	*root;

  ret = 1;
  new_elem = std_malloc(sizeof(t_list));
  if (new_elem)
    {
      new_elem->data = data;
      root = bousti_get_root(*list);
      new_elem->next = *list;
      new_elem->prev = root;
      (*list)->prev = new_elem;
      *list = new_elem;
      root->next = *list;
      ret = 0;
    }
  return (ret);
}

int		bousti_put_in_end_circ(t_list **list, void *data)
{
  int		ret;
  t_list	*tmp;
  t_list	*new_elem;
  t_list	*root;

  ret = 1;
  new_elem = std_malloc(sizeof(t_list));
  tmp = *list;
  while (tmp && tmp->next && tmp->next->data)
    tmp = tmp->next;
  root = bousti_get_root(*list);
  if (new_elem)
    {
      new_elem->data = data;
      new_elem->next = root;
      if (*list == root)
	{
	  *list = new_elem;
	  root->next = *list;
	}
      else if (tmp)
	tmp->next = new_elem;
      ret = 0;
    }
  return (ret);
}

int		bousti_put_in_circ(t_list **list, void *data)
{
  int		ret;
  t_list	*new_elem;
  t_list	*root;

  ret = 1;
  new_elem = std_malloc(sizeof(t_list));
  if (new_elem)
    {
      new_elem->data = data;
      root = bousti_get_root(*list);
      new_elem->next = *list;
      root->next = new_elem;
      *list = new_elem;
      ret = 0;
    }
  return (ret);
}
