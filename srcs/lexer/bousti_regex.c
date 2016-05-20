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

/*
** Checks all the possible terminal expressions in of a syntax rule.
** Uses the t_bousti_check_exp function pointer assiciated with each possible
** expression
**
** Retruns the number of characters that have been valid_sizeated as a part of this
** terminal rule
*/
int	_check_regex_and_go_forward(const t_bousti_syntax	*terminal,
				    const char			*exp,
				    t_bousti_token_stack	**stack)
{
  int	i;
  int	valid_size;
  t_tkn	*new_token;
  char	*tkn_value;

 i = 0;
  valid_size = 0;
  while (!valid_size && terminal->components + i)
    {
      valid_size = terminal->components[i].check(exp);
      i += 1;
    }
  if (valid_size && (new_token = bousti_malloc(sizeof(t_bousti_token))))
    {
      new_token->associated = terminal->components[i];
      tkn_value = malloc(valid_size);
      if (tkn_value)
	{
	  tkn_value[0] = 0;
	  tkn_value = strncat(tkn_value, exp, valid_size);
	  new_token->value = (const char *)tkn_value;
	}
      bousti_stack_append(stack, new_token);
    }
  return (valid_size);
}
