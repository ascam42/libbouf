/*
** bouf.h for boustifaille in /home/ungaro_l/mylibs/boustifaille
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Tue Apr 12 16:44:51 2016 Luca Ungaro
** Last update Tue Apr 12 18:09:41 2016 Luca Ungaro
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
#ifndef BOUF_H_
# define BOUF_H_

# ifndef BOUSTI_LIBMY
#  define BOUSTI_LIBC

# endif /* BOUSTI_LIBMY */

# if defined(BOUSTI_LIBMY) && defined(BOUSTI_LIBC)
#  error	"Cannot use both libmy and libc. Choose one."
#  warning	"Source : BOUSTI_LIBMY && BOUSTI_LIBC both defined"

# else /* defined(BOUSTI_LIBMY) XOR defined(BOUSTI_LIBC) */

#  if !defined(BOUSTI_LIBMY) && !defined(BOUSTI_LIBC)
#   error	"This should not happend ! (If it does, I'm sorry for you)"
#   warning	"Source : BOUSTI_LIBMY && BOUSTI_LIBC both undefined"

#  else /* defined(BOUSTI_LIBMY) XOR defined(BOUSTI_LIBC) */

/*
** +---------------------------------------------------------------------------+
** |                                                                           |
** |  What a guard, wasn't it ?                                                |
** |                                                                           |
** +---------------------------------------------------------------------------+
*/
#   include "boustifaille/hidden_bouf.h"

#  endif /* !(defined(BOUSTI_LIBMY) && defined(BOUSTI_LIBC)) */

# endif /* !(!defined(BOUSTI_LIBMY) && !defined(BOUSTI_LIBC)) */

#endif /* !BOUF_H_ */
