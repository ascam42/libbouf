/*
** tree.h for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue May  3 16:10:28 2016 Luca Ungaro
** Last update Tue May  3 17:20:10 2016 Luca Ungaro
*/

#ifndef TREE_H_
# define TREE_H_

# include <stdlib.h>

typedef struct	s_tree
{
  void		*data;
  struct s_tree	*head;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

typedef t_tree	t_bousti_tree;

typedef void	(*t_bousti_free_node)(t_bousti_tree	*node);

/*
** bousti_put_in_tree.c
*/
t_bousti_tree	*bousti_new_elem(void			*data);
t_bousti_tree	*bousti_put_in_left(t_bousti_tree	*head,
				    void		*data);
t_bousti_tree	*bousti_put_in_right(t_bousti_tree	*head,
				     void		*data);
/*
** bousti_link_in_tree.c
*/
t_bousti_tree	*bouti_link_in_head(t_bousti_tree	*head,
				    t_bousti_tree	*new);
t_bousti_tree	*bouti_link_in_left(t_bousti_tree	*head,
				    t_bousti_tree	*new);
t_bousti_tree	*bouti_link_in_right(t_bousti_tree	*head,
				     t_bousti_tree	*new);

void		bousti_free_tree(t_bousti_tree		*tree,
				 t_bousti_ok		free_head);
void		bousti_free_tree_fct(t_bousti_tree	*tree,
				     t_bousti_free_node	free_node,
				     t_bousti_ok	free_head);

#endif /* !TREE_H_ */
