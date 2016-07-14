/*
** bousti_regex.c for  in /home/aitoua_s/prog/psu/PSU_2015_42sh/boustifaille/srcs
** 
** Made by samy ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Sun Jun  5 22:25:19 2016 samy ait-ouakli
** Last update Sun Jun  5 22:28:45 2016 samy ait-ouakli
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"

t_bousti_errlog	g_bousti_errlog = NULL;

static int	_check_arg_and_go_forward(const t_bousti_syntax	*termin,
					  const t_bousti_rule	calling,
					  const char		*exp,
					  t_bousti_token_stack	**stack)
{
  int		valid_size;
  t_tkn		*new_token;
  char		*tkn_value;

  if (calling.check)
    valid_size = calling.check(exp);
  if ((new_token = bousti_malloc(sizeof(t_bousti_token))))
    {
      new_token->associated_rulename = calling.exp;
      tkn_value = malloc(valid_size + 1);
      if (tkn_value)
	{
	  tkn_value[0] = 0;
	  tkn_value = bousti_strncat(tkn_value, exp, valid_size);
	  new_token->value = (const char *)tkn_value;
	}
      bousti_stack_append(stack, new_token);
    }
  (void)termin;
  return (valid_size);
}

/*
** Checks all the possible terminal expressions in of a syntax rule.
** Uses the t_bousti_check_exp function pointer assiciated with each possible
** expression
**
** Retruns the number of characters that have been valid_sizeated as a part of
** this terminal rule
*/
static int	_check_terminal_and_go_forward(const t_bousti_syntax	*termin,
					       const t_bousti_rule	calling,
					       const char		*exp,
					       t_bousti_token_stack	**stack)
{
  int	i[2];
  t_tkn	*new_token;
  char	*tkn_value;

  i[0] = -1;
  i[1] = 0;
  while (!i[1] && termin->components + ++i[0] &&
	 termin->components[i[0]].check)
    i[1] = termin->components[i[0]].check(exp);
  if (i[1] && (new_token = bousti_malloc(sizeof(t_bousti_token))))
    {
      if (strcmp(termin->components[i[0]].exp, "WORD") == 0)
	new_token->associated_rulename = calling.exp;
      else
	new_token->associated_rulename = termin->components[i[0]].exp;
      tkn_value = malloc(i[1] + 1);
      if (tkn_value)
	{
	  tkn_value[0] = 0;
	  tkn_value = bousti_strncat(tkn_value, exp, i[1]);
	  new_token->value = (const char *)tkn_value;
	}
      bousti_stack_append(stack, new_token);
    }
  return (i[1]);
}

/*
** Checks a terminal's syntax while it can be required. If it is not present
** (and is not optionnal), raises an error.
**
** When raising an error, it logs out the cause using the g_bousti_errlog
** function, frees the current token stack and "nullifies" it.
**
** The "RULE" string associated to it is the very last before the terminal rule
** in grammar's descending order
*/
int	_check_maybe_optionnal(const t_bousti_syntax	*terminal,
			       const t_bousti_rule	calling,
			       const char		*exp,
			       t_bousti_token_stack	**stack)
{
  int	ret;

  ret = 0;
  if ((calling.type & ZERO_OR_MORE) == ZERO_OR_MORE
      || (calling.type & ONE_OR_MORE) == ONE_OR_MORE)
    {
      if (calling.check)
	ret = _check_arg_and_go_forward(terminal, calling, exp, stack);
      else
	ret = _check_terminal_and_go_forward(terminal, calling, exp, stack);
    }
  else if (terminal && exp && stack)
    ret = _check_terminal_and_go_forward(terminal, calling, exp, stack);
  return (ret);
}
