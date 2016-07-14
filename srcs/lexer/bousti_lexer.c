/*
** lexer.c for boustifaille in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed May 18 15:48:56 2016 Luca Ungaro
** Last update Sat Jun  4 22:25:07 2016 nicolas tsolissos
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"

static void	_raise_format_error(const char	*exp)
{
  char		*err_msg;

  err_msg = NULL;
  if (exp && g_bousti_errlog)
    {
      err_msg = bousti_stralloc(2, BOUSTI_SYNTAX_ERR, exp);
      if (err_msg)
	{
	  g_bousti_errlog(err_msg);
	  bousti_free(err_msg);
	}
    }
}

static const char	*_skip_separators(const char	*exp)
{
  while (exp && *exp && *exp == ' ')
    exp += 1;
  return (exp);
}

t_bousti_token_stack	*_bousti_lexer(const t_bousti_syntax	*syntax,
				       const char		**expr,
				       t_bousti_token_stack	*ret,
				       const char		*base_rule_name)
{
   int			i;
  t_bousti_syntax	base_rule;
  t_bousti_syntax	rule;
  t_bousti_rule		component;

  i = -1;
  base_rule = _get_rule_by_name(syntax, base_rule_name);
  while (expr && *expr && *(*expr = _skip_separators(*expr))
	 && base_rule.components[++i].exp)
    {
      component = base_rule.components[i];
      rule = _get_rule_by_name(syntax, component.exp);
      if (rule.terminal)
	*expr += _check_maybe_optionnal(&rule, (const t_bousti_rule)
					{base_rule_name,
					    component.type,
					    component.check},
					*expr, &ret);
      else
	ret = _bousti_lexer(syntax, expr, ret, component.exp);
    }
  return (ret);
}

t_bousti_token_stack	*bousti_lexer(const t_bousti_syntax	*syntax,
				      const char		*expr,
				      const char		*base_rule_name)
{
  t_bousti_token_stack	*ret;

  ret = NULL;
  ret = _bousti_lexer(syntax, &expr, ret, base_rule_name);
  if (*expr)
    _raise_format_error(expr);
  return (ret);
}
