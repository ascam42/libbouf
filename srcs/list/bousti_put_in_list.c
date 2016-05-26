/*
** bousti_put_in_list.c for bousti_put_in_list in /home/ungaro_l/rendu/Piscine_C_J11
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Mon Oct 12 08:57:39 2015 Luca Ungaro
** Last update Thu Apr 28 20:14:54 2016 Luca Ungaro
*/

#include "bouf.h"

int		bousti_put_in_list(t_list **list, void *data)
{
  t_list	*new;

  new = bousti_malloc(sizeof(*new));
  if (new ==  NULL)
    return (1);
  new->data = data;
  new->next = *list;
  *list = new;
  return (0);
}

int		bousti_put_in_end_list(t_list **list, void *data)
{
  t_list	*tmp;
  t_list	*new;

  tmp = *list;
  new = bousti_malloc(sizeof(*new));
  if (new == NULL)
    return (1);
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
    }
  new->data = data;
  new->next = NULL;
  if (*list != NULL)
    tmp->next = new;
  else
    *list = new;
  return (0);
}

int		bousti_put_in_dblist(t_list **list, void *data)
{
  t_list	*new;

  new = bousti_malloc(sizeof(*new));
  if (new ==  NULL)
    return (1);
  new->data = data;
  new->next = *list;
  new->prev = NULL;
  if (*list)
    *list->prev = new;
  *list = new;
  return (0);
}

int		bousti_put_in_end_dblist(t_list **list, void *data)
{
  t_list	*tmp;
  t_list	*new;

  tmp = *list;
  new = bousti_malloc(sizeof(*new));
  if (new == NULL)
    return (1);
  if (tmp != NULL)
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
    }
  new->data = data;
  new->next = NULL;
  new->prev = tmp;
  if (*list != NULL)
      tmp->next = new;
  else
    *list = new;
  return (0);
}
