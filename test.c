
#include "bouf.h"

int		main(int	ac,
		     char	**av)
{
  t_bousti_list	*list;
  void		*toto;

  list = NULL;
  toto = bousti_malloc(500);
  bousti_put_in_end_dblist(&list, toto);
  printf("coucou\n");
  bousti_garbage_collect();
  return (0);
}
