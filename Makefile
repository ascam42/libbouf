##
## Makefile for lib_make in /home/ungaro_l/rendu/Piscine_C_J10
## 
## Made by Luca Ungaro
## Login   <ungaro_l@epitech.net>
## 
## Started on  Fri Oct  9 09:04:28 2015 Luca Ungaro
## Last update Fri May 20 12:47:34 2016 Luca Ungaro
##

AR	= ar rc
EXTRACT	= ar x
LIST	= ar t

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
	  srcs/tree/bousti_put_in_tree.c \
	  srcs/tree/bousti_link_in_tree.c \
	  srcs/tree/bousti_free_tree.c \
	  srcs/alloc/bousti_unique_alloc.c \
	  srcs/alloc/bousti_alloc.c \
	  srcs/alloc/bousti_alloc_get.c \
	  srcs/alloc/bousti_alloc_size.c \
	  srcs/alloc/bousti_free.c \
	  srcs/alloc/bousti_garbage_collect.c \
	  srcs/alloc/bousti_abort.c \
	  srcs/alloc/bousti_stralloc.c \
	  srcs/stack/bousti_private_stack.c \
	  srcs/stack/bousti_stack.c \
	  srcs/lexer/lexer.c \
	  srcs/lexer/get_rule.c \
	  srcs/lexer/bousti_regex.c \


ifdef BOUSTI_ARCHIVE
BOUSTI_ARCHIVE_OBJECTS = $(shell $(LIST) $(BOUSTI_ARCHIVE))
else
BOUSTI_ARCHIVE_OBJECTS =
endif

INCDEST	= ../

HEAD	= include/bouf.h \
	  include/boustifaille/list.h \
	  include/boustifaille/tree.h \
	  include/boustifaille/actual_bouf.h \
	  include/boustifaille/private_bouf.h \
	  include/boustifaille/alloc_guard_bouf.h \

OBJS	= $(SRCS:.c=.o)

CPPFLAGS+= -Iinclude

all:	$(NAME)

$(NAME):	$(OBJS)
ifdef BOUSTI_ARCHIVE
	@$(EXTRACT) $(BOUSTI_ARCHIVE)
endif
	@$(AR) $(NAME) $(OBJS) $(BOUSTI_ARCHIVE_OBJECTS) && \
	$(RANLIB) $(NAME) && \
	$(CP) $(HEAD) $(INCDEST) && \
	$(ECHO) "\n" [ $(GREEN)BOUSTIFAILLE : OK$(DEFAULT) ] "\n" || \
	$(ECHO) "\n" [ $(RED)BOUSTIFAILLE : KO$(DEFAULT) ] "\n"
ifdef BOUSTI_ARCHIVE
	@$(RM) $(BOUSTI_ARCHIVE_OBJECTS)
endif

.c.o:
	@$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS) && \
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
