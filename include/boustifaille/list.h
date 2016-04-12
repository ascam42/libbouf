/*
** list.h for boustifaille in /home/ungaro_l/rendu/UNIX_system/PSU_2015_my_ls
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Nov 24 13:19:36 2015 Luca Ungaro
** Last update Tue Apr 12 20:37:16 2016 Luca Ungaro
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
#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>

/*
** Following structure can define either :
**   - Linear linked list (simple or double)
**   - Circle linked list (simple or double)
**
** For simple lists, prev elem shall be ignored (even removed afterwords)
**
** For linear linked list, root node shall be initialized with NULL value
**  and 'list' functions family shall be used.
**
** For circular lists, root node SHALL BE ALLOCATED, with bousti_create_root().
**  It will be the VERY LAST ELEM of the list. 'Circle' functions family
**  shall be used.
**
** Obviously, each type of list needs to be freed. If data can be freed in
**  one row, use bousti_free_list(). Else, a pointer to a function that properly
**  frees a node and its data shall be passed as a parameter to
**  bousti_free_list_fct().
*/
typedef struct	s_list
{
  void		*data;
  struct s_list	*prev;
  struct s_list	*next;
}		t_list;

typedef t_list	t_bousti_list;

/*
** bousti_put_in_list.c
*/
int	bousti_put_in_end_dblist(t_list **list, void *data);
int	bousti_put_in_dblist(t_list **list, void *data);
int	bousti_put_in_end_list(t_list **list, void *data);
int	bousti_put_in_list(t_list **list, void *data);
/*
** bousti_put_in_circ.c
*/
t_list	*bousti_create_root(void);
int	bousti_put_in_end_dbcirc(t_list **list, void *data);
int	bousti_put_in_dbcirc(t_list **list, void *data);
int	bousti_put_in_end_circ(t_list **list, void *data);
int	bousti_put_in_circ(t_list **list, void *data);
/*
** bousti_show_list.c
*/
void	bousti_show_list(t_list *list);
char	**bousti_list_to_wordtab(t_list *list);
/*
** bousti_free_list.c
*/
void	bousti_free_list(t_list *list);
void	bousti_free_list_fct(t_list *list, void (*free_node)(t_list *node));
/*
** bousti_last_elem.c
*/
t_list	*bousti_last_elem(t_list *list);
t_list	*bousti_get_root(t_list *list);

#endif /* !LIST_H_ */
