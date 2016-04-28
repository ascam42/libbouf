/*
** bousti_private.h for bouf in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Thu Apr 28 13:45:43 2016 Luca Ungaro
** Last update Thu Apr 28 20:09:21 2016 Luca Ungaro
*/

#ifndef PRIVATE_BOUF_H_
# define PRIVATE_BOUF_H_

# if !defined(BOUF_H_) || !defined(ACTUAL_BOUF_H_)
#  error	"You shall not include boustifaille/private_bouf.h directly."
#  warning	"Source : BOUF_H_ or ACTUAL_BOUF_H_ undefined"

# else /* BOUF_H_ && ACTUAL_BOUF_H_ */

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . PRIVATE STACK . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
*/
typedef struct			s_bousti_private_stack
{
  void				*data;
  struct s_bousti_private_stack	*prev;
  struct s_bousti_private_stack	*next;
}				t_bousti_private_stack;

typedef t_bousti_private_stack	t_b_pv_stack;

int	bousti_private_stack_push(t_b_pv_stack			**stack,
				  void				*data);
int	bousti_private_stack_append(t_b_pv_stack		**stack,
				    void			*data);
void	bousti_private_stack_pop(t_b_pv_stack			**stack,
				 void				*elem);
void	bousti_free_private_stack(t_b_pv_stack			*stack);

/*
** -----------------------------------------------------------------------------
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** . . . . . . . . . . . . . .  THE BOUSTI_ALLOCATOR . . . . . . . . . . . . . .
** . . . . . . . . . . . . . . (or its hidden part...) . . . . . . . . . . . . .
** . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
** -----------------------------------------------------------------------------
*/
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
** CLASSIC allocation
*/
typedef struct			s_bousti_alloc
{
  void				*addr;
  size_t			size;
}				t_bousti_alloc;

extern t_bousti_private_stack	*g_alloc_list;

/*
**
** UNIQUE allocation (ever dreamed of std::unique_ptr ?)
*/
typedef struct			s_bousti_unique_alloc
{
  void				*owner;
  void				*addr;
  size_t			size;
}				t_bousti_unique_alloc;

extern t_bousti_private_stack	*g_unique_alloc_list;

/*
**
** Without the Holy Norm, this function would have been static :
*/
t_bousti_alloc		*find_with_address(void		*addr);
t_bousti_unique_alloc	*find_unique_with_address(void	*addr);
t_bousti_unique_alloc	*find_unique_with_owner(void	*addr);
void			bousti_abort(void);

# endif /* !(BOUF_H_ && ACTUAL_BOUF_H_) */

#endif /*!PRIVATE_BOUF_H_ */
