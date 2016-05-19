/*
** deref_rule.c for bouf in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Thu May 19 15:09:26 2016 Luca Ungaro
** Last update Thu May 19 16:32:19 2016 Luca Ungaro
*/

#include "bouf.h"

const char		_deref_component(const t_bousti_syntax	*syntax,
					 const t_bousti_rule	*component
					 const char		*expr)
{
  bool			ret;
  const char		*component_name;
  t_bousti_syntax	rule;

  ret = false;
  component_name = _get_next_component_name(components);
  rule = get_rule_by_name(component_name);
  ret = _deref_component(syntax, rule);
  return (ret);
}
