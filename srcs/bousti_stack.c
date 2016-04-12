/*
** bousti_stack.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 18:43:31 2016 Luca Ungaro
** Last update Tue Apr 12 21:07:06 2016 Luca Ungaro
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
# include "bouf.h"

void	bousti_stack_append(t_bousti_list	**stack,
			    void		*elem)
{
  bousti_put_in_end_dblist(stack, elem);
}

/*
** DOC :: upon node ot node->data
*/
void		bousti_stack_pop(t_bousti_list	**stack,
				 void		*elem)
{
  t_bousti_list	*elem_node;
  t_bousti_list	*prev;
  t_bousti_list	*next;

  if (stack && *stack && elem)
    {
      elem_node = bousti_stack_get_by_data(*stack, elem);
      if (!elem_node)
	elem_node = (t_bousti_list *)(elem);
      if (elem_node)
	{
	  prev = elem_node->prev;
	  next = elem_node->next;
	  if (prev)
	    prev->next = next;
	  if (next)
	    next->prev = prev;
	  if (elem != elem_node)
	    {
	      bousti_free(elem_node);
	      elem_node = NULL;
	    }
	}
      bousti_free(elem);
      if (!(*stack) && next)
	*stack = next;
    }
}

t_bousti_list	*bousti_stack_get_by_data(t_bousti_list	*list,
					  void		*data)
{
  t_bousti_list	*ret;

  ret = NULL;
  while (list && list->data && !ret)
    {
      if (list->data == data)
	ret = list;
      list = list->next;
    }
  return (ret);
}
