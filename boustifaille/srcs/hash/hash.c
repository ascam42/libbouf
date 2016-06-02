/*
** hash.c for  in /home/aitoua_s/prog/psu/PSU_2015_42sh/boustifaille
** 
** Made by samy ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Tue May 24 13:52:32 2016 samy ait-ouakli
** Last update Thu Jun  2 18:20:11 2016 samy ait-ouakli
*/

#include "bouf.h"

static t_hash		**st_hash;

int		init_hash()
{
  int		i;

  if ((st_hash = malloc(sizeof(t_hash*) * SIZE)) == NULL)
    return (EXIT_FAILURE);
  i  = -1;
  while (++i < SIZE)
    st_hash[i] = NULL;
  return (EXIT_SUCCESS);
}

int		put_in_hash(char *name, void *data)
{
  int		pos;
  t_list	*tmp;
  t_elem	*elem;

  pos = my_hash_fct(name);
  tmp = st_hash[pos];
  if ((elem = new_elem(name, data)) == NULL)
    return (0);
  while (tmp != NULL)
    if (bousti_strcmp(((t_elem*)tmp->data)->name, name) == 0)
      {
	((t_elem*)tmp->data)->data = data;
	return (2);
      }
    else
      tmp = tmp->next;
  bousti_put_in_end_list(&st_hash[pos], elem);
  return (1);
}

int		remove_elem(char *name)
{
  int		i;
  t_list	*tmp;

  i = my_hash_fct(name);
  tmp = st_hash[i];
  if (bousti_strcmp(((t_elem*)tmp->data)->name, name) == 0)
    {
      tmp = tmp->next;
      return (1);
    }
  while (tmp->next != NULL)
    if (bousti_strcmp(((t_elem*)tmp->next->data)->name, name) == 0)
      {
	tmp = tmp->next->next;
	return (1);
      }
    else
      tmp = tmp->next;
  if (bousti_strcmp(((t_elem*)tmp->next->data)->name, name) == 0)
    {
      free(tmp->next);
      tmp->next = NULL;
      return (1);
    }
  return (0);
}

void		*get_elem(char *name)
{
  int		i;
  t_list	*tmp;

  i = my_hash_fct(name);
  tmp = st_hash[i];
  while (tmp!= NULL)
    {
      if (bousti_strcmp(((t_elem*)tmp->data)->name, name) != 0)
	tmp = tmp->next;
      else
	return (((t_elem*)tmp->data)->data);
    }
  return (NULL);
}
