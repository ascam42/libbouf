/*
** hash.h for  in /home/aitoua_s/prog/psu/PSU_2015_42sh/boustifaille
** 
** Made by samy ait-ouakli
** Login   <aitoua_s@epitech.net>
** 
** Started on  Tue May 24 13:53:30 2016 samy ait-ouakli
** Last update Fri Jun  3 14:59:27 2016 samy ait-ouakli
*/

#ifndef HASH_H_
# define HASH_H_

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

typedef t_list t_hash;

typedef struct	s_elem
{
  char		*name;
  void		*data;
}		t_elem;

#define SIZE 50

/*
** Initialise hashtable
*/
int	init_hash();

/*
** Initialise a new element, data of the HT
*/
t_elem	*new_elem(char *name, void *data);

/*
** Put element in HT, return :
** 0 if error
** 1 if the element didn't exist and was put
** 2 if the element exist and was replaced
*/
int	put_in_hash(char *name, void *data);

/*
** Remove elem from HT, return:
** 1 if the element was removed
** 0 if the element wasn't in the HT
*/
int	remove_elem(char *name);

/*
** return the elem stored in the hashtable
*/
void	*get_elem(char *name);
/*
** Hash function homemade
*/
int	my_hash_fct(char const *name);

#endif /* !HASH_H_ */
