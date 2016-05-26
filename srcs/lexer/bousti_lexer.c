/*
** lexer.c for boustifaille in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed May 18 15:48:56 2016 Luca Ungaro
** Last update Fri May 20 18:05:31 2016 Luca Ungaro
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
**
**
**
**
**
**
**
** RETOUR EN CASCADE D'ERREUUUUUR... est-ce qu'il se fait bieing ??
*/
t_bousti_token_stack	*bousti_lexer(const t_bousti_syntax	*syntax,
				      const char		*expr,
				      const char		*base_rule_name)
{
  int			i;
  t_bousti_syntax	base_rule;
  t_bousti_syntax	rule;
  t_bousti_rule		component;
  t_bousti_token_stack	*ret;
  t_bousti_token_stack	*recurs;

  i = 0;
  ret = NULL;
  base_rule = _get_rule_by_name(syntax, base_rule_name);
  while (base_rule.components + i)
    {
      component = base_rule.components[i];
      rule = _get_rule_by_name(syntax, component.exp);
      if (rule.terminal)
	expr += _check_maybe_optionnal(&rule, component, expr, &ret);
      else
	{
	  recurs = bousti_lexer(syntax, expr, rule.name);
	  ret = bousti_concat_stack(ret, recurs);
	}
    }
  return (ret);
}
