/*
** bousti_strdup.c for  in /home/aitoua_s/prog/psu/PSU_2015_42sh/boustifaille/srcs
** 
** Made by samy ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Sun Jun  5 22:29:12 2016 samy ait-ouakli
** Last update Sun Jun  5 22:29:14 2016 samy ait-ouakli
*/

#include "bouf.h"

char	*bousti_strdup(const char *s)
{
  int	i;
  char	*ret;

  ret = NULL;
  i = bousti_strlen(s);
  ret = bousti_malloc((i + 1) * sizeof(char));
  if (ret)
    ret = strcpy(ret, s);
  return (ret);
}
