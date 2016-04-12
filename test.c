

#include "bouf.h"

int	main(int ac, char **av)
{
  void	*tmp;

  tmp = bousti_malloc(500);
  bousti_printf("Allocated %i bytes at %p\n",
		bousti_get_allocated_size(tmp), tmp);
  bousti_free_everything();
  return (0);
}
