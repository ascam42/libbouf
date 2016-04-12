/*
** my_stralloc.c for lib in /home/ungaro_l/rendu/UNIX_system/PSU_2015_my_ls/lib/my
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Nov 24 11:00:20 2015 Luca Ungaro
** Last update Tue Apr 12 18:22:24 2016 Luca Ungaro
*/

#include "bouf.h"

static void	bousti_stralloc_extra(char	**str_addr,
				      va_list	elem,
				      int	str_nb)
{
  int	i;
  char	*ret;
  char	*tmp;

  i = 0;
  ret = *str_addr;
  ret[0] = '\0';
  while (i++ < str_nb)
    {
      tmp = va_arg(elem, char *);
      if (tmp)
	ret = bousti_strcat(ret, tmp);
    }
}

char		*bousti_stralloc(int	str_nb,
				 ...)
{
  int		i;
  int		len;
  va_list	elem;
  char		*tmp;
  char		*ret;

  i = 0;
  len = 0;
  va_start(elem, str_nb);
  while (i++ < str_nb)
    {
      tmp = va_arg(elem, char *);
      len += bousti_strlen(tmp);
    }
  va_end(elem);
  ret = bousti_malloc(len + 1);
  if (ret != NULL)
    {
      va_start(elem, str_nb);
      bousti_stralloc_extra(&ret, elem, str_nb);
      va_end(elem);
      ret[len] = '\0';
    }
  return (ret);
}

static void	bousti_stralloc_extra_not_repeat(char		**str_addr,
						 va_list	elem,
						 int		str_nb)
{
  int	i;
  int	j;
  int	k;
  char	*ret;
  char	*tmp;

  i = 0;
  ret = *str_addr;
  ret[0] = '\0';
  while (i++ < str_nb)
    {
      tmp = va_arg(elem, char *);
      j = bousti_strlen(ret);
      k = 0;
      while (ret[j] == tmp[k])
	k += 1;
      ret = bousti_strcat(ret, tmp + k);
    }
}

char		*bousti_stralloc_not_repeat(int	str_nb,
					    ...)
{
  int		i;
  int		len;
  va_list	elem;
  char		*tmp;
  char		*ret;

  i = 0;
  len = 0;
  va_start(elem, str_nb);
  while (i++ < str_nb)
    {
      tmp = va_arg(elem, char *);
      len += bousti_strlen(tmp);
    }
  va_end(elem);
  ret = bousti_malloc(len + 1);
  if (ret != NULL)
    {
      va_start(elem, str_nb);
      bousti_stralloc_extra_not_repeat(&ret, elem, str_nb);
      va_end(elem);
      ret[len] = '\0';
    }
  return (ret);
}
