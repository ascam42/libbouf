/*
** my_perr.c for  in /home/aitoua_s/prog/psu/PSU_2015_42sh/boustifaille
** 
** Made by samy ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Tue May 24 14:18:20 2016 samy ait-ouakli
** Last update Tue May 31 16:47:34 2016 samy ait-ouakli
*/

#include "bouf.h"

t_elem		*new_elem(char *name, void *data)
{
  t_elem	*res;

  if ((res = malloc(sizeof(t_elem))) == NULL)
    return (NULL);
  res->name = name;
  res->data = data;
  return (res);
}
