/*
** fct_hashage.c for  in /home/aitoua_s/prog/psu/PSU_2015_42sh/boustifaille
** 
** Made by samy ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Wed May 25 15:13:22 2016 samy ait-ouakli
** Last update Thu Jun  2 15:07:50 2016 samy ait-ouakli
*/

#include "bouf.h"

int	my_hash_fct(char const *name)
{
  int	res;
  int	i;
  int	j;

  res = 0;
  j = 0;
  while (j < 3)
    {
      i = 0;
      while (name[i])
	{
	  res = res ^ name[i] << j;
	  i++;
	}
      res = res << j * 8;
      j++;
    }
  res = (res < 0 ? -res : res);
  return (res % SIZE);
}
