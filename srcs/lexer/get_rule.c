/*
** get_rule.c for boustifaille in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed May 18 17:05:10 2016 Luca Ungaro
** Last update Thu May 19 15:41:32 2016 Luca Ungaro
*/

#include "bouf.h"

t_bousti_syntax		_get_rule_by_name(const t_bousti_syntax	*syntax,
					  const char		*name)
{
  t_bousti_syntax	ret;
  int			i;

  i = 0;
  ret.name = NULL;
  if (syntax)
    while (!ret.name && syntax[i].name)
      {
	if (!bousti_strcmp(syntax[i].name, name))
	  ret = syntax[i];
	i += 1;
      }
  return (ret);
}
