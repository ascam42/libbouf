/*
** bousti_last_elem.c for libmy in /home/ungaro_l/rendu/C_prog_elem/CPE_2015_Pushswap
** 
** Made by Luca Ungaro
** Login   <ungaro_l@epitech.net>
** 
** Started on  Wed Nov  4 13:19:28 2015 Luca Ungaro
** Last update Tue Apr 12 20:38:10 2016 Luca Ungaro
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
#include "bouf.h"

t_list		*bousti_last_elem(t_list *list)
{
  t_list	*ret;

  if (list)
    {
      while (list->next)
	list = list->next;
      ret = list;
    }
  return (ret);
}

t_list		*bousti_get_root(t_list *list)
{
  t_list	*ret;

  if (list)
    {
      while (list->next && list->data)
	list = list->next;
      ret = list;
    }
  return (ret);
}
