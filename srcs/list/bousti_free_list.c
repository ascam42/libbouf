/*
** bousti_free_list.c for bistro in /home/ungaro_l/rendu/Piscine_C_bistromathique
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Fri Oct 30 18:39:10 2015 Luca Ungaro
** Last update Tue Apr 12 20:46:07 2016 Luca Ungaro
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

void		bousti_free_list(t_list *list)
{
  t_list	*tmp;

  while (list && list->data)
    {
      tmp = list;
      list = list->next;
      if (tmp->data)
	std_free(tmp->data);
      std_free(tmp);
    }
  std_free(list);
}

void		bousti_free_list_fct(t_list *list,
				     void (*free_node)(t_list *node))
{
  t_list	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free_node(tmp);
    }
  free_node(list);
}
