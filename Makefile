##
## Makefile for lib_make in /home/ungaro_l/rendu/Piscine_C_J10
## 
## Made by Luca Ungaro
## Login   <ungaro_l@epitech.net>
## 
## Started on  Fri Oct  9 09:04:28 2015 Luca Ungaro
## Last update Tue Apr 12 21:04:31 2016 Luca Ungaro
##

##
## +---------------------------------------------------------------------------+
## |                                                                           |
## | Boustifaille corp's library overload                                      |
## |                                                                           |
## | This file and all the other ones with it are under BeerWare license       |
## | (revision 42) :                                                           |
## |                                                                           |
## |   | <luca.ungaro@epitech.eu> wrote this file. As long as you retain this  |
## |   | notice you can do whatever you want with this stuff. If we meet some  |
## |   | day and you think this stuff is worth it, you can buy me a beer in    |
## |   | return.                                                               |
## |   |                                                                       |
## |   | Luca Ungaro, for Boustifaille Corp.                                   |
## |                                                                           |
## +---------------------------------------------------------------------------+
##

AR	= ar rc
RANLIB	= ranlib
CC	= gcc

RM	= rm -f
CP	= cp -u -r --parent

ECHO	= echo -e "\t"

DEFAULT	= "\033[00m"
GREEN	= "\033[0;32m"
TEAL	= "\033[1;36m"
RED	= "\033[0;31m"

NAME	= libbouf.a

SRCS	= srcs/list/bousti_free_list.c \
	  srcs/list/bousti_last_elem.c \
	  srcs/list/bousti_put_in_list.c \
	  srcs/list/bousti_put_in_circ.c \
	  srcs/list/bousti_show_list.c \
	  srcs/bousti_alloc.c \
	  srcs/bousti_alloc_get.c \
	  srcs/bousti_stack.c \
	  srcs/bousti_free.c \
	  srcs/bousti_stralloc.c

INCDEST	= ../

HEAD	= include/bouf.h \
	include/boustifaille/hidden_bouf.h \
	include/boustifaille/list.h \

OBJS	= $(SRCS:.c=.o)

override CFLAGS	+= -Iinclude

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS) && \
	$(RANLIB) $(NAME) && \
	$(CP) $(HEAD) $(INCDEST) && \
	$(ECHO) "\n" [ $(GREEN)BOUSTIFAILLE : OK$(DEFAULT) ] "\n" || \
	$(ECHO) "\n" [ $(RED)BOUSTIFAILLE : KO$(DEFAULT) ] "\n"

.c.o:
	@$(CC) -c $< -o $@ $(CFLAGS) && \
	$(ECHO) [ $(GREEN)OK$(DEFAULT) ] $(CC) $< || \
	$(ECHO) [ $(RED)KO$(DEFAULT) ] $(CC) $<

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME) && \
	$(ECHO) "\n" [ $(GREEN)BOUSTIFAILLE : CLEAN$(DEFAULT) ] "\n" || \
	$(ECHO) "\n" [ $(RED)BOUSTIFAILLE : DIRTY$(DEFAULT) ] "\n"

re:	fclean all

.PHONY:	all clean fclean re
