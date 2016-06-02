/*
** bousti_free_list.c for bistro in /home/ungaro_l/rendu/Piscine_C_bistromathique
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Fri Oct 30 18:39:10 2015 Luca Ungaro
** Last update Tue May  3 17:21:56 2016 Luca Ungaro
*/
#include "bouf.h"

static void	_free_node(t_list	*node)
{
  if (node->data)
    bousti_free(node->data);
  bousti_free(node);
}

void		bousti_free_list(t_list *list)
{
  bousti_free_list_fct(list, &_free_node);
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
}
