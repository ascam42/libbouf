/*
** bousti_private_stack.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Thu Apr 28 13:43:01 2016 Luca Ungaro
** Last update Thu Apr 28 19:52:01 2016 Luca Ungaro
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"

void		bousti_private_stack_push(t_b_pv_stack	**stack,
					  void		*data)
{
  t_b_pv_stack	*new;

  new = std_malloc(sizeof(*new));
  if (new ==  NULL)
    return (1);
  new->data = data;
  new->next = *stack;
  new->prev = NULL;
  *stack = new;
  return (0);
}

void		bousti_private_stack_append(t_b_pv_stack	**stack,
					    void		*data)
{
  t_b_pv_stack	*tmp;
  t_b_pv_stack	*new;

  tmp = *stack;
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
  if (*stack != NULL)
      tmp->next = new;
  else
    *stack = new;
  return (0);
}

void		bousti_private_stack_pop(t_b_pv_stack	**stack,
					 void		*elem)
{
  t_b_pv_stack	*elem_node;
  t_b_pv_stack	*prev;
  t_b_pv_stack	*next;

  if (stack && *stack && elem)
    {
      elem_node = bousti_stack_get_by_data(*stack, elem);
      if (!elem_node)
	elem_node = (t_b_pv_stack *)(elem);
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
	std_free(elem_node);
    }
}

void		bousti_free_private_stack(t_b_pv_stack	*stack)
{
  t_stack	*tmp;

  while (stack && stack->data)
    {
      tmp = stack;
      stack = stack->next;
      if (tmp->data)
	std_free(tmp->data);
      std_free(tmp);
    }
  std_free(stack);
}
