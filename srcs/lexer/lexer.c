/*
** lexer.c for boustifaille in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed May 18 15:48:56 2016 Luca Ungaro
** Last update Thu May 19 16:36:50 2016 Luca Ungaro
*/

#include "bouf.h"

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
				      const char		*expr
				      const char		*base_rule_name)
{
  int			i;
  const char		terminal;
  const char		*component_name;
  t_bousti_syntax	base_rule;
  t_bousti_syntax	rule;
  t_bousti_token_stack	*ret;
  t_bousti_token_stack	*recurs;

  i = 0;
  ret = NULL;
  base_rule = _get_rule_by_name(syntax, base_rule);
  while (base_rule.components + i)
    {
      component_name = _get_next_component_name(base_rule.components[i]);
      rule = get_rule_by_name(component_name);
      if (rule.terminal)
	__check_regexp_validity_and_move_forward__();
      else
	{
	  recurs = bousti_lexer(syntax, expr, rule.name);
	  ret = bousti_concat_stack(ret, recurs);
	}
      i += __check__terminal__validity__and__go__forward();
    }
  return (ret);
}
