/*
** bousti_regex.c for boustifaille in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Fri May 20 11:41:56 2016 Luca Ungaro
** Last update Fri May 20 17:22:13 2016 Luca Ungaro
*/

#include "bouf.h"
#include "boustifaille/private_bouf.h"

t_bousti_errlog	g_bousti_errlog = NULL;

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
  int	i;
  int	valid_size;
  t_tkn	*new_token;
  char	*tkn_value;

  i = 0;
  valid_size = 0;
  while (!valid_size && termin->components + i &&
	 termin->components[i].check)
    {
      valid_size = termin->components[i].check(exp);
      i += 1;
    }
  if (valid_size && (new_token = bousti_malloc(sizeof(t_bousti_token))))
    {
      new_token->associated_rulename = calling.exp;
      tkn_value = malloc(valid_size + 1);
      if (tkn_value)
	{
	  tkn_value = bousti_strncpy(tkn_value, exp, valid_size + 1);
	  new_token->value = (const char *)tkn_value;
	}
      bousti_stack_append(stack, new_token);
    }
  return (valid_size);
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
  int	new;

  ret = 0;
  if (calling.type == ZERO_OR_MORE || calling.type == ONE_OR_MORE)
    while ((new = _check_terminal_and_go_forward(terminal, calling,
						 exp, stack)))
      ret += new;
  else if (terminal && exp && stack)
    ret = _check_terminal_and_go_forward(terminal, calling, exp, stack);
  if (!ret && calling.type != ZERO_OR_MORE && calling.type != ZERO_OR_ONE)
    {
      /*bousti_dprintf(STDERR, "zouf calling :: '%s'\n", calling.exp);*/
      bousti_free_list(*stack);
      *stack = NULL;
    }
  bousti_dprintf(STDERR, "Validated %i bytes of terminal %s ('%s')\n",
		 ret, terminal->name, exp);
  return (ret);
}
