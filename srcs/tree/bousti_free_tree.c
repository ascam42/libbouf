/*
** bousti_free_tree.c for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue May  3 17:05:05 2016 Luca Ungaro
** Last update Tue May  3 17:23:29 2016 Luca Ungaro
*/

#include "bouf.h"

static void	_free_node(t_bousti_tree	*node)
{
  if (node->data)
    bousti_free(node->data);
  bousti_free(node);
}

void	bousti_free_tree(t_bousti_tree	*tree,
			 t_bousti_ok	free_head)
{
  bousti_free_tree_fct(tree, &_free_node, free_head);
}

void	bousti_free_tree_fct(t_bousti_tree	*tree,
			     t_bousti_free_node	free_node,
			     t_bousti_ok	free_head)
{
  if (tree)
    {
      if (tree->right)
	{
	  bousti_free_tree(tree->right, free_head);
	  tree->right = NULL;
	}
      if (tree->left)
	{
	  bousti_free_tree(tree->left, free_head);
	  tree->left = NULL;
	}
      if (free_head && tree->head)
	{
	  bousti_free_tree(tree->head, free_head);
	  tree->head = NULL;
	}
      free_node(tree);
    }
}
