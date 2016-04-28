/*
** bousti_free_list.c for bistro in /home/ungaro_l/rendu/Piscine_C_bistromathique
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Fri Oct 30 18:39:10 2015 Luca Ungaro
** Last update Thu Apr 28 19:55:33 2016 Luca Ungaro
*/
#include "bouf.h"

void		bousti_free_list(t_list *list)
{
  t_list	*tmp;

  while (list && list->data)
    {
      tmp = list;
      list = list->next;
      if (tmp->data)
	bousti_free(tmp->data);
      bousti_free(tmp);
    }
  bousti_free(list);
}

void		bousti_free_list_fct(t_list *list,
				     void (*free_node)(t_list *node))
{
  t_list	*tmp;

  while (list && list->data)
    {
      tmp = list;
      list = list->next;
      free_node(tmp);
    }
  free_node(list);
}
