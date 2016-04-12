/*
** bousti_put_in_list.c for bousti_put_in_list in /home/ungaro_l/rendu/Piscine_C_J11
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Mon Oct 12 08:57:39 2015 Luca Ungaro
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

int		bousti_put_in_list(t_list **list, void *data)
{
  t_list	*new;

  new = std_malloc(sizeof(*new));
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
  new = std_malloc(sizeof(*new));
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

  new = std_malloc(sizeof(*new));
  if (new ==  NULL)
    return (1);
  new->data = data;
  new->next = *list;
  new->prev = NULL;
  *list = new;
  return (0);
}

int		bousti_put_in_end_dblist(t_list **list, void *data)
{
  t_list	*tmp;
  t_list	*new;

  tmp = *list;
  new = std_malloc(sizeof(*new));
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
