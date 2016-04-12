/*
** bouf.h for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 16:44:51 2016 Luca Ungaro
** Last update Tue Apr 12 21:38:34 2016 Luca Ungaro
*/

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | Boustifaille corp's library overload                                      |
** |                                                                           |
** | This file and all the other ones with it are under BeerWare license       |
** | (revision 42) :                                                           |
** |                                                                           |
** |   | <luca.ungaro@epitech.eu> wrote this file. As long as you retain this  |
** |   | notice you can do whatever you want with this stuff. If we meet some  |
** |   | day and you think this stuff is worth it, you can buy me a beer in    |
** |   | return.                                                               |
** |   |                                                                       |
** |   | Luca Ungaro, for Boustifaille Corp.                                   |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#ifndef HIDDEN_BOUF_H_
# define HIDDEN_BOUF_H_

# ifndef BOUF_H_
#  error	"You shall not include boustifaille/hidden_bouf.h directly."
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

#   include "libmy.h"

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
#   define bousti_atoi		getnbr
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

typedef bool		t_bousti_ok;


/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . LINKED LISTS. . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
**
** +---------------------------------------------------------------------------+
** |                                                                           |
** | you can find their documentation in their own header file                 |
** |                                                                           |
** | Note : they DO NOT use the BOUSTI_ALLOCATOR, even if it has been          |
** | overloaded. But anyway, you can alloc/free datas with bousti_malloc/free  |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#  include "boustifaille/list.h"

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . .  THE BOUSTI_ALLOCATOR . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
**
** +---------------------------------------------------------------------------+
** |                                                                           |
** | BOUSTI_ALLOCATOR_ABORT :                                                  |
** |      Exit when an allocation fails (with a nice and clean error message)  |
** |                                                                           |
** | Note : you shall define this macro when compiling libbouf.a !!! ;)        |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
# ifdef BOUSTI_ALLOCATOR_ABORT

#  define BOUSTI_ALLOC_ERROR	-42
#  define BOUSTI_ALLOC_ERROR_MSG "Allocation failed : no space left on device."

# endif /* !BOUSTI_ALLOCATOR_ABORT */

typedef void			*(*t_sysmalloc)(size_t	size);
typedef void			*(*t_sysrealloc)(void	*ptr,
						 size_t	size);
typedef void			*(*t_syscalloc)(size_t	nmemb,
						size_t	size);
typedef void			(*t_sysfree)(void	*addr);

extern t_sysmalloc		g_std_malloc;
extern t_sysrealloc		g_std_realloc;
extern t_syscalloc		g_std_calloc;
extern t_sysfree		g_std_free;

# define std_malloc		g_std_malloc
# define std_realloc		g_std_realloc
# define std_calloc		g_std_calloc
# define std_free		g_std_free

/*
**
** No, BUNNY_ALLOCATOR has nothing to do with it... :p
*/
# ifdef BOUSTI_ALLOCATOR_OVERLOAD

#  define malloc		bousti_malloc
#  define realloc		bousti_realloc
#  define calloc		bousti_calloc
#  define free			bousti_free

# endif /* !BOUSTI_ALLOCATOR_OVERLOAD */

typedef struct		s_bousti_alloc
{
  void			*addr;
  size_t		size;
}			t_bousti_alloc;

extern t_bousti_list	*g_alloc_list;

void		*bousti_malloc(size_t			size);
void		*bousti_realloc(void			*pre,
				size_t			size);
void		*bousti_calloc(size_t			nmemb,
			       size_t			size);
size_t		bousti_get_allocated_size(void		*addr);
size_t		bousti_get_total_allocated_size(void);
void		bousti_free(void			*ptr);
void		bousti_free_everything(void);
/*
**
** Without the Holy Norm, this function would have been static :
*/
t_bousti_alloc	*find_with_address(void		*addr);

/* !!!! Conflit : si on bousti_malloc pour les strings et qu'on les free à la  */
/*                main, puis qu'on leck_check... C'est le zouf ! double-free ! */
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
** +---------------------------------------------------------------------------+
*/
char		*bousti_stralloc(int			str_nb,
				 ...);
char		*bousti_stralloc_not_repeat(int		str_nb,
					    ...);

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | this is just a stack using t_bousti_list                                  |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
void		bousti_stack_append(t_bousti_list	**stack,
				    void		*elem);
/*
**
** Note : bousti_stack_pop
**    --> 'elem' parameter can be either addr of a node or of a node's ->data
*/
void		bousti_stack_pop(t_bousti_list		**stack,
				 void			*elem);
t_bousti_list	*bousti_stack_get_by_data(t_bousti_list	*list,
					  void		*data);

# endif /* !defined(BOUSTI_LIBMY) && defined(BOUSTI_LIBC) */

#endif /* !HIDDEN_BOUF_H_ */
