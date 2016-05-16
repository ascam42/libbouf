/*
** bouf.h for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 16:44:51 2016 Luca Ungaro
** Last update Mon May 16 18:14:14 2016 Luca Ungaro
*/

#ifndef ACTUAL_BOUF_H_
# define ACTUAL_BOUF_H_

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . .  ____                  _   _  __      _ _ _       . . . . . . .
** . . . . . . . |  _ \                | | (_)/ _|    (_) | |      . . . . . . .
** . . . . . . . | |_) | ___  _   _ ___| |_ _| |_ __ _ _| | | ___  . . . . . . .
** . . . . . . . |  _ < / _ \| | | / __| __| |  _/ _` | | | |/ _ \ . . . . . . .
** . . . . . . . | |_) | (_) | |_| \__ \ |_| | || (_| | | | |  __/ . . . . . . .
** . . . . . . . |____/ \___/ \__,_|___/\__|_|_| \__,_|_|_|_|\___| . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
*/
# ifndef BOUF_H_
#  error	"You shall not include boustifaille/actual_bouf.h directly."
#  warning	"Source : BOUF_H_ undefined"

# else /* BOUF_H_ */

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** |  --> Using libmy                                                          |
** | (compilation shall be done with -lmy and libmy.h in -I PATH)              |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#  if defined(BOUSTI_LIBMY)

#   include BOUSTI_LIBMY

#   define bousti_putchar	my_putchar
#   define bousti_printf	my_printf
#   define bousti_fdprintf	my_fdprintf
#   define bousti_dprintf	my_fdprintf
#   define bousti_atoi		my_getnbr
#   define bousti_strlen	my_strlen
#   define bousti_strcmp	my_strcmp
#   define bousti_strncmp	my_strncmp
#   define bousti_strcat	my_strcat
#   define bousti_strncat	my_strncat
#   define bousti_strlcat	my_strlcat
#   define bousti_strcpy	my_strcpy
#   define bousti_strncpy	my_strncpy
#   define bousti_strstr	my_strstr
#   define bousti_strdup	my_strdup

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** |  --> Using libc                                                           |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#  elif defined(BOUSTI_LIBC)

#   include <string.h>
#   include <stdio.h>

#   define bousti_putchar	putchar
#   define bousti_printf	printf
#   define bousti_fdprintf	dprintf
#   define bousti_dprintf	dprintf
#   define bousti_atoi		atoi
#   define bousti_strlen	strlen
#   define bousti_strcmp	strcmp
#   define bousti_strncmp	strncmp
#   define bousti_strcat	strcat
#   define bousti_strncat	strncat
#   define bousti_strlcat	strlcat
#   define bousti_strcpy	strcpy
#   define bousti_strncpy	strncpy
#   define bousti_strstr	strstr
#   define bousti_strdup	strdup

#  endif /* !(!defined(BOUSTI_LIBMY) || defined(BOUSTI_LIBC)) */

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . .  REAL STUFF STARTS HERE . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
*/
#  include <stdlib.h>
#  include <stdbool.h>
#  include <stdarg.h>
#  include <unistd.h>

#  define STDIN			STDIN_FILENO
#  define STDOUT		STDOUT_FILENO
#  define STDERR		STDERR_FILENO

#  define _STRINGIFY(str)	#str
#  define STRINGIFY(macro)	_STRINGIFY(macro)

typedef bool			t_bousti_ok;

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . LINKED LISTS. . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
**
** +---------------------------------------------------------------------------+
** |                                                                           |
** | You can find their documentation in their own header file                 |
** |                                                                           |
** | Note : they DO use the BOUSTI_ALLOCATOR (whether it's overloaded or not)  |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#  include "boustifaille/list.h"

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . TREES . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
**
** +---------------------------------------------------------------------------+
** |                                                                           |
** | You can find their documentation in their own header file                 |
** |                                                                           |
** | Note : they DO use the BOUSTI_ALLOCATOR (whether it's overloaded or not)  |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#  include "boustifaille/tree.h"

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . .  THE BOUSTI_ALLOCATOR . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
**
** +---------------------------------------------------------------------------+
** |                                                                           |
** | The BOUSTI_ALLOCATOR overloads system's malloc and :                      |
** |     - Stores size allocated at each address (and makes it accessible)     |
** |     - Can exit program on error (if BOUSTI_ALLOCATOR_ABORT is defined)    |
** |     - Can free everything allocated in one function call                  |
** |                                                                           |
** | bousti_[...]alloc() : works exactly like system's [...]alloc()            |
** | bousti_get_allocated_size() : returns the size allocated at an address    |
** | bousti_get_total_allocated_size() : returns the total allocated size      |
** | bousti_free() : works exactly like system's free()                        |
** | bousti_garbage_collect() : frees all allocated blocks, plus internal      |
** |                            stack. Is called as a destructor so everything |
** |                            is freed at exit.                              |
** |                                                                           |
** | Note : it goes without saying that bousti_get[...]size() and              |
** |        bousti_free[...] supposes your allocation has been made with       |
** |        bousti_[...]alloc();                                               |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
void			*bousti_malloc(size_t			size)
  __attribute__((malloc, alloc_size(1)));
void			*bousti_realloc(void			*pre,
					size_t			size)
  __attribute__((alloc_size(2)));
void			*bousti_calloc(size_t			nmemb,
				       size_t			size)
  __attribute__((malloc, alloc_size(1, 2)));
void			*bousti_unique_malloc(void		*owner,
					      size_t		size)
  __attribute__((malloc, alloc_size(2)));
void			*bousti_unique_realloc(void		*owner,
					       void		*ptr,
					       size_t		size)
  __attribute__((alloc_size(3)));
void			*bousti_unique_calloc(void		*owner,
					      size_t		nmemb,
					      size_t		size)
  __attribute__((malloc, alloc_size(2, 3)));
size_t			bousti_get_allocated_size(void		*addr);
size_t			bousti_get_total_allocated_size(void);
void			bousti_free(void			*ptr);
void			bousti_garbage_collect(void)
  __attribute__((destructor));

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | BOUSTI_ALLOCATOR_OVERLOAD :                                               |
** |      If you don't want to type bousti_malloc every 2 lines                |
** |                                                                           |
** | Note : if you want to use system allocation functions, use std_[...]alloc |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
# ifdef BOUSTI_ALLOCATOR_OVERLOAD

#  define malloc		bousti_malloc
#  define realloc		bousti_realloc
#  define calloc		bousti_calloc
#  define free			bousti_free

# endif /* !BOUSTI_ALLOCATOR_OVERLOAD */

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | BOUSTI_ALLOCATOR_ABORT :                                                  |
** |      Exit when an allocation fails (with a nice and clean error message)  |
** |                                                                           |
** | Note : you shall define this macro when compiling libbouf.a !!! ;)        |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
# if defined (BOUSTI_ALLOCATOR_ABORT) || defined(BOUSTI_ALLOCATOR_WARN)

#  define BOUSTI_ALLOC_ERROR	-42
#  define BOUSTI_ALLOC_ERROR_MSG "Allocation failed : no space left on device."

# endif /* !(BOUSTI_ALLOCATOR_ABORT && BOUSTI_ALLOCATOR_WARN) */

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | stralloc fonctions are designed to concatenate strings                    |
** |                                                                           |
** | example : ret = my_stralloc(3, "/tmp", "/", "foobar");                    |
** |           ret's value is now "/tmp/foobar"                                |
** |                                                                           |
** | Note : they DO use the BOUSTI_ALLOCATOR (whether it's overloaded or not)  |
** |                                                                           |
** | Warn : considering bousti_stralloc[...] uses bousti_malloc, i'ts really   |
** |        MORE THAN RECOMMANDED to free them with bousti_free AND to call    |
** |        bousti_garbage_collect() at least at the end of your program       |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
char			*bousti_stralloc(int			str_nb,
					 ...)
  __attribute__((malloc));
char			*bousti_stralloc_not_repeat(int		str_nb,
						    ...)
  __attribute__((malloc));

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | this is just a stack using t_bousti_list                                  |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
void			bousti_stack_append(t_bousti_list	**stack,
					    void		*elem);
/*
**
** Note : bousti_stack_pop
**    --> 'elem' parameter can be either addr of a node or of a node's ->data
*/
void			bousti_stack_pop(t_bousti_list		**stack,
					 void			*elem);
t_bousti_list		*bousti_stack_get_by_data(t_bousti_list	*list,
						  void		*data);

# endif /* !BOUF_H_ */

#endif /* !ACTUAL_BOUF_H_ */
