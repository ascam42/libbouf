/*
** bousti_stack.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 18:43:31 2016 Luca Ungaro
** Last update Fri May 20 12:04:13 2016 Luca Ungaro
*/

# include "bouf.h"

void	bousti_stack_append(t_bousti_list	**stack,
			    void		*elem)
{
  bousti_put_in_end_dblist(stack, elem);
}

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
	  next = elem_node->next;
	  prev = elem_node->prev;
	  if (prev)
	    prev->next = next;
	  if (next)
	    next->prev = prev;
	}
      if (!(*stack) || (*stack) == elem_node)
	*stack = next;
      if (elem != elem_node)
	bousti_free(elem_node);
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

t_bousti_list	*bousti_concat_stack(t_bousti_list	*stack,
				     t_bousti_list	*append)
{
  while (append && append->data)
    {
      bousti_stack_append(&stack, append->data);
      append = append->next;
    }
  return (stack);
}
