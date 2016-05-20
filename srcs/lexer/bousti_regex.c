/*
** bousti_regex.c for boustifaille in /home/ungaro_l/mylibs/boustifaille/srcs/lexer
** Made by Luca Ungaro
** 
** Login   <ungaro_l@epitech.net>
** 
** Started on  Fri May 20 11:41:56 2016 Luca Ungaro
** Last update Fri May 20 12:09:15 2016 Luca Ungaro
*/

#include "bouf.h"

/*
** Checks all the possible terminal expressions in of a syntax rule.
** Uses the t_bousti_check_exp function pointer assiciated with each possible
** expression
**
** Retruns the number of characters that have been validated as a part of this
** terminal rule
*/
int	_check_regex_and_go_forward(const t_bousti_syntax	*terminal,
				    const char			*exp)
{
  int	i;
  int	valid;

  i = 0;
  valid = 0;
  while (!valid && terminal->components + i)
    {
      valid = terminal->components[i].check(exp);
      i += 1;
    }
  return (valid);
}
