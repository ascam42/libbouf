/*
** bousti_put_in_tree.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue May  3 16:10:13 2016 Luca Ungaro
** Last update Tue May  3 16:53:47 2016 Luca Ungaro
*/

#include "bouf.h"

t_bousti_tree	*bousti_new_elem(void	*data)
{
  t_bousti_tree	*new;

  new = bousti_malloc(sizeof(t_bousti_tree));
  if (new)
    {
      new->data = data;
      new->head = NULL;
      new->right = NULL;
      new->left = NULL;
    }
  return (new);
}

t_bousti_tree	*bousti_put_in_left(t_bousti_tree	*head,
				    void		*data)
{
  t_bousti_tree	*new;

  new = bousti_malloc(sizeof(t_bousti_tree));
  if (new)
    {
      new->data = data;
      new->head = head;
      new->right = NULL;
      new->left = NULL;
      if (head)
	head->left = new;
    }
  return (new);
}

t_bousti_tree	*bousti_put_in_right(t_bousti_tree	*head,
				    void		*data)
{
  t_bousti_tree	*new;

  new = bousti_malloc(sizeof(t_bousti_tree));
  if (new)
    {
      new->data = data;
      new->head = head;
      new->right = NULL;
      new->left = NULL;
      if (head)
	head->right = new;
    }
  return (new);
}
