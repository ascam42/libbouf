/*
** bouf.h for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 16:44:51 2016 Luca Ungaro
** Last update Fri May 20 18:09:48 2016 Luca Ungaro
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
void			*bousti_malloc(size_t			size);
void			*bousti_realloc(void			*pre,
					size_t			size);
void			*bousti_calloc(size_t			nmemb,
				       size_t			size);
void			*bousti_unique_malloc(void		*owner,
					      size_t		size);
void			*bousti_unique_realloc(void		*owner,
					       void		*ptr,
					       size_t		size);
void			*bousti_unique_calloc(void		*owner,
					      size_t		nmemb,
					      size_t		size);
size_t			bousti_get_allocated_size(void		*addr);
size_t			bousti_get_total_allocated_size(void);
void			bousti_free(void			*ptr);
void			bousti_garbage_collect(void);

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

#  define unique_malloc		bousti_unique_malloc
#  define unique_realloc	bousti_unique_realloc
#  define unique_calloc		bousti_unique_calloc
#  define unique_free		bousti_unique_free

# endif /* !BOUSTI_ALLOCATOR_OVERLOAD */

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** | BOUSTI_ALLOCATOR_ABORT :                                                  |
** |      Exit when an allocation fails (with a nice and clean error message)  |
** |                                                                           |
** | Assign true to one of g_bousti_allocator_abort or g_bousti_allocator_warn |
** | depending on what your heart desires. By default, both are set to false   |
** |                                                                           |
** | Note : g_bousti_allocator_[...] are ALREADY defined in libbouf !          |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#  define BOUSTI_ALLOC_ERROR	-42
#  define BOUSTI_ALLOC_ERROR_MSG "Allocation failed : no space left on device."

extern bool		g_bousti_allocator_abort;
extern bool		g_bousti_allocator_warn;

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
					 ...);
char			*bousti_stralloc_not_repeat(int		str_nb,
						    ...);

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . THE BOUSTI_LEXER. . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
**
** +---------------------------------------------------------------------------+
** |                                                                           |
** | The BOUSTI_LEXER is a generic syntax lexer. It returns a stack of tokens  |
** | corresponding to the expresion splityted according to the syntax passed   |
** | as parameter.                                                             |
** |                                                                           |
** | Note: if the syntax passed as parameter is invalid (contains multiple     |
** |       possibilities for some cases...), tokenisation's behavior is        |
** |       undefined.                                                          |
** |                                                                           |
** |                                                                           |
** | Here is how you shall use the parser :                                    |
** |                                                                           |
** | The syntax used by the bousti_lexer is defined as an array of             |
** | t_bousti_syntax. An element is a "rule" of your syntax. Its name goes in  |
** | the 'name' field. If it's a terminal rule, terminal shall be true. If it  |
** | is false, the parser consider components as a rule. The components are an |
** | an array of t_bousti_rule.                                                |
** |                                                                           |
** | A t_bousti_rule contains an expression (its name, when it's a RULE or its |
** | ID if it's a TERMINAL). The type describes its usage. Note that it cannot |
** | be both RULE and TERMINAL. Finally, check is a pointer to a function that |
** | valides the synax of a terminal rule. It shall take a pointer to the      |
** | beggining of the terminal to check and shall return the number of         |
** | validated bytes (0 or more, but never less !)                             |
** | The t_bousti_check_epx functions are yours to implement, so they can      |
** | check the validity of your terminal expressions.                          |
** |                                                                           |
** |                                                                           |
** | bousti_lexer returns a stack of t_bousti_token. This stack is equivalent  |
** | to a t_bousti_list. If it is NULL, a lexing error occured. In case it's   |
** | due to an unexpected token, the bousti_lexer will send an appropriate     |
** | error message to the g_bousti_errlog function.                            |
** |                                                                           |
** | The value contains the... content of the token (i.e. a segment of the     |
** | expression lexed by bousti_lexer) and 'associated' points to the          |
** | NON TERMINAL rule IMMEDIATLY ABOVE the terminal validated.                |
** |                                                                           |
** |                                                                           |
** | IMPORTANT NOTE : the base rule passed as parameter to bousti_lexer CANNOT |
** |                  be a terminal. If it is, it will be ignored and the      |
** |                  expression won't be lexed correctly                      |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
# define BOUSTI_NB_COMPONENTS_MAX	5

typedef int			(*t_bousti_check_exp)(const char	*exp);

typedef enum			e_bousti_token_type
{
  NONE = 0,
  RULE = 2,
  TERMINAL = 4,
  ONE_OR_MORE = 8,
  ZERO_OR_MORE = 16,
  ZERO_OR_ONE = 24
}				t_bousti_token_type;

typedef struct			s_bousti_rule
{
  const char			*exp;
  t_bousti_token_type		type;
  t_bousti_check_exp		check;
}				t_bousti_rule;

typedef struct			s_bousti_syntax
{
  const char			*name;
  bool				terminal;
  t_bousti_rule			components[BOUSTI_NB_COMPONENTS_MAX + 1];
}				t_bousti_syntax;

typedef struct			s_bousti_token
{
  const char			*value;
  t_bousti_rule			associated;
}				t_bousti_token;

typedef t_bousti_list		t_bousti_token_stack;

/*
** Err-logger
*/
# define BOUSTI_SYNTAX_ERR		"Syntax error near unexpected token: "

typedef void			(*t_bousti_errlog)(const char		*msg);

extern t_bousti_errlog		g_bousti_errlog;

t_bousti_token_stack	*bousti_lexer(const t_bousti_syntax	*syntax,
				      const char		*expr,
				      const char		*base_rule_name);

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . BOUSTI_MISCANELLOUS . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
**
** +---------------------------------------------------------------------------+
** |                                                                           |
** | this is just a stack using t_bousti_list                                  |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
void			bousti_stack_append(t_bousti_list	**stack,
					    void		*elem);
t_bousti_list		*bousti_concat_stack(t_bousti_list	*stack,
					     t_bousti_list	*append);
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
