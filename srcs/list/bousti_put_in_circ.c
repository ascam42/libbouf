/*
** bousti_put_in_circ.c for lib in /home/ungaro_l/rendu/UNIX_system/PSU_2015_bousti_select/lib/my
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed Dec  2 10:21:18 2015 Luca Ungaro
** Last update Tue Apr 12 20:38:09 2016 Luca Ungaro
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
#include "bouf.h"

t_list		*bousti_create_root(void)
{
  t_list	*root;

  root = std_malloc(sizeof(t_list *));
  if (root)
    {
      root->data = NULL;
      root->next = NULL;
      root->prev = NULL;
    }
  return (root);
}

int		bousti_put_in_end_dbcirc(t_list **list, void *data)
{
  int		ret;
  t_list	*new_elem;
  t_list	*root;

  ret = 1;
  new_elem = std_malloc(sizeof(t_list *));
  if (new_elem)
    {
      new_elem->data = data;
      root = bousti_get_root(*list);
      new_elem->next = root;
      if (root->prev)
	{
	  new_elem->prev = root->prev;
	  new_elem->prev->next = new_elem;
	}
      else
	new_elem->prev = root;
      if (*list == root)
	*list = new_elem;
      root->prev = new_elem;
      root->next = *list;
      ret = 0;
    }
  return (ret);
}

int		bousti_put_in_dbcirc(t_list **list, void *data)
{
  int		ret;
  t_list	*new_elem;
  t_list	*root;

  ret = 1;
  new_elem = std_malloc(sizeof(t_list *));
  if (new_elem)
    {
      new_elem->data = data;
      root = bousti_get_root(*list);
      new_elem->next = *list;
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
  t_list	*new_elem;
  t_list	*root;

  ret = 1;
  new_elem = std_malloc(sizeof(t_list *));
  if (new_elem)
    {
      new_elem->data = data;
      root = bousti_get_root(*list);
      new_elem->next = root;
      if (*list == root)
	*list = new_elem;
      root->next = *list;
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
  new_elem = std_malloc(sizeof(t_list *));
  if (new_elem)
    {
      new_elem->data = data;
      root = bousti_get_root(*list);
      new_elem->next = *list;
      root->next = new_elem;
      ret = 0;
    }
  return (ret);
}
