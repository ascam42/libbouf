/*
** lexer.c for boustifaille in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed May 18 15:48:56 2016 Luca Ungaro
** Last update Fri May 20 16:53:12 2016 Luca Ungaro
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"

/*
** TODO
**
** Recuperer la regle de base
** deref la regle
** recuperer chaque sous regle/elem
** deref l'elem
** ...
** checker la syntaxe des qu'on trouve un terminal
*/
t_bousti_token_stack	*bousti_lexer(const t_bousti_syntax	*syntax,
				      const char		*expr,
				      const char		*base_rule_name)
{
  int			i;
  const char		*prev_expr;
  const char		*component_name;
  t_bousti_syntax	base_rule;
  t_bousti_syntax	rule;
  t_bousti_token_stack	*ret;
  t_bousti_token_stack	*recurs;

  i = 0;
  ret = NULL;
  base_rule = _get_rule_by_name(syntax, base_rule_name);
  while (base_rule.components + i)
    {
      component_name = base_rule.components[i].exp;
      rule = _get_rule_by_name(syntax, component_name);
      if (rule.terminal)
	expr += _check_regex_and_go_forward(&rule, expr, &ret);
      else
	{
	  recurs = bousti_lexer(syntax, expr, rule.name);
	  ret = bousti_concat_stack(ret, recurs);
	}
    }
  return (ret);
}
