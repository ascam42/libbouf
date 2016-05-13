#include "bouf.h"
#include "boustifaille/private_bouf.h"

int	main(void)
{
  void	*ptr;


  bousti_free(bousti_stralloc(3, "toto", "titit", "tata"));
  ptr = g_std_malloc(42);
  bousti_free(ptr);
  bousti_garbage_collect();
  return (0);
}
